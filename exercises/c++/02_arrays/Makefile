CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++17

SRC = 01_reverse_order.cc    \
	02_isprime.cc          \
	03_erasieve.cc         \
	04_isprime_stdvector.cc         \
	05_erasieve_stdvector.cc

EXE = $(SRC:.cc=.x)

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .cc .x

all: $(EXE)

.PHONY: all

%.x: %.cc
	$(CXX) $< -o $@ $(CXXFLAGS)

format: $(SRC)
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this command"

.PHONY: format

clean:
	rm -f $(EXE) *~

.PHONY: clean
