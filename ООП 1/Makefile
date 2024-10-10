CC = g++
CFLAGS = -Wall -g

TARGET = oop

SRCS = Ship.cpp ShipManager.cpp Playfield.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJS)