#include <iostream>
#include "BSTNode.h"
#include "Queue.h"
#include "Tree.h"
using namespace std;


int main(void) 
{
	int num = 0;
	int SELNUM = 0;
	

	
	
	int Size = 0;
	cout << "Enter Input Size : ";
	cin >> Size;

	int temp[100] = { 0, };

	if (!cin || Size <= 0) {
		cout << "Invalid Input" << endl;
		return 0;
	}
	cout << "Enter a number : ";
	for (int i = 0; i < Size; i++) {
		cin >> num;
		if (!cin || Size <= 0) {
			cout << "Invalid Input" << endl;
			continue;
		}
		temp[i] = num;
	}
	cout << endl << endl;
	while (1) {
		////////////////// ***make BST*** ///////////////
		Tree BST;
		int S = Size;
		for (int i = 0; i < Size; i++) { 

			BSTNode* newNode = new BSTNode(temp[i]);
			if(!BST.Insert(newNode))
				S--;
		}
		////////////////////////////////////////////////
		cout << "1. Preorder" << endl;
		cout << "2. Inorder" << endl;
		cout << "3. Postorder" << endl;
		cout << "4. Exit" << endl;
		cout << "Select Number : ";
		cin >> SELNUM;
		
		if (!cin) {
			cout << "Invalid Input" << endl;
			return 0;
		}
		
		if (SELNUM == 1) {
			Queue queue;
			cout << endl << endl;
			
			queue.Pushpreorder(BST.GetRoot());
			
			for (int i = 0; i < S; i++) {
				queue.Pop();
			}
			cout << endl << endl;
		}
		else if (SELNUM == 2) {
			Queue queue;
			cout << endl << endl;

			queue.Pushinorder(BST.GetRoot());

			for (int i = 0; i < S; i++) {
				queue.Pop();
			}
			cout << endl << endl;
		}
		else if (SELNUM == 3) {
			Queue queue;
			cout << endl << endl;

			queue.Pushpostorder(BST.GetRoot());

			for (int i = 0; i < S; i++) {
				queue.Pop();
			}
			cout << endl << endl;
		}
		else if (SELNUM == 4) {
			cout << "End of Program" << endl;
			return 0;
		}
		else {
			cout << "Invalid Input" << endl;
			continue;
		}
	}
}
