run: build
	./tic-tac-toe 2> gamelog.txt

debug: build
	./tic-tac-toe

	
clean:
	rm game

build: main.cpp TicTac.h
	g++ -o tic-tac-toe main.cpp

	
