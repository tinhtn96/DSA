PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

OBJS =  main.o graph.o
CPPFLAGS = -Wall -g -std=c++11
CXX=g++

main:$(OBJS)
	$(CXX) -o $@ $^
	@echo "Makefile is done !!!!!!!!!!!"
	@echo $(PROJECT_ROOT)
	@echo "============================"

clean:
	rm -rf *.o core *.core main

%.o:(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<