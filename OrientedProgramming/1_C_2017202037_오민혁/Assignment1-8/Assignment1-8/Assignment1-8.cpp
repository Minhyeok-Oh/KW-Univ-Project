#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string str;

	ifstream in("ciphertext.txt"); // file open ciphertext.txt
	while (!in.eof()) { 
		getline(in, str); // input string
	}
	in.close(); // file close
	cout << "ciphertext: " << str << endl;
	stringstream ss(str); // stringstream ss

	string token; // string token
	int num = 0;
	char arr[1000] = { 0, };
	while (ss >> token)
	{
		arr[num] = stoi(token, nullptr, 16); // convert hexadecimal to decimal
		if (arr[num] > 127) {
			while (arr[num] < 128)
				arr[num] = arr[num] - 128; // 0 < ASCII CODE < 127
		}
		num++;
	}

	int tmp = 0;
	for (int i = 0; i < 128; i++) { // print ceaser cipher
		cout << "key(" << i << "): ";
		for (int j = 0; j < num; j++) {
			if ((arr[j] + i) < 128)
				cout << (char)(arr[j] + i);
			else {
				tmp = arr[j] + i;
				while (tmp > 127) { // 0 < ASCII CODE < 127
					tmp = tmp - 128;
				}
				cout << (char)tmp;
			}

		}
		cout << endl;
	}

}