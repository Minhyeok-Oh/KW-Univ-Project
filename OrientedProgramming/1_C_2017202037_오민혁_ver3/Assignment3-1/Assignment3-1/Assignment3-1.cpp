#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h""
#include <cstring>
using namespace std;

int main(void) {

	List list;
	
	int SELNUM = 0;


	while (1) {

		cout << "1. LOAD" << endl;
		cout << "2. PRINT" << endl;
		cout << "3. INSERT" << endl;
		cout << "4. Category SEARCH" << endl;
		cout << "5. Menu SEARCH" << endl;
		cout << "6. DELETE" << endl;
		cout << "7. End of Program!" << endl;
		cout << "Select Number: ";
		cin >> SELNUM;
		if (!cin) {
			cout << "Invalid Input" << endl << endl;
			return 0;
		}
		cout << endl;
		if (SELNUM == 1) { // LOAD
			list.LOAD();
		}
		else if (SELNUM == 2) { // PRINT
			list.PRINT();
			
		}
		else if (SELNUM == 3) { // INSERT
			cout << "Enter Category, Menu and Price: " << endl;

			char buf[100] = { 0, };
			cin.ignore();
			cin.getline(buf, 100);
			int price = 0;
			char* category = strtok(buf, " \t");
			if (category == NULL) {
				cout << "Invalid Input" << endl << endl;
				continue;
			}
			char* menu = strtok(NULL, " \t");
			if (menu == NULL) {
				cout << "Invalid Input" << endl << endl;
				continue;
			}
			char* ptr = strtok(NULL, " \t");
			if (ptr == NULL) {
				cout << "Invalid Input" << endl << endl;
				continue;
			}
			price = atoi(ptr);
			if (price == 0) {
				cout << "Invalid Input" << endl << endl;
				continue;
			}
			if(list.INSERT(category,menu,price))
				cout << "Insert Success!" << endl;
			
		}
		else if (SELNUM == 4) { // Category SEARCH
			char find[100] = { 0, };
			cout << "Enter Category which you want to find :";
			cin >> find;
			
			list.CategorySEARCH(find);
		}
		else if (SELNUM == 5) { // Menu SEARCH
			char find[100] = { 0, };
			cout << "Enter Menu which you want to find :";
			cin >> find;

			list.MenuSEARCH(find);
		}
		else if (SELNUM == 6) { // DELETE
			char find[100] = { 0, };
			cout << "Enter Menu which you want to delete :";
			cin >> find;
			
			list.DELETE(find);
			
		}
		else if (SELNUM == 7) {
			cout << "End of Program!" << endl;
			return 0;
		}
		else {
			cout << "Invalid Input" << endl;
		}
	}



	return 0;
}