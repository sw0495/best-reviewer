CC = g++
CFLAGS = -c -g
LDFLAGS =  
OBJECTS = sample1_unittest.o sample1.o

run: all
	./program

all: program

program : $(OBJECTS)
	$(CC)  $(LDFLAGS) -o program $(OBJECTS) -lgtest

main.o : sample1_unittest.cc
	$(CC) $(CFLAGS) sample1_unittest.cc 

hello.o : sample1.cc
	$(CC) $(CFLAGS) sample1.cc