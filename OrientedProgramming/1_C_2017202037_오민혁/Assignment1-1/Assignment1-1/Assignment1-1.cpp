#include <iostream>

using namespace std;
char** shape; // two-dimension array dynamic allocation
// making square function
void square(int n, int x, int y) {

	if (n == 1)
	{
		shape[x][y] = '$';
		return;
	}

	int d = n / 3; // start position

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) // for center blank
				continue;
			else
				square(d, x + (i * d), y + (j * d));
		}
}

int main()
{
	int n;
	cout << "Enter the power of 3:"; // input
	cin >> n;

	if ((n < 3 || n >= 2287) || (n / 3) % 3 != 0 && n != 3) { // exception handling
		cout << "error";
		return 0;
	}

	shape = new char* [n];
	for (int i = 0; i < n; i++) {
		shape[i] = new char[n]; // make row
		memset(shape[i], 0, sizeof(char) * n); // initializing
	}

	for (int i = 0; i < n; i++) // array initializing
		for (int j = 0; j < n; j++)
			shape[i][j] = ' ';
	square(n, 0, 0); // draw square
	for (int i = 0; i < n; i++) { // print
		for (int j = 0; j < n; j++) {
			cout << shape[i][j];
		}
		cout << endl;
	}
}
