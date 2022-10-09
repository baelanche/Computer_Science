CC = gcc
OBJS = main.o
TARGET = hw1_201923678.exe

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	rm -f *.o
	rm -f $(TARGET)

main.o: main.h main.c
