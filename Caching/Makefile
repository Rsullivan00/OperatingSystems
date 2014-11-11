CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

SRCS=Page.cpp secondChance.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: secondChance Page

secondChance: $(OBJS)
	$(CXX) $(LDFLAGS) -o secondChance $(OBJS) $(LDLIBS) 

secondChance.o: secondChance.cpp Page.cpp

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) secondChance 
