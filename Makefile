run: build
	./game 2> gamelog.txt

debug: build
	./game

	
clean:
	rm game

build: main.cpp TicTac.h
	g++ -o game main.cpp

	
