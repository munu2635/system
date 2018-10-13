CC=gcc
CFLAGES= -g -Wall
OBJS=4-1.o
TARGET=4-1

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
