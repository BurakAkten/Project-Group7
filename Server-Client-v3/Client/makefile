GPP = g++
CC = gcc
OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

DEPENDENCIES = uici.o uiciname.o restart.o Client.o Networkable.o MatConverter.o
SRCS = main.cpp 
PROG = exe
STD11 = -std=c++11


all: main

main: $(DEPENDENCIES)
	$(GPP) $(SRCS) -o $(PROG) $(DEPENDENCIES) $(LIBS) $(STD11)

Client.o: Client.cpp Client.h
	$(GPP) -c Client.cpp  $(STD11)

Networkable.o: Networkable.cpp Networkable.h
	$(GPP) -c Networkable.cpp $(STD11)	

MatConverter.o: MatConverter.cpp MatConverter.h
	$(GPP) -c MatConverter.cpp $(STD11)

uici.o: supporting/uici.c supporting/uici.h
	$(CC) -c supporting/uici.c 

uiciname.o: supporting/uiciname.c supporting/uiciname.h
	$(CC) -c supporting/uiciname.c 

restart.o: supporting/restart.c supporting/restart.h
	$(CC) -c supporting/restart.c 

clean:
	 rm *.o exe