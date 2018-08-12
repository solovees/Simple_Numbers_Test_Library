QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_simple_numbers.cpp \
    ../../Lab3_library/lab3_prost/lab3_prost.cpp

