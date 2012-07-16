#-------------------------------------------------
#
# Author Prof1983 <prof1983@ya.ru>
# Created 15.06.2012
# LastMod 16.07.2012
#
#-------------------------------------------------

QT -= core gui

TARGET = AiKernel
TEMPLATE = lib

INCLUDEPATH += Include
INCLUDEPATH += ../At/Include

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

HEADERS += A.h \
	Include/AOwl \
	Include/AOwlOntology \
	Include/AOwlTypes \
    Include/AiKernel

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
