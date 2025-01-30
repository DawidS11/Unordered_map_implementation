CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20

SRC = main.cpp UnorderedMap.cpp
HEADERS = UnorderedMap.hpp

OBJ = $(SRC:.cpp=.o)

EXEC = program

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

rebuild: clean all

.PHONY: all clean rebuild