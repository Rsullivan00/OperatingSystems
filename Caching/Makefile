CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -std=c++11

SRCS=Page.cpp secondChance.cpp lru.cpp lfu.cpp random.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: secondChance lru lfu random

secondChance: Page.o secondChance.o 
	$(CXX) $(CPPFLAGS) Page.cpp secondChance.cpp -o secondChance

lru: Page.o lru.o 
	$(CXX) $(CPPFLAGS) Page.cpp lru.cpp -o lru 

lfu: Page.o lfu.o 
	$(CXX) $(CPPFLAGS) Page.cpp lfu.cpp -o lfu 

random: Page.o lfu.o 
	$(CXX) $(CPPFLAGS) Page.cpp random.cpp -o random 

secondChance.o: Page.h secondChance.cpp

lru.o: Page.h lru.cpp

lfu.o: Page.h lfu.cpp

random.o: Page.h random.cpp

Page.o: Page.h

clean:
	$(RM) $(OBJS) *.exe
