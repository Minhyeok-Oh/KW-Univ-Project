#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
	srand((unsigned int)time(NULL)); // for rand()

	int row, column;
	int Matrix[100][100];
	memset(Matrix, 0, sizeof(Matrix)); // initializing Matrix
	cout << "Enter the row : "; // input
	cin >> row;
	cout << "Enter the column : ";
	cin >> column;

	
	int* check = new int[row * column]; // duplication checking table

	memset(check, 0, sizeof(check)); // initializing

	if ((row >= 1 && row <= 100 && column >= 1 && column <= 100) == 0) {
		cout << "error";
		return 0;
	}
	
	for (int i = 0; i < row; i++) { // input random number to Matrix
		for (int j = 0; j < column; j++) {
			Matrix[i][j] = rand() % (row*column);
			if (check[Matrix[i][j]] == 1) { // check duplication
				j--;
				continue;
			}
			else
				check[Matrix[i][j]] = 1;			
		}
	}	

	cout << "Origin Matrix >>>" << endl << endl;
	for (int i = 0; i < row; i++) { // print original matrix
		for (int j = 0; j < column; j++) {
			cout << setw(5) << Matrix[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Transpose Matrix >>>" << endl << endl; // print transpose matrix
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			cout << setw(5) << Matrix[j][i] << "  ";
		}
		cout << endl;
	}

	return 0;
}