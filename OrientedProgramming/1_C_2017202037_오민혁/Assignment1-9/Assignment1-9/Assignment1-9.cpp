#include <iostream>

using namespace std;

int main()
{
	char type;
	int text;
	int call;

	int etext = 0, ecall = 0, total = 0;
	while (1) { // infinite loop
		cout << "Which type: "; // input
		cin >> type;
		cout << "Text: ";
		cin >> text;
		cout << "CALL: ";
		cin >> call;

		if (type == 'A') { // A type
			if (text > 100) {
				etext = (text - 100) * 20;
			}

			if (call > 60) {
				ecall = (call - 60) * 180;
			}

			total = 10000 + etext + ecall;
			break;
		}
		else if (type == 'B') { // B type
			if (text > 150) {
				etext = (text - 150) * 15;
			}

			if (call > 90) {
				ecall = (call - 90) * 150;
			}

			total = 15000 + etext + ecall;
			break;
		}
		else if (type == 'C') { // C type
			if (text > 200) {
				etext = (text - 200) * 10;
			}

			if (call > 120) {
				ecall = (call - 120) * 60;
			}

			total = 20000 + etext + ecall;
			break;
		}
		else if (type == 'D') { // D type
			if (text > 250) {
				etext = (text - 250) * 5;
			}

			if (call > 150) {
				ecall = (call - 150) * 30;
			}

			total = 25000 + etext + ecall;
			break;
		}
		else { // exception handling
			cout << "==================" << endl;
			cout << "invalid input" << endl;
			cout << "==================" << endl;
			continue;
		}
	} // print result
	cout << "==================" << endl;
	cout << "Result" << endl;
	cout << "Extra text: " << etext << endl;
	cout << "Extra call: " << ecall << endl;
	cout << "Total: " << total << endl;

}