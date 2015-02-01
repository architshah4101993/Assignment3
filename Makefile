all:
	astyle main.cpp
	g++ -pg main.cpp -o main
	./main
	gprof main gmon.out > analysis.txt
