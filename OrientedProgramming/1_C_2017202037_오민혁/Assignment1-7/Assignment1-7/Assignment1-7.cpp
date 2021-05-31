#include <iostream>
using namespace std;

int main() {

	int x1, y1, x2, y2, x3, y3;

	cout << "P1: ";
	cin >> x1 >> y1; // input
	cout << "P2: ";
	cin >> x2 >> y2;
	cout << "P3: ";
	cin >> x3 >> y3;

	int result = x1 * y2 + x2 * y3 + x3 * y1; // equation of finding triangle area
	result = result - y1 * x2 - y2 * x3 - y3 * x1;

	if (result > 0)
		cout << "Counter-clockwise" << endl; // counter-clockwise
	else if (result < 0)
		cout << "Clockwise" << endl; // clockwise
	else
		cout << "Straight" << endl; // straight

	return 0;
}