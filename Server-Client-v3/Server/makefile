GPP = g++
CC = gcc
OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

DEPENDENCIES = uici.o uiciname.o restart.o Server.o Networkable.o MatConverter.o Motor.o Recognation.o Detected.o
SRCS = main.cpp 
PROG = exe
STD11 = -std=c++11
WIRING = -lwiringPi


all: main

main: $(DEPENDENCIES)
	$(GPP) $(SRCS) -o $(PROG) $(DEPENDENCIES) $(LIBS) $(STD11) $(WIRING)

Server.o: Server.cpp Server.h Data.h Command.h
	$(GPP) -c Server.cpp  $(STD11)

Motor.o: motor/Motor.cpp motor/Motor.h motor/MotorException.h
	$(GPP) -c motor/Motor.cpp  $(STD11)

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

Detected.o: image/Detected.cpp image/Detected.h
	$(CC) -c image/Detected.cpp $(STD11)

Recognation.o: image/Recognation.cpp image/Recognation.h
	$(CC) -c image/Recognation.cpp $(STD11)

clean:
	 rm *.o exe