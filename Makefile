CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = cgpa_calculator
SRC = src/main.cpp src/cgpa.cpp
INC = -Iinclude

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(INC) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)