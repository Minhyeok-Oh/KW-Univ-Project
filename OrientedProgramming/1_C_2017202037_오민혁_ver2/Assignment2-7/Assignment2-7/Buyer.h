#pragma once
#include <iostream>
#include "Pharmacist.h"
using namespace std;

class Buyer {
private:
	Pharmacist Pharma; // inner class
	int mask_number; // mask number
	int money; // money
public:
	Buyer() { mask_number = 0; money = 3000; } // constructor
	~Buyer(){ mask_number = 0; money = 0; } // destructor

	int Getmoney() { // get money
		return money;
	}
	int Getmask_number() { // get my the number of mask
		return mask_number;
	}
	void Setmask_number(int num) { // set mask number
		Buyer::mask_number = num;
	}
	void Setmoney(int num) { // set money
		Buyer::money = num;
	}
	void Setpharmacist(Pharmacist a){ // set pharmacist
		Buyer::Pharma = a;
	}
	void Getmask_count() {
		cout << "���� ����ũ ����: " << Pharma.getmask_count()<<"��" << endl << endl;
	}
	void Getmask_price() {
		cout << "����ũ ����: " << Pharma.getprice() <<"��"<< endl << endl;
	}
	int buymask() { // buy mask
		int num = 0;
		cout << "�� ���� �����Ͻðڽ��ϱ�?" << endl;
		cin >> num;
		if ((Pharma.getmask_count() - num < 0) && (Buyer::money - (num * 1000) < 0)) {// exception handling
			cout << "����ũ ���� �ܾ� ��� �����մϴ�." << endl << endl;
			return 1;
		}
		else if (Buyer::money - (num * 1000) < 0) {// exception handling
			cout << "�ܾ��� �����մϴ�" << endl << endl;
			return 1;
		}
		else if (Pharma.getmask_count() - num < 0) {// exception handling
			cout << "����ũ ��� �����մϴ�." << endl << endl;
			return 1;
		}
		else {

			Pharma.setmask_count(Pharma.getmask_count() - num);
			Setmask_number(Buyer::mask_number + num);
			Setmoney(Buyer::money - (num * 1000));
			cout << num << "���� ���� �Ϸ�." << endl << endl;
			
		}
		return 2;
	}
	
};