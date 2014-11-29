#include <iostream>
#include "TicTac.h"

using namespace std;

int main(){

	Board game('T','J');

	do{
		game.printBoard();
		game.playerTurn();
	}while(!game.checkWin());

	return 0;
}

