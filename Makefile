all: hello

hello:
	g++ main.cpp course.cpp day.cpp interface.cpp interface.h course.h day.h
dbg:
	g++ -g main.cpp course.cpp day.cpp interface.cpp interface.h course.h day.h
	gdb a.out
