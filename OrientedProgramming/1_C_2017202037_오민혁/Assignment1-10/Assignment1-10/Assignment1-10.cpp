#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int random[4] = { 0, }; // declare random array and initializing
	srand((unsigned int)time(NULL)); // for making random number

	for (int i = 0; i < 4; i++) { // input random number to random array
		random[i] = rand() % 10;
		for (int j = 0; j < i; j++) { // duplication checking
			if (random[i] == random[j]) {
				i--;
				break;
			}
		}
	}
	int num;
	cout << "Random numbers: " << endl;

	int n = 0;
	int HIT = 0, BLOW = 0;
	while (n < 10) { // game times < 10
		HIT = 0; BLOW = 0;
		n++; // add game times
		cout << "Your number: "; // input number
		cin >> num;

		if ((num >= 1000 && num < 10000) == 0) { // exception handling
			cout << "invalid input" << endl;
			n--;
			continue;
		}

		int yourNum[4] = { 0, }; // yourNum array initializing
		for (int i = 0; i < 4; i++) { // for 1 number input per 1 array
			yourNum[i] = num % 10;
			num = num - num % 10;
			num /= 10;
		}

		int check = 0;
		for (int i = 0; i < 4; i++) { // duplication checking
			for (int j = 0; j < i; j++) {
				if (yourNum[i] == yourNum[j])
					check = 1;
			}
		}
		if (check == 1) { // exception handling
			cout << "invalid input" << endl;
			n--;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (random[i] == yourNum[j]) { // hit & blow checking
					if (i == j)
						HIT++;
					else
						BLOW++;
				}
				else
					continue;
			}
		}

		cout << ">>HIT: " << HIT << "," << "BLOW: " << BLOW << endl;
		if (HIT == 4) {
			cout << "Win" << endl;
			return 0;
		}
		if (n == 10) {
			cout << "Lose" << endl; // output print
			return 0;
		}

	}

}