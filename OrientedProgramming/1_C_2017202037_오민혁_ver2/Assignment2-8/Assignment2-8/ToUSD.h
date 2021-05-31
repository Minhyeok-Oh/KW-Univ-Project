#pragma once
#include <iostream>
#include "Exchange.h"
using namespace std;
class ToUSD : public Exchange { // class inheritance
private:

public:
	ToUSD(char * country, float price) :Exchange(country,price) // constructor
	{
		float tmp = 0;
		if (!strcmp(country, "CNY")) {
			tmp = price * (float)(170.0 / 1200.0);
			cout << round(tmp) << " USD" << endl;
		}
		else if (!strcmp(country, "JPY")) {
			tmp = price * (float)(11.0 / 1200.0);
			cout << round(tmp) << " USD" << endl;
		}
		else if (!strcmp(country, "EUR")) {
			tmp = price * (float)(1300.0 / 1200.0);
			cout << round(tmp) << " USD" << endl;
		}
		else if (!strcmp(country, "KRW")) {
			tmp = price * (float)(1.0 / 1200.0);
			cout << round(tmp) << " USD" << endl;
		}
		else if (!strcmp(country, "USD")) {
			tmp = tmp;
			cout << round(tmp) << " USD" << endl;
		}
		else {
			cout << "Input error" << endl;
		}
	}
	~ToUSD() {}
};