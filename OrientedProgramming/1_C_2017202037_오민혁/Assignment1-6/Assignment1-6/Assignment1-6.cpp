#include <iostream>

using namespace std;

int main()
{
	char Bingo[100][100]; // table
	memset(Bingo, ' ', sizeof(Bingo)); // initializing Bingo array
	int board[3][3] = { 1,2,3,4,5,6,7,8,9 }; // initializing board
	////////////////// draw bingo board ///////////////////
	Bingo[0][1] = 'X';
	Bingo[0][3] = '0';
	Bingo[0][6] = '1';
	Bingo[0][9] = '2';
	Bingo[1][0] = 'Y';
	Bingo[2][0] = '0';
	Bingo[4][0] = '1';
	Bingo[6][0] = '2';
	Bingo[2][1] = '|';
	Bingo[2][4] = '|';
	Bingo[2][7] = '|';
	Bingo[2][10] = '|';
	Bingo[4][1] = '|';
	Bingo[4][4] = '|';
	Bingo[4][7] = '|';
	Bingo[4][10] = '|';
	Bingo[6][1] = '|';
	Bingo[6][4] = '|';
	Bingo[6][7] = '|';
	Bingo[6][10] = '|';
	
	for (int i = 2; i < 13; i++) {
		Bingo[1][i] = '-';
		Bingo[3][i] = '-';
		Bingo[5][i] = '-';
		Bingo[7][i] = '-';
	}
	////////////////////////////////////////////////////////////

	for (int i = 0; i < 11; i++) { // print bingo board
		for (int j = 0; j < 11; j++) {
			cout << Bingo[i][j];
		}
		cout << endl;
	}
	int num = 0, x, y;
	int result = 0;
	int player = 1;
	while (1) {
		num++; // game times counting
		if (num % 2 != 0) // change player
			player = 1;
		else
			player = 2;

		cout << "[Play " << player << "] Enter your location [x y] : ";
		cin >> x >> y; // input
		if (((x >= 0 && x <= 2) == 0) || ((y >= 0 && y <= 2) == 0)) // exception handling
		{
			cout << "error";
			return 0;
		}
		if (Bingo[(y + 1) * 2][(x + 1) * 3 - 1] != ' ') { // exception handling
			cout << "invalid input." << endl;
			num--;
			continue;
		}
		if (player == 1) { // player 1
			Bingo[(y + 1) * 2][(x + 1) * 3 - 1] = 'O';
			board[y][x] = 1;
		}
		else { // player2
			Bingo[(y + 1) * 2][(x + 1) * 3 - 1] = 'X';
			board[y][x] = 2;
		}
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cout << Bingo[i][j];
			}
			cout << endl;
		}

		// diagonal bingo checking
		if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
			(board[2][0] == board[1][1] && board[2][0] == board[0][2])) {
			result = 1;
		}
		//horizontal, vertical bingo checking
		for (int i = 0; i <= 2; i++) {
			if ((board[i][0] == board[i][1] && board[i][0] == board[i][2])
				|| (board[0][i] == board[1][i] && board[0][i] == board[2][i])) {

				result = 1;
			}
		}

		if (result == 1) {
			if (player == 1) {
				cout << "winner is [Player 1]" << endl; // result print
				return 0;
			}
			else {
				cout << "winner is [Player 2]" << endl;
				return 0;
			}
		}

		if (num == 9) {
			cout << "draw" << endl; // draw print
			return 0;
		}

	}

}