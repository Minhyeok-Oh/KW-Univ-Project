#include <iostream>

using namespace std;
int CalcLength(const char* str) // calculating length of string
{
	int len;
	for (len = 0; str[len] != '\0'; len++);
	return len;
}

int main()
{
	int i;
	char str[128];
	cout << "Enter the string : ";
	cin.getline(str, 128); // input string

	for (int i = 0; i < CalcLength(str); i++) {
		if (str[i] >= 65 && str[i] <= 90) // converting upper to lower 
			str[i] = str[i] + 32;
		else if (str[i] >= 97 && str[i] <= 122) // converting lower to upper
			str[i] = str[i] - 32;
		else
			continue;
	}

	int temp = 0;
	for (int i = 0; i < CalcLength(str) / 2; i++) { // reverse
		temp = str[i];
		str[i] = str[CalcLength(str) - i - 1];
		str[CalcLength(str) - i - 1] = temp;
	}

	cout << "Result: " << str << endl;

	return 0;
}