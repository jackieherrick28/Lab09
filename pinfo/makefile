CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = pinfo

$(TARGET): pinfo.o
	$(CC) pinfo.o -o $(TARGET)

pinfo.o: pinfo.c
	$(CC) $(CFLAGS) -c pinfo.c

clean:
	rm -f *.o $(TARGET)