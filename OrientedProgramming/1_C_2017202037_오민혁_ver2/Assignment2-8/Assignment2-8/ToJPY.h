#pragma once
#include <iostream>
#include "Exchange.h"
using namespace std;
class ToJPY : public Exchange { // class inheritance
private:

public:
	ToJPY(char* country, float price) :Exchange(country, price) // constructor
	{
		float tmp = 0;
		if (!strcmp(country, "USD")) {
			tmp = price * (float)(1200.0 / 11.0);
			cout << round(tmp) << " JPY" << endl;
		}
		else if (!strcmp(country, "CNY")) {
			tmp = price * (float)(170.0/11.0);
			cout << round(tmp) << " JPY" << endl;
		}
		else if (!strcmp(country, "EUR")) {
			tmp = price * (float)(1300.0 / 11.0);
			cout << round(tmp) << " JPY" << endl;
		}
		else if (!strcmp(country, "KRW")) {
			tmp = price * (float)(1.0 / 11.0);
			cout << round(tmp) << " JPY" << endl;
		}
		else {
			cout << "Input error" << endl;
		}
	}
	~ToJPY() {}
};