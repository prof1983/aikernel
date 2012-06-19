#-------------------------------------------------
#
# Project created by QtCreator 2012-06-15T08:31:31
#
#-------------------------------------------------

QT       -= core gui

TARGET = AiKernel
TEMPLATE = lib

INCLUDEPATH += ../At/Base

DEFINES += AIKERNEL_LIBRARY

SOURCES += \
    AOwl.c \
    AOwlNode.c \
    AiKernelMain.c \
    AOwlNodeSet.c \
    AOwlObject.c \
    AOwlReasoner.c \
    Model/AOwlOntology.c \
    Model/AOwlOntology_Imported.c \
    Model/AOwlOntology_References.c \
    Model/AOwlOntology_Access.c \
    Model/AOwlOntology_Retrive.c \
    Model/AOwlOntology_Axioms.c \
    Model/AOwlOntology_Annotation.c \
    Model/AOwlOntology_Axioms2.c \
    Model/AOwlOntology_Classes.c \
    Model/AOwlOntology_ObjectProp.c \
    Model/AOwlOntology_DataProp.c \
    Model/AOwlOntology_Individuals.c \
    AiKernel.c

HEADERS += AiKernel.h\
    Model/AOwlOntology.h \
    AOwlTypes.h \
    AOwl.h \
    A.h
#    ../At/Base/ABase2.h \
#    ../At/Base/ABase.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEEACD274
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = AiKernel.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}