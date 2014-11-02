CC=g++
CFLAGS=-c -Wall  
CFLAGSOPT=-O3
CFLAGTEST=-DTEST_RUN
LC=g++
RM=rm -f
LCFLAGS=-pthread
SOURCES= ./src/fibonacci.cpp
OBJECTS= ./obj/fibonacci.o
OBJTEST=./obj/fibonacci_test.o
OBJDIR=./obj/
BINARY=./fibonacci
INCLUDE=-I../gtest-1.7.0/include
LIBSPATH=./obj/gtest-all.o
GTESTSRC=../gtest-1.7.0/src/gtest-all.cc
GTESTOBJ=./obj/gtest-all.o
GTSRCINC=-I../gtest-1.7.0/

.PHONY: all

all: build

build:$(OBJDIR) $(OBJECTS) $(GTESTOBJ)
	 $(LC) $(LCFLAGS) $(LIBSPATH) $(OBJECTS) -o $(BINARY) 

$(OBJDIR):
	mkdir obj
	
$(OBJECTS):
	$(CC) $(CFLAGS) $(CFLAGSOPT) $(INCLUDE) $(SOURCES) -o $(OBJECTS)
	
$(GTESTOBJ):
	$(CC) $(CFLAGS) $(GTSRCINC) $(INCLUDE) $(GTESTSRC) -o $(GTESTOBJ)
	
tests: $(OBJTEST) $(GTESTOBJ)
	$(LC) $(LCFLAGS) $(LIBSPATH) $(OBJTEST) -o $(BINARY)
	
$(OBJTEST):
	$(CC) $(CFLAGS) $(CFLAGTEST) $(INCLUDE) $(SOURCES) -o $(OBJTEST)
	
clean:
	$(RM) $(OBJECTS) $(OBJTEST) $(BINARY)

cleanAll:
	$(RM) $(OBJECTS) $(OBJTEST) $(BINARY) $(GTESTOBJ)
