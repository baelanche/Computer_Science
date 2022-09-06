CC = gcc
CFLAGS = -g -Wall -lpthread
OBJS = dgrep.o
TARGET = dgrep

$(TARGET): $(OBJS)
        $(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
        rm -f *.o
        rm -f $(TARGET)

dgrep.o: dgrep.c
