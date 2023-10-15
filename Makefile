CXX = g++
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests
BIN_DIR = bin
LIB = lib
INC = -I include
CXXFLAGS=-g -Wall -std=c++14
LDFLAGS= -shared -fPIC

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

TESTS = $(wildcard $(TEST_DIR)/*.cpp)
TARGETS = $(patsubst $(TEST_DIR)/%.cpp,$(BIN_DIR)/%,$(TESTS))
BREELIB=btreelibrary
all: $(BREELIB) $(TARGETS)

$(BREELIB): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $(LIB)/libBtree.so

$(TARGETS): $(BIN_DIR)/%: $(OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_DIR)/$*.cpp -L$(LIB) -lBtree $(INC) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir build/
	mkdir lib/
	mkdir bin/
	$(CXX) $(INC) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf build/
	rm -rf lib/
	rm -rf bin/
