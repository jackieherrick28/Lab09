CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = info

$(TARGET): info.o
	$(CC) info.o -o $(TARGET)

info.o: info.c
	$(CC) $(CFLAGS) -c info.c

clean:
	rm -f *.o $(TARGET)