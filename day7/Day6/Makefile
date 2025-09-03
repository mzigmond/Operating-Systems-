CC = gcc

all: Day6-1 stackStuff

stackStuff: stack.o main.o
	$(CC) stack.o main.o -o stackTest

Day6-1: Day6-1.c
	$(CC) Day6-1.c -o Day6-1

Day6-2: Day6-2.c
	$(CC) Day6-2.c -o Day6-2
	
clean:
	rm *.o
    
.c.o:
	$(CC) -c $< -o $@
