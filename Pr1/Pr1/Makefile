CC=g++
CXXFLAGS=-g -std=c++17
ODIR=src
BUILD=build

_OBJ=$(BUILD)/Racionales.o $(BUILD)/Racional.o
OBJ=$(patsubst %,%,$(_OBJ))

all: Racionales
$(BUILD)/Racionales.o: $(ODIR)/Racionales.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/Racional.o: $(ODIR)/Racional.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

Racionales: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS) -lm

.PHONY:clean

clean:
	rm -rf build/* Racionales

