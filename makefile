#makefile for sandpile model

#CFLAGS = -O
CC = g++
#SRC=Sand.cpp Sandpile.cpp SOC2.cpp  #SOURCE FILES (.cpp)
#OBJ = $(SRC:.cpp = .o)

SOC: Sand.o Sandpile.o SOC2.o random.o
	$(CC) -o SOC Sand.o Sandpile.o SOC2.o random.o 

random.o: random.cpp
	$(CC) -c random.cpp

Sand.o: Sand.cpp 
	$(CC) -c Sand.cpp

Sandpile.o: Sandpile.cpp
	$(CC) -c Sandpile.cpp

SOC2.o: SOC2.cpp
	$(CC) -c SOC2.cpp 

clean:
	rm -f core *.o

 
