all: hello

hello:
	g++ main.cpp course.cpp day.cpp course.h day.h
valgrind:
	g++ -Wall -ggdb3 main2.cpp Dictionary.cpp Dictionary.h
	valgrind --leak-check=full ./a.out
dbg:
	g++ -g main.cpp course.cpp day.cpp course.h day.h
	gdb a.out
