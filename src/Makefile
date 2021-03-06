CC = clang
RM = rm -f
DFLAG = -g
GFLAGS = -Wall -Wextra
CFLAGS = $(DFLAG) $(GFLAGS) -c
LFLAGS = $(DFLAG) $(GFLAGS)

all: TestStack

TestStack: TestStack.o Stack.o
	$(CC) $(LFLAGS) TestStack.o Stack.o -o TestStack

CalculatorMain: Stack.o Calculator.o CalculatorMain.o
	$(CC) $(LFLAGS) Stack.o Calculator.o CalculatorMain.o -o CalculatorMain


Stack.o: Stack.c Stack.h
	$(CC) $(CFLAGS) Stack.c

TestStack.o: TestStack.c Stack.h myassert.h
	$(CC) $(CFLAGS) TestStack.c

Calculator.o: Calculator.c Calculator.h Stack.h
	$(CC) $(CFLAGS) Calculator.c

CalculatorMain.o: Calculator.c Calculator.h
	$(CC) $(CFLAGS) CalculatorMain.c


clean:
	$(RM) TestStack CalculatorMain *.o
