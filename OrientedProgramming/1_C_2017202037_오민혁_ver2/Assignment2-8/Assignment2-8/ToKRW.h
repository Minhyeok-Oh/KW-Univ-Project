#pragma once
#include <iostream>
#include "Exchange.h"
using namespace std;
class ToKRW : public Exchange { // class inheritance
private:

public:
	ToKRW(char* country, float price) :Exchange(country,  price) // constructor
	{
		float tmp = 0;
		if (!strcmp(country, "USD")) {
			tmp = price * (float)1200.0;
			cout << round(tmp) << " KRW" << endl;
		}
		else if (!strcmp(country, "JPY")) {
			tmp = price * (float)11.0;
			cout << round(tmp) << " KRW" << endl;
		}
		else if (!strcmp(country, "EUR")) {
			tmp = price * (float)1300.0;
			cout << round(tmp) << " KRW" << endl;
		}
		else if (!strcmp(country, "CNY")) {
			tmp = price * (float)170.0;
			cout << round(tmp) << " KRW" << endl;
		}
		else if (!strcmp(country, "KRW")) {
			tmp = tmp;
			cout << round(tmp) << " KRW" << endl;
		}
		else {
			cout << "Input error" << endl;
		}
	}
	~ToKRW() {}
};