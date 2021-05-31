#pragma once
#include <iostream>

using namespace std;

class Pharmacist {
private:
	int mask_count;
	int price;
public:
	Pharmacist() { mask_count = 5; price = 1000; } // constructor
	~Pharmacist() { mask_count=0; price = 0; } // destructor

	int getmask_count(){ // get mask count
		return mask_count;
	}
	int getprice() { // get mask price
		return price;
	}
	void setmask_count(int mask_count) { // set mask count
		Pharmacist::mask_count = mask_count;
	}
	void setprice(int price) { // set mask price
		Pharmacist::price = price;
	}
};