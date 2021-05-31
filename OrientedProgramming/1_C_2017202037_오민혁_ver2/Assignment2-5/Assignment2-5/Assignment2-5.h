#pragma once
#include <iostream>

class PatientInfo
{
private:
	char* name;
	char* address;
	int registration_number;
	int phone_number;

public:
	PatientInfo() { // basic constructor
		name = NULL;
		address = NULL;
		registration_number = 0;
		phone_number = 0;
	}
	~PatientInfo() { // destructor
		name = NULL;
		address = NULL;
		registration_number = 0;
		phone_number = 0;
	}
	PatientInfo(char* name, char* address, int registration_number, int phone_number) // constructor
	{
		PatientInfo::name = name;
		PatientInfo::address = address;
		PatientInfo::registration_number=registration_number;
		PatientInfo::phone_number = phone_number;
		
	}

	char* getName() { return name; } // get Name
	char* getAddress() { return address; } // get Address
	int get_R_Number() { return registration_number; } // get Registration number
	int get_P_Number() { return phone_number; } // get Phone number
};
