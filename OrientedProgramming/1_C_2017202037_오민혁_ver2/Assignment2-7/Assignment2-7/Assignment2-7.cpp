#include <iostream>
#include "Buyer.h"
#include "Pharmacist.h"

using namespace std;

int main() 
{
	Buyer buyer; // declare buyer
	Pharmacist pharmacist; // declare pharmacist
	buyer.Setpharmacist(pharmacist); // inner class
	int num = 2341;
	while (num != 0) {
		cout << " 0. 프로그램 종료" << endl;
		cout << " 1. 마스크 재고 물어보기" << endl;
		cout << " 2. 마스크 가격 물어보기" << endl;
		cout << " 3. 마스크 구매하기" << endl;
		cout << " 4. 내 마스크 갯수 확인하기" << endl;
		cout << " 5. 내 지갑 확인하기" << endl;
		cin >> num;
		
		if (num == 1) {
			buyer.Getmask_count(); // ask mask stock
		}
		else if (num == 2) {
			buyer.Getmask_price(); // ask mask price
		}
		else if (num == 3) { // buy mask
			
			if (buyer.buymask() == 1) // exception handling
				continue;
			
		}
		else if (num == 4) { // the number of mask
			cout << "내 마스크 갯수: " << buyer.Getmask_number() << "개" << endl << endl;
		}
		else if (num == 5) { // my money
			cout << "내 잔액: " << buyer.Getmoney() << "원" << endl << endl;
		}

	}
}