#pragma once
//#pragma once for some reason...

//use standard definitions
using namespace std;

/*
Space Object:

Each "Space" of a "Board" is either empty, Player One or Player 2
and would have a corresponding symbol
*/
class Space {

	public:
	
		Space(int newPlayer, char newSymbol){

			player = newPlayer;

			symbol = newSymbol;
		};

		int player;

		char symbol;

};

/*
Board Object:

A tic-tac-toe "Board" is a 3x3 array of "Spaces".
*/
class Board {

	public:

		//Player Symbols
		char p1Char, p2Char;

		//Current Player
		int currPlayer;

		//Array of Spaces
		Space* board[3][3];

		//Default symbols are 'X' and 'O', of course...
		Board(char newP1Char = 'X', char newP2Char = 'O'){

			//Start with Player 1
			currPlayer = 1;

			//Set the Player Symbols
			p1Char = newP1Char;
			p2Char = newP2Char;

			//Fill the Board with empty Spaces
			for(int r = 0; r < 3; r++)
				for(int c = 0; c < 3; c++)
					board[r][c] = new Space(0,'-');
		};

		//Print the Boards current state
		void printBoard(){

			// Print the top 
			cout << "X|1|2|3|" << endl;

			// Loop thru the array of spaces and print each symbol
			// Also print line number and seperators where neccessary
			for(int r = 0; r < 3; r++){
				cout << r + 1;
				for(int c = 0; c < 3; c++){
					cout << '|' << board[r][c]->symbol;
				}
				cout << '|' << endl;				
			}
		};

		// Initiate the current players turn
		void playerTurn(){

			// The players input
			// Will be 2 digit number with the first being the row
			// and the second being the column
			// e.g. 22 -> will be 2,2
			int input = 0;

			// Some vars to use
			int row = 0;
			int col = 0;

			bool validMove = false;

			int moveCount = 0;

			do{
				// Print the board
				cout << "Player " << currPlayer << "'s Turn" << endl;			
				printBoard();

				//Add a move count
				moveCount++;

				//Start without being able to move
				validMove = false;

				// If Player has tried more than 10 times let them have it...
				if(moveCount > 10){
					cout << "Fuck it, you can there asshole!" << endl;
					validMove = true;
				}

				// Prompt for input
				cout << "Enter Row, then Column then press Enter: ";
				cin >> input;

				// Break it down
				row = (input/10) - 1; 
				col = (input%10) - 1;

				// Check for valid input
				if(row <= 2 && row >= 0)
					if(col <= 2 && col >= 0)
						if(board[row][col]->player == 0)
							validMove = true;
						else
							cout << "That's not how Tic-Tac-Toe works dipshit\nTry again." << endl;
					else
						cout << "That's not a valid column asshole, quit tryin to break shit.\nTry again." << endl;
				else
					cout << "That shit ain't right nigga\nTry again." << endl;

			// Until it's valid input
			}while(!validMove);

			// Set the Space to the appropriate symbol
			if(currPlayer == 1)
				board[row][col] = new Space(1, p1Char);
			else
				board[row][col] = new Space(2, p2Char);

			//Print log to stderr
			cerr << "Player " << currPlayer << " moved at " << row+1 << ',' << col+1 << endl;

			// Switch players
			if(currPlayer == 1)
				currPlayer = 2;
			else
				currPlayer = 1;
			
		};

		// Check if someone has won
		bool checkWin(){

			/*Wow this is bad...

			I'm really sad about this...I mean it works...but...
			...
			.....
			......

			It's just not good.

			It checks each row, then column, then diagonal
			to see if there are 3 consecutive spaces of either Player.
			*/
			for(int i = 0; i < 8; i++){
				switch(i){
					//Check Rows
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

};
