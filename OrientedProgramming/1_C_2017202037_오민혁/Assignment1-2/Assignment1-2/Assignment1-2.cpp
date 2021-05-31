#include <iostream>

using namespace std;

bool* arr; // declare array

void Prime(int n) { // function of finding prime number
	arr = new bool[n + 1];

	if (n <= 1)
		return;


	for (int i = 2; i <= n; i++)
		arr[i] = true;

	for (int i = 2; i * i <= n; i++) {
		if (arr[i])
			for (int j = i * i; j <= n; j += i)
				arr[j] = false;
	}
}

int main()
{
	int n, count = 0;
	cout << "Enter the n:"; // input
	cin >> n;
	if (n < 2) { // exception handling
		cout << "error";
		return 0;
	}
	Prime(n); // call function

	for (int i = 2; i < n + 1; i++) { //repeat
		if (arr[i]) {
			cout << i << " ";
			count++; // the number of prime number
		}
	}

	cout << endl << endl << "The number of Prime numbers:" << count << endl;
	return 0;
}