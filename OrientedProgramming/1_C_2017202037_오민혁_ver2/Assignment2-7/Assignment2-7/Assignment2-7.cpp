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
		cout << " 0. ���α׷� ����" << endl;
		cout << " 1. ����ũ ��� �����" << endl;
		cout << " 2. ����ũ ���� �����" << endl;
		cout << " 3. ����ũ �����ϱ�" << endl;
		cout << " 4. �� ����ũ ���� Ȯ���ϱ�" << endl;
		cout << " 5. �� ���� Ȯ���ϱ�" << endl;
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
			cout << "�� ����ũ ����: " << buyer.Getmask_number() << "��" << endl << endl;
		}
		else if (num == 5) { // my money
			cout << "�� �ܾ�: " << buyer.Getmoney() << "��" << endl << endl;
		}

	}
}