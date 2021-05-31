#pragma once
#include <iostream>
#include "Exchange.h"
using namespace std;
class ToEUR : public Exchange {// class inheritance
private:

public:
	ToEUR(char* country, float price) :Exchange(country, price) // constructor
	{
		float tmp = 0;
		if (!strcmp(country, "USD")) {
			tmp = price * (float)(1200.0 / 1300.0);
			cout << round(tmp) << " EUR" << endl;
		}
		else if (!strcmp(country, "JPY")) {
			tmp = price * (float)(11.0 / 1300.0);
			cout << round(tmp) << " EUR" << endl;
		}
		else if (!strcmp(country, "CNY")) {
			tmp = price * (float)(170.0 / 1300.0);
			cout << round(tmp) << " EUR" << endl;
		}
		else if (!strcmp(country, "KRW")) {
			tmp = price * (float)(1.0 / 1300.0);
			cout << round(tmp) << " EUR" << endl;
		}
		else if (!strcmp(country, "EUR")) {
			tmp = tmp;
			cout << round(tmp) << " EUR" << endl;
		}
		else {
			cout << "Input error" << endl;
		}
	}
	~ToEUR() {}
};