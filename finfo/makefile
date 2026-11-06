CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = finfo

$(TARGET): finfo.o
	$(CC) finfo.o -o $(TARGET)

finfo.o: finfo.c
	$(CC) $(CFLAGS) -c finfo.c

clean:
	rm -f *.o $(TARGET)