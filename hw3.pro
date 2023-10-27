HEADERS   = \
    form.h
SOURCES   = main.cpp \
            form.cpp
QT += sql widgets
requires(qtConfig(combobox))


FORMS += \
    form.ui

DISTFILES += \
    db.sql


