CXX=g++
CXXFLAGS=-c -Wall  
CXXFLAGSOPT=-O3
LD=g++
RM=rm -f
LDFLAGS=-pthread
SOURCES= ./src/fibonacci.cpp
OBJECTS= ./obj/fibonacci.o
BINARY=./fibonacci
CXXFLAGTEST=-DTEST_RUN
OBJTEST=./obj/fibonacci_test.o
OBJDIR=./obj/
LIBSTEST=-lgtest
GTEST_DIR=../gtest-1.7.0

.PHONY: all

all: build

.PHONY: build

build:$(OBJDIR) $(OBJECTS) 
	 $(LD) $(LDFLAGS) $(OBJECTS) $(LIBSPATH)  -o $(BINARY) 

$(OBJDIR):
	mkdir obj
	
$(OBJECTS):
	$(CXX) $(CXXFLAGS) $(CXXFLAGSOPT) $(INCLUDE) $(SOURCES) -o $(OBJECTS)
	
.PHONY: tests

tests: $(OBJTEST)
	$(LD) $(LDFLAGS) $(LIBSTEST) $(OBJTEST) -o $(BINARY)
	
$(OBJTEST):
	$(CXX) $(CXXFLAGS) $(CXXFLAGTEST) $(SOURCES) -o $(OBJTEST)

.PHONY: clean

clean:
	$(RM) $(OBJECTS) $(OBJTEST) $(BINARY)
