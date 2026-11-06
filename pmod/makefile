CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = pmod

$(TARGET): pmod.o
	$(CC) pmod.o -o $(TARGET)

pmod.o: pmod.c
	$(CC) $(CFLAGS) -c pmod.c

clean:
	rm -f *.o $(TARGET)