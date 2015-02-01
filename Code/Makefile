all:
	astyle main.cpp
	g++ -pf main.cpp -o main
	./main
	gprof main gmon.out > analysis.txt
