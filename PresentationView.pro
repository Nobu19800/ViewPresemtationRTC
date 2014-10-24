TEMPLATE = vcapp
TARGET = PresentationView
QT += widgets
QT += testlib

HEADERS	    =   mainwindow.h \
		graphicsview.h \
		ImageDataCom.h \
		PresentationView.h
SOURCES	    =   mainwindow.cpp \
		graphicsview.cpp \
		PresentationView.cpp \
		ImageDataCom.cpp \
		PresentationViewComp.cpp
build_all:!build_pass {
    CONFIG -= build_all
    CONFIG += release
}

# install
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS diagramscene.pro images
INSTALLS += target sources
