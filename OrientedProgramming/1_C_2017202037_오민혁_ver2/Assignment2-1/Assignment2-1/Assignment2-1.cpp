#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>

using namespace std;

int main()
{
	ifstream fin("source.txt"); // source.txt open
	ofstream fout("result.txt"); // result.txt open

	time_t start, end;

	char str[100]; // str array
	char input[100]; // input array
	memset(str, 0, sizeof(str)); // array initialize
	memset(input, 0, sizeof(str)); // array initialize
	float accuracy = 0; 
	float correct = 0; 
	float speed = 0;
	float t = 0;
	if (!fin.is_open()) { // exception handling
		cout << "No file!" << endl;
		return 0;
	}
	
	fout << "KW Typing Verification Program" << endl;
	fout << "정확도 : " << accuracy << "           ";
	fout << "속도(타자/s) : " << speed << endl << endl;

	while (fin.peek()!=EOF) {
		
		correct = 0;
		cout << "KW Typing Verification Program" << endl;
		
		cout << "정확도 : " << accuracy << "           ";
		cout << fixed;
		cout.precision(1);
		cout<<"속도(타자/s) : " << speed << endl;
		
		cout << endl;
		
		fin.getline(str, 100);		
		cout << "문장 : " << str << endl;
		
		cout << "입력 : ";
		start = time(NULL);
		cin.getline(input, 100);
		end = time(NULL);
		t = end - start; // typing time
		cout << input;
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == input[i])
				correct++; // correct accuracy
		}
		float len = (float)strlen(str);
		float leng = (float)strlen(input);
		speed = leng / t;
		accuracy = (correct / leng) * 100;
		fout << str << endl;
		
		fout << "정확도 : " << accuracy << "           ";
		fout << fixed;
		fout.precision(1);
		fout <<"속도(타자/s) : " << speed << endl << endl;
		memset(str, 0, sizeof(str));
		memset(input, 0, sizeof(input));
		system("cls"); // clearance
	}
	cout << "KW Typing Verification Program" << endl;
	cout << "정확도 : " << accuracy << "           " << "속도(타자/s) : " << speed << endl;

	fin.close();
	fout.close();

	return 0;
}