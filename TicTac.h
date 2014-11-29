#pragma once

using namespace std;

class Space {

	public:
	
		Space(int newPlayer, char newSymbol){

			player = newPlayer;

			symbol = newSymbol;


		};


		int player;

		char symbol;

};

class Board {

	public:

		Board(char newP1Char = 'X', char newP2Char = 'O'){

			currPlayer = 1;
			p1Char = newP1Char;
			p2Char = newP2Char;

			for(int r = 0; r < 3; r++)
				for(int c = 0; c < 3; c++)
					board[r][c] = new Space(0,'-');
		};

		void printBoard(){
			for(int r = 0; r < 3; r++){
				for(int c = 0; c < 3; c++){
					cout << '|' << board[r][c]->symbol;
				}
				cout << '|' << endl;				
			}
		};

		void playerTurn(){

			int row = 0;
			int col = 0;

			cout << "Player " << currPlayer << "'s Turn" << endl;

			do{
				cout << "Enter Row: ";
				cin >> row;

				cout << "Enter Col: ";
				cin >> col;

			}while(board[row-1][col-1]->player != 0);

			if(currPlayer == 1)
				board[row-1][col-1] = new Space(1, p1Char);
			else
				board[row-1][col-1] = new Space(2, p2Char);

			cerr << "Player " << currPlayer << " moved at " << row << ',' << col << endl;

			if(currPlayer == 1)
				currPlayer = 2;
			else
				currPlayer = 1;
			
		};

		bool checkWin(){


			for(int i = 0; i < 8; i++){

				switch(i){
					//Check Rows//

					//1
					case 0:
						if(board[0][0] -> symbol == p1Char && board[0][1] -> symbol == p1Char && board[0][2] -> symbol == p1Char){
							printBoard();
							cout << "Player 1 Wins" << endl;
							return true;
						}
						if(board[0][0] -> symbol== p2Char && board[0][1] -> symbol == p2Char && board[0][2] -> symbol == p2Char){
							printBoard();
							cout << "Player 2 Wins" << endl;
							return true;
						}
					break;

					//2
					case 1:
						if(board[1][0] -> symbol == p1Char && board[1][1] -> symbol == p1Char && board[1][2] -> symbol == p1Char){
							printBoard();
							cout << "Player 1 Wins" << endl;
							return true;
						}
						if(board[1][0] -> symbol== p2Char && board[1][1] -> symbol == p2Char && board[1][2] -> symbol == p2Char){
							printBoard();
							cout << "Player 2 Wins" << endl;
							return true;
						}
					break;

					//3
					case 2:
						if(board[2][0] -> symbol == p1Char && board[2][1] -> symbol == p1Char && board[2][2] -> symbol == p1Char){
							printBoard();
							cout << "Player 1 Wins" << endl;
							return true;
						}						
							if(board[2][0] -> symbol== p2Char && board[2][1] -> symbol == p2Char && board[2][2] -> symbol == p2Char){
							printBoard();
							cout << "Player 2 Wins" << endl;
							return true;
						}
					break;
					//**********//


					//Check Columns//

					//1
					case 3:
						if(board[0][0] -> symbol == p1Char && board[1][0] -> symbol == p1Char && board[2][0] -> symbol == p1Char){
							printBoard();
							cout << "Player 1 Wins" << endl;
							return true;
						}
						if(board[0][0] -> symbol== p2Char && board[1][0] -> symbol == p2Char && board[2][0] -> symbol == p2Char){
							printBoard();
							cout << "Player 2 Wins" << endl;
							return true;
						}
					break;

					//2
					case 4:
						if(board[0][1] -> symbol == p1Char && board[1][1] -> symbol == p1Char && board[2][1] -> symbol == p1Char){
							printBoard();
							cout << "Player 1 Wins" << endl;
							return true;
						}
						if(board[0][1] -> symbol== p2Char && board[1][1] -> symbol == p2Char && board[2][1] -> symbol == p2Char){
							printBoard();
							cout << "Player 2 Wins" << endl;
							return true;
						}
					break;

					//3
					case 5:
						if(board[0][2] -> symbol == p1Char && board[1][2] -> symbol == p1Char && board[2][2] -> symbol == p1Char){
							printBoard();
							cout << "Player 1 Wins" << endl;
							return true;
						}
						if(board[0][2] -> symbol== p2Char && board[1][2] -> symbol == p2Char && board[2][2] -> symbol == p2Char){
							printBoard();
							cout << "Player 2 Wins" << endl;
							return true;
						}

					break;
					//*************//
				
					//Check Diagonals//
					case 6:
						if(board[0][0] -> symbol == p1Char && board[1][1] -> symbol == p1Char && board[2][2] -> symbol == p1Char){
							printBoard();
							cout << "Player 1 Wins" << endl;
							return true;
						}
						if(board[0][0] -> symbol== p2Char && board[1][1] -> symbol == p2Char && board[2][2] -> symbol == p2Char){
							printBoard();
							cout << "Player 2 Wins" << endl;
							return true;
						}
					break;

					case 7:
						if(board[0][2] -> symbol == p1Char && board[1][1] -> symbol == p1Char && board[2][0] -> symbol == p1Char){
							printBoard();
							cout << "Player 1 Wins" << endl;
							return true;
						}
						if(board[2][0] -> symbol== p2Char && board[1][1] -> symbol == p2Char && board[2][0] -> symbol == p2Char){
							printBoard();
							cout << "Player 2 Wins" << endl;
							return true;
						}

					break;
					//***************//

				}
			}


			return false;
		};

		char p1Char;

		char p2Char;

		int currPlayer;

		Space* board[3][3];
};
