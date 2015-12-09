# Makefile for SDL2 based program

#********** COMPILERS ********** #
CC = gcc
CXX = g++

#********** COMPILER FLAGS ********** #
CFLAGS = -Wall

#********** LIBRARIES ********** #
WIN_LIBS = -LC:\libs\SDL2\lib\x86 -lSDL2main -lSDL2 -LC:\libs\SDL2_image\i686-w64-mingw32\lib -lSDL2_image
#MACSDL = -lSDL2
MAC_LIBS = -L/usr/local/lib -lSDL2 -lSDL2_image

#********** INCLUDES ********** #
WIN_INCLUDE =  -IC:\libs\SDL2\include -IC:\libs\SDL2_image\i686-w64-mingw32\include\SDL2

MAC_INCLUDE = -I/usr/local/include/SDL2

#********** SOURCE (.c or .cpp) ********** #
SOURCE = $(wildcard *.c)

# ********** EXECUTABLE NAMES ********** #
WIN_32 =  -o win32_game.exe
MAC_64 = -o darwin64_game

all:
	$(CC) $(CFLAGS) $(SOURCE) $(WIN_INCLUDE) $(WIN_LIBS) $(WIN_32)

mac:
	$(CC) $(CFLAGS) $(SOURCE) $(MAC_INCLUDE) $(MAC_LIBS) $(MAC_64)

clean:
	rm -rf *.exe *.o darwin64_game
