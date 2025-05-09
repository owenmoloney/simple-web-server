CC = g++
CFLAGS = -std=c++17 -lpthread

TARGET = server
OBJS = main.o

# Default rule (when you type `make`)
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Rule to compile .cpp to .o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
