#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class ThreeSixNine {
private:
	int num;
public:
	ThreeSixNine() { num = 0; } // constructor
	~ThreeSixNine() { num = 0; } // destructor

	void print369(int num) {
		cout.setf(ios::left);
		for (int i = 1; i <= num; i++) {
			int tmp = 0; // for separate
			int count = 0; // 3,6,9 count
			int temp = i; // temp variable
			
			while (temp != 0) {
				tmp = temp % 10; // separate one by one
				
				if (tmp % 3 == 0 && tmp != 0) // distinguish including 3,6,9
					count++;
				temp /= 10;
			}
			if (count != 0) {
				cout.width(10);
				if (count == 1)
					cout << "!";
				else 
					cout << "!!";
												
				if (i % 10 == 0)
					cout << endl;				
			}
			else {
				if (i % 10 == 0) {
					cout.width(10);
					cout  << i << endl;
				}
				else {
					cout.width(10);
					cout << i;
				}
			}
			
		}
	}
};