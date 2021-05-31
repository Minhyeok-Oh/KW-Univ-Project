#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class Exchange {
private:
	char* country; // country
	float price; // price
public:
	Exchange(char * country, float price ) // constructor 
	{ 
		this->country=country; 
		this->price = price;
	}
	~Exchange() {}
	
};