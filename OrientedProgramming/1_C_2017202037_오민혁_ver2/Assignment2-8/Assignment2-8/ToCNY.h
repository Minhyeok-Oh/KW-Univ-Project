#pragma once
#include <iostream>
#include "Exchange.h"
using namespace std;
class ToCNY : public Exchange{ // class inheritance
private:
	
public:
	ToCNY(char* country, float price) :Exchange(country, price) // constructor
	{
		float tmp = 0;
		if (!strcmp(country, "USD")) {
			tmp = price * (float)(1200.0/170.0);
			cout << round(tmp) << " CNY" << endl;
		}
		else if (!strcmp(country, "JPY")) {
			tmp = price * (float)(11.0/170.0);
			cout << round(tmp) << " CNY" << endl;
		}
		else if (!strcmp(country, "EUR")) {
			tmp = price * (float)(1300.0/170.0);
			cout << round(tmp) << " CNY" << endl;
		}
		else if (!strcmp(country, "KRW")) {
			tmp = price * (float)(1.0/170.0);
			cout << round(tmp) << " CNY" << endl;
		}
		else if (!strcmp(country, "CNY")) {
			tmp = tmp;
			cout << round(tmp) << " CNY" << endl;
		}
		else {
			cout << "Input error" << endl;
		}
	}
	~ToCNY() {}
};