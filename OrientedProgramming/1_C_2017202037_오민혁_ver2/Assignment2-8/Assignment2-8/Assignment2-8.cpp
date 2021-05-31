#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Exchange.h"
#include "ToKRW.h"
#include "ToCNY.h"
#include "ToEUR.h"
#include "ToJPY.h"
#include "ToUSD.h"
using namespace std;

int main() 
{
	
	while (1) {
		char yorn = NULL; // initialize
		char str[100] = { '\0', }; // initialize
		float price = 0; // price
		char convert1[100] = { '\0', }; // first country
		char convert2[100] = { '\0', }; // second country

		cout << "¡ÚCurrency Converter¡Ú" << endl;
		cout << "e.g. [Price] KRW to USD" << endl << endl;
		
		
		cin.getline(str, 100);
		
		char* ptr = NULL;
		ptr=strtok(str, " "); // first string
		
		if (!atof(ptr)) {
			cout << "Input error" << endl;//exception handling
			return 0;
		}
		
		price = atof(ptr);
		
		ptr = strtok(NULL, " "); // second string
		
		if (!ptr) {
			cout << "Input error" << endl;//exception handling
			return 0;
		}
		strcpy(convert1, ptr);
		
		ptr = strtok(NULL, " "); // third string
		if (strcmp(ptr,"to")) {
			cout << "Input error" << endl;//exception handling
			return 0;
		}
		ptr = strtok(NULL, " "); // fourth string
		if (!ptr) {
			cout << "Input error" << endl;//exception handling
			return 0;
		}
		strcpy(convert2, ptr);
		
		Exchange exchange(convert1, price); // declare parent class
		
		if (!strcmp(convert2, "KRW")) {
			ToKRW KRW(convert1, price); // declare child class
		}
		else if (!strcmp(convert2, "USD")) {
			ToUSD USD(convert1, price);// declare child class
		}
		else if (!strcmp(convert2, "JPY")) {
			ToJPY JPY(convert1, price);// declare child class
		}
		else if (!strcmp(convert2, "EUR")) {
			ToEUR EUR(convert1, price);// declare child class
		}
		else if (!strcmp(convert2, "CNY")) {
			ToCNY CNY(convert1, price);// declare child class
		}
		else {
			cout << "Input error" << endl;
		}



		cout << "Would you like to continue? (Y/N)" << endl;
		cin >> yorn; // Yes or No
		cout << endl;
		if (yorn == 'Y' || yorn == 'y') {
			getchar(); // erase buffer
			
			continue;
		}
		else if (yorn == 'N' || yorn == 'n') {
			cout << "Bye!" << endl;
			return 0;
		}
		else {
			cout << "Input error" << endl;
			return 0;
		}
		
			
	}
	
	return 0;
}