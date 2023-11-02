#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>
#include <QSemaphore>

QMutex m;

struct Account {
    int balance{1000};
};

struct AccountSem {
    QSemaphore balance{1000};
};

class TransferMutex : public QThread {
    Account& from;
    Account& to;
    int amount;
    void run() override {
        QMutexLocker lk(&m);
        if(from.balance >= amount) {
            from.balance -= amount;
            QThread::usleep(1);
            to.balance += amount;
        }
    }
public:
     TransferMutex(Account& from, Account& to, int amount, QObject* parent = nullptr) :
     QThread(parent),
     from(from),
     to(to),
     amount(amount)
    {

    }
};

class TransferSem : public QThread {
    AccountSem& from;
    AccountSem& to;
    int amount;
    void run() override {
            from.balance.tryAcquire(amount, 2000);
            QThread::usleep(1);
            to.balance.release(amount);
    }

public:
     TransferSem(AccountSem& from, AccountSem& to, int amount, QObject* parent = nullptr) :
     QThread(parent),
     from(from),
     to(to),
     amount(amount)
    {

    }
};

class TransferSimple : public QThread {
    Account& from;
    Account& to;
    int amount;
    void run() override {
        if(from.balance >= amount) {
            from.balance -= amount;
            QThread::usleep(1);
            to.balance += amount;
        }
    }
public:
    TransferSimple(Account& from, Account& to, int amount, QObject* parent = nullptr) :
     QThread(parent),
     from(from),
     to(to),
     amount(amount)
    {

    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Account acc1;
    Account acc2;

    qDebug() << "Есть два счета с 1000$ - Acc1 и Acc2";
    qDebug() << "Многопоточно переводим 500$ Acc1->Acc2 и 1200$ Acc2->Acc1";


    TransferMutex t1m(acc1, acc2, 500);
    TransferMutex t2m(acc2, acc1, 1200);

    t1m.start();
    t2m.start();

    t1m.wait();
    t2m.wait();

    qDebug() << "Результат с использованием mutex:";
    qDebug() << "Acc1.balance=" << acc1.balance<<"$";
    qDebug() << "Acc2.balance=" << acc2.balance<<"$";

    AccountSem acc1sem;
    AccountSem acc2sem;
    TransferSem t1sem(acc1sem, acc2sem, 500);
    TransferSem t2sem(acc2sem, acc1sem, 1200);

    t1sem.start();
    t2sem.start();

    t1sem.wait();
    t2sem.wait();

    qDebug() << "Результат с использованием семафоров:";
    qDebug() << "Acc1.balance=" << acc1sem.balance.available()<<"$";
    qDebug() << "Acc2.balance=" << acc2sem.balance.available()<<"$";

    Account acc1s;
    Account acc2s;

    TransferSimple t1s(acc1s, acc2s, 500);
    TransferSimple t2s(acc2s, acc1s, 1200);

    t1s.start();
    t2s.start();

    t1s.wait();
    t2s.wait();

    qDebug() << "Результат без использования дополнительных механизмов:";
    qDebug() << "Acc1.balance=" << acc1s.balance<<"$";
    qDebug() << "Acc2.balance=" << acc2s.balance<<"$";


    return a.exec();
}

