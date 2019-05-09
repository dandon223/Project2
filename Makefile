all: hello

hello:
	g++ main.cpp course.cpp day.cpp interface.cpp interface.h course.h day.h
dbg:
	g++ -g main.cpp course.cpp day.cpp interface.cpp interface.h course.h day.h
	gdb a.out
valgrind:
	g++ -Wall -ggdb3 main.cpp course.cpp day.cpp interface.cpp interface.h course.h day.h
	valgrind --leak-check=full ./a.out
