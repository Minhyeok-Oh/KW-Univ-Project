#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Assignment2-5.h" // include head file
using namespace std;

int main() {
	
	//initialize
	char name[4][100] = {'\0', }; 
	char address[4][100]={ '\0', };
	int registration_number[4]= { 0, };
	int phone_number[4]={ 0, };
	// initialize //
	for (int i = 0; i < 4; ++i) { 
		memset(name[i], 0, sizeof(char)*100);
		memset(address[i], 0, sizeof(char)*100);
	}

	//memset(registration_number, 0, sizeof(int) * 4);
	//memset(phone_number, 0, sizeof(int) * 4);
	for (int i = 0; i < 4; i++) { // input 4 member information
		
		cout << "Name: ";
		cin.getline(name[i], 100);
		cout << "Address: ";
		cin.getline(address[i], 100);		
		cout << "Registration Number: ";
		cin >> registration_number[i];
		if (!cin) {
			cout << "error" << endl; // exception handling
			return 0;
		}
		cout << "Phone Number: ";
		cin >> phone_number[i];
		if (!cin) {
			cout << "error" << endl; // exception handling
			return 0;
		}
		cout << endl;
		getchar();
	}

	PatientInfo People[4]; // declare class array
	for (int i = 0; i < 4; i++) {
		People[i].PatientInfo::PatientInfo(name[i], address[i], registration_number[i], phone_number[i]);		
	}
	// print result //
	cout << "<<<<<< Information Of Class Member >>>>>>>" << endl;
	for (int i = 0; i < 4; i++) {
		cout << People[i].PatientInfo::getName() << endl;
		cout << People[i].PatientInfo::getAddress() << endl;
		cout << People[i].PatientInfo::get_R_Number() << endl;
		cout << People[i].PatientInfo::get_P_Number() << endl << endl;
	}	
	return 0;

}