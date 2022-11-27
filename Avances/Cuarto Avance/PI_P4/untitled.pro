QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/QLedLabel.cpp \
    src/main.cpp \
    src/widget.cpp

nasm.name = nasm ${QMAKE_FILE_IN}
nasm.input = ASM_FILES
nasm.variable_out = OBJECTS
nasm.commands = nasm -f elf64 ${QMAKE_FILE_IN} -o ${QMAKE_FILE_OUT}
nasm.output = ${QMAKE_VAR_OBJECTS_DIR}${QMAKE_FILE_IN_BASE}$${first(QMAKE_EXT_OBJ)}
nasm.CONFIG += target_predeps

QMAKE_EXTRA_COMPILERS  += nasm

ASM_FILES += \
    src/asm/anticollision_simulation.asm \
    src/asm/gas_simulation.asm \
    src/asm/pressure_simulation.asm \
    src/asm/temperature_simulation.asm \
    src/asm/umbrales.asm

HEADERS += \
    src/QLedLabel.h \
    src/widget.h \
    src/Funciones.h

FORMS += \
    widget.ui
 
QMAKE_LFLAGS += \
    -no-pie
    
QMAKE_VAR_OBJECTS_DIR += \
	build


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
