#include <iostream>
#include "TicTac.h"

using namespace std;

int main(){

	char p1Token = 'X';
	char p2Token = 'O';


	cout << "Enter Player 1's Token: ";
	cin >> p1Token;

	again:
	cout << "Enter Player 2's Token: ";
	cin >> p2Token;

	if(p1Token == p2Token){
		cout << "Nigga, that's player 1's token, what the fuck you tryna do?" << endl;
		goto again;
	}

	Board game(p1Token, p2Token);

	do{
//		game.printBoard();
		game.playerTurn();
	}while(!game.checkWin());

	return 0;
}

