CC = clang
RM = rm -f
DFLAG = -g
GFLAGS = -Wall -Wextra
CFLAGS = $(DFLAG) $(GFLAGS) -c
LFLAGS = $(DFLAG) $(GFLAGS)

all: TestStack

TestStack: TestStack.o Stack.o 
	$(CC) $(LFLAGS) TestStack.o Stack.o -o TestStack


Stack.o: Stack.c Stack.h
	$(CC) $(CFLAGS) Stack.c

TestStack.o: TestStack.c Stack.h myassert.h
	$(CC) $(CFLAGS) TestStack.c


clean:
	$(RM) TestStack *.o
