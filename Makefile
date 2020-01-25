CC=gcc
CFLAG=-pthread
SRC=src
TARGET=maze
RM=rm

maze : $(SRC)
	$(CC) -o $@ $(SRC)/*.c $(CFLAG)

