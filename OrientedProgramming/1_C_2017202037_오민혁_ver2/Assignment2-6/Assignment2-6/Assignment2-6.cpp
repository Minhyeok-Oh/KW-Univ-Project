#include <iostream>
#include "Assignment2-6.h"

using namespace std;

int main() {
	int num;
	ThreeSixNine game;

	cout << "input 369 number" << endl;
	cin >> num;
	if (num < 0 || num>300) {
		cout << "error" << endl;
		return 0;
	}

	game.print369(num); // call public function
	cout << endl;

	return 0;
}