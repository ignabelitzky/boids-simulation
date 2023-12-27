CXX := g++
CXXFLAGS := -std=c++23 -Wall -Werror -Wextra -pedantic -march=native -O2
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system

TARGET := boids

SRC := main.cpp utils.cpp boid.cpp
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(SFML_LIBS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) $(OBJ)
