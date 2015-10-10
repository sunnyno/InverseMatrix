make:
	g++ -pg -o matrix main.cpp
	./matrix
test:
	cxxtestgen --error-printer -o runner.cpp MyTest.h
	g++ -o runner runner.cpp



    
