# ***************************************************************
# File Name:  app.cpp
# Created By: Nick G. Toth
# E-Mail:     ntoth@pdx.edu
# Date:       Aug 9th, 2017
#
# Overview: QMake file for testing the QVertex widget.
#
# ***************************************************************/

TEMPLATE = app
CONFIG += console
TARGET = QVtexTest
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
SOURCES += QVtexTest.cpp QVertex.cpp
