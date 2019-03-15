QT       += core gui widgets

greaterThan(QT_VERSION, 4.7): lessThan(QT_VERSION, 5.0): QT += declarative
greaterThan(QT_MAJOR_VERSION, 4): QT += quick


		 
INCLUDEPATH  += $$PWD \
                $$PWD/zxing

HEADERS +=  $$PWD/zxing/bigint/NumberlikeArray.hh \
    $$PWD/zxing/bigint/BigUnsignedInABase.hh \
    $$PWD/zxing/bigint/BigUnsigned.hh \
    $$PWD/zxing/bigint/BigIntegerUtils.hh \
    $$PWD/zxing/bigint/BigIntegerLibrary.hh \
    $$PWD/zxing/bigint/BigIntegerAlgorithms.hh \
    $$PWD/zxing/bigint/BigInteger.hh

SOURCES += $$PWD/zxing/bigint/BigUnsignedInABase.cc \
    $$PWD/zxing/bigint/BigUnsigned.cc \
    $$PWD/zxing/bigint/BigIntegerUtils.cc \
    $$PWD/zxing/bigint/BigIntegerAlgorithms.cc \
    $$PWD/zxing/bigint/BigInteger.cc


unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }

    DEFINES += NOFMAXL
    INSTALLS += target
}

win32-msvc*{

    INCLUDEPATH += $$PWD/zxing/win32/zxing \
	            $$PWD/zxing/win32/zxing/msvc
    HEADERS += $$PWD/zxing/win32/zxing/msvc/stdint.h \
                $$PWD/zxing/win32/zxing/iconv.h

    SOURCES += $$PWD/zxing/win32/zxing/win_iconv.c
}

win32-g++{

    INCLUDEPATH += $$PWD/zxing/win32/zxing \
					$$PWD/zxing/win32/zxing/msvc
    HEADERS += $$PWD/zxing/win32/zxing/iconv.h

    SOURCES += $$PWD/zxing/win32/zxing/win_iconv.c
}

!win32{
    DEFINES += NO_ICONV
}
winrt {
    DEFINES += NO_ICONV
}
