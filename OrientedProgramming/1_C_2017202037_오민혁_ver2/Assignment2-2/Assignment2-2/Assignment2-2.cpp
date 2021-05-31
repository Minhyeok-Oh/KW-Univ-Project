#include <iostream>
using namespace std;

int main()
{
	int two_d_array[2][3] = { 1,2,3,4,5,6 }; // 2X3 array
	int * a = &two_d_array[0][0]; // a->1
	int * b = &two_d_array[1][0]; // b->4
	int * c = &two_d_array[0][1]; // c->2
	int * d = &two_d_array[0][2]; // d->3
	int ** h = &a; // h->a
	int ** i = &a; // i->a
	int	** j = &c; // j->c
	int * e = two_d_array[0]; // e->row 1
	int * f = two_d_array[1]; // f->row 2
	int (*g)[3] = two_d_array; // g->two_d_array
	
	cout << "First Condition" << endl;
	cout << "a: " << *a << endl;
	cout << "b: " << *b << endl;
	cout << "c: " << *c << endl;
	cout << "d: " << *d << endl;
	cout << "h: " << **h << endl;
	cout << "i: " << **i << endl;
	cout << "j: " << **j << endl;
	
	cout << endl;
	cout << "Second Condition" << endl;
	cout << "1-a: " << a << endl;
	cout << "1-h: " << *h << endl;
	cout << "1-i: " << *i << endl;
	cout << "2-c: " << c << endl;
	cout << "2-j: " << *j << endl;
	cout << "3-d: " << d << endl;
	cout << "4-b: " << b << endl;
	cout << "5-?: " << b+1 << endl;
	cout << "6-?: " << b+2 << endl;
	
	cout << endl;
	cout << "Third Condition" << endl;
	cout << "e: " << *e << endl;
	cout << "f: " << *f << endl;
	cout << "g: " << **g << endl;
	


	
	return 0;
}