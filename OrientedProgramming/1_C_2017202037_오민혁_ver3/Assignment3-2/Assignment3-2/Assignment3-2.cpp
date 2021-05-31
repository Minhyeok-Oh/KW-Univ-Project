#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h"
#include <cstring>
using namespace std;

int main(void)
{
	List list;

	int SELNUM=0;
	cout << "************************************" << endl;
	cout << "S T A R T " << endl;
	cout << "************************************" << endl;

	cout << "1. Insert lecture at beginning" << endl;
	cout << "2. Insert lecture at last" << endl;
	cout << "3. Insert lecture at position" << endl;
	cout << "4. Delete lecture" << endl;
	cout << "5. Update lecture" << endl;
	cout << "6. Search lecture" << endl;
	cout << "7. Search professor" << endl;
	cout << "8. Search grade" << endl;
	cout << "9. Sort by grade In ascennding order" << endl;
	cout << "10. Display lecture list" << endl;
	cout << "11. Reverse lecture list" << endl;
	cout << "12. Exit" << endl;
	while (SELNUM != 12) {
		
		cout << "Input number: ";
		cin >> SELNUM;
		if (!cin) {
			cout << "Invalid Input" << endl << endl;
			return 0;
		}

		if (SELNUM == 1) { // Insert lecture at beginning
			cout << "-----------------------------" << endl;
			char name[100] = { 0, };
			char professor[100] = { 0, };
			int grade = 0;
			cout << "<Insert lecture at beginning>" << endl;
			cout << "->Enter the lecture name: ";
			cin >> name;
			cout << "->Enter the lecture professor: ";
			cin >> professor;
			cout << "->Enter the lecture grade:";
			cin >> grade;
			if (!cin) {
				cout << "Invalid Input." << endl;
				return 0;
			}
			list.InsertAtBeginning(name,professor,grade);
			
			cout << "-----------------------------" << endl;
		}
		else if (SELNUM == 2) { // Insert lecture at last
			cout << "-----------------------------" << endl;
			char name[100] = { 0, };
			char professor[100] = { 0, };
			int grade = 0;
			cout << "<Insert lecture at last>" << endl;
			cout << "->Enter the lecture name: ";
			cin >> name;
			cout << "->Enter the lecture professor: ";
			cin >> professor;
			cout << "->Enter the lecture grade:";
			cin >> grade;
			if (!cin) {
				cout << "Invalid Input." << endl;
				return 0;
			}
			list.InsertAtLast(name, professor, grade);
			cout << "-----------------------------" << endl;
		}
		else if (SELNUM == 3) { // Insert lecture at position
			cout << "-----------------------------" << endl;
			char name[100] = { 0, };
			char professor[100] = { 0, };
			int grade = 0;
			int position = 0;
			cout << "<Insert lecture at position>" << endl;
			cout << "Enter the position of lecture insert: ";
			cin >> position;
			cout << "->Enter the lecture name: ";
			cin >> name;
			cout << "->Enter the lecture professor: ";
			cin >> professor;
			cout << "->Enter the lecture grade:";
			cin >> grade;
			if (!cin) {
				cout << "Invalid Input." << endl;
				return 0;
			}
			list.InsertAtPosition(name, professor, grade, position);
			cout << "-----------------------------" << endl;
		}
		else if (SELNUM == 4) { // Delete lecture
			cout << "-----------------------------" << endl;
			char name[100] = { 0, };
			cout << "<Delete Lecture>" << endl;
			cout << "Enter the lecture of lecture Delete:";
			cin >> name;
			list.DELETE(name);
			cout << "-----------------------------" << endl;
		}
		else if (SELNUM == 5) { // Update lecture
			char name[100] = { 0, };
			cout << "-----------------------------" << endl;
			cout << "<Update lecture>" << endl;
			cout << "->Enter the lecture name:";
			cin >> name;
			
			list.UPDATE(name);

			cout << "-----------------------------" << endl;

		}
		else if (SELNUM == 6) { // Search lecture
			cout << "-----------------------------" << endl;
			cout << "<Search lecture>" << endl;
			cout << "->Enter the lecture name you want to search:";
			char name[100] = { 0, };
			cin >> name;
			list.Searchlecture(name);
			if (!cin) {
				cout << "Invalid Input." << endl;
				return 0;
			}
			cout << "-----------------------------" << endl;

		}
		else if (SELNUM == 7) { // Search professor
			cout << "-----------------------------" << endl;
			cout << "<Search professor>" << endl;
			cout << "->Enter the professor name you want to search:";
			char professor[100] = { 0, };
			cin >> professor;
			list.Searchprofessor(professor);
			cout << "-----------------------------" << endl;

		}
		else if (SELNUM == 8) {
			cout << "-----------------------------" << endl;
			cout << "<Search grade>" << endl;
			cout << "->Enter the lecture name you want to search:";
			int grade;
			cin >> grade;
			if (!cin) {
				cout << "Invalid Input." << endl;
				return 0;
			}
			list.Searchgrade(grade);
			cout << "-----------------------------" << endl;

		}
		else if (SELNUM == 9) {
			cout << "-----------------------------" << endl;
			cout << "<Sort by grade In ascennding order>" << endl;
			list.sorting();
			cout << "-----------------------------" << endl;

		}
		else if (SELNUM == 10) {
			cout << "-----------------------------" << endl;
			cout << "<Display lecture list>" << endl;
			list.PRINT();
			cout << "-----------------------------" << endl;
		}
		else if (SELNUM == 11) {
			cout << "-----------------------------" << endl;
			cout << "<Reverse lecture list>" << endl;
			cout << "**The product list has been reversed**" << endl;
			list.RePrint();
			cout << "-----------------------------" << endl;
		}
		else if (SELNUM == 12) {
			cout << "-----------------------------" << endl;
			
			cout << "Exit" << endl;
			cout << "-----------------------------" << endl;

			return 0;
		}
		else {
			
			if (!cin) {
				cout << "Invalid Input." << endl;
				return 0;
			}
			cout << "Invalid Input." << endl;
		}
	}



}