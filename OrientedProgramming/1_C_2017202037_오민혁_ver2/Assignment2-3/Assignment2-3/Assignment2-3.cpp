#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	
	int x, y;

	cout << "Please input 2D array size: ";
	cin >> x >> y;
	
	int **arr = new int* [y]; // 2 dimension array dynamic allocation
	for (int i = 0; i < y; ++i) {
		arr[i] = new int[x];
		memset(arr[i], 0, sizeof(int) * x); // array initialize
	}
	int X=-1, Y=0;
	int num = 1;
	
	int tx = x, ty = y;
	int d = 1;
	while (0<tx*ty) {		
		for (int m = 0; m < tx; m++) { // make row
			X = X + d;
			
			arr[Y][X] = num;
			num++;
		}
		tx--;
		ty--;
		for (int n = 0; n < ty; n++) { // make column
			
			Y = Y + d;
			arr[Y][X] = num;
			num++;
			
		}		
		d = d * (-1); // direction
	}
	
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			
			cout<<setw(4)<<arr[i][j];

		}
		cout << endl;
	}
	return 0;
}