all: orderedhtdriver openhtdriver

orderedhtdriver: orderedhttest.cpp ordered.h ordered.cpp
	g++ -std=c++11 -o orderedhtdriver orderedhttest.cpp ordered.cpp

openhtdriver: openhttest.cpp open.h open.cpp
	g++ -std=c++11 -o openhtdriver openhttest.cpp open.cpp

clean:
	rm -f openhtdriver
	rm -f orderedhtdriver
