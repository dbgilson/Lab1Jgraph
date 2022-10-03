all: TestYourStrength

TestYourStrength: TestYourStrength.o
	g++ -pthread -o TestYourStrength TestYourStrength.o

TestYourStrength.o: TestYourStrength.cpp
	g++ -c TestYourStrength.cpp