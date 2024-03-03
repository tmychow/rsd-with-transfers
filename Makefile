CC=g++

engine.o: engine.cpp engine.h
	$(CC) -std=c++11 -c engine.cpp -o engine.o
	$(CC) agent.o rooms.o engine.o -o engine

all : agent.cpp agent.h rooms.cpp rooms.h engine.cpp engine.h
	$(CC) -std=c++11 -c rooms.cpp -o rooms.o
	$(CC) -std=c++11 -c agent.cpp -o agent.o
	$(CC) -std=c++11 -c engine.cpp -o engine.o
	$(CC) agent.o rooms.o engine.o -o engine

clean:
	rm -f *.o
	rm -f engine
	rm -f output/*