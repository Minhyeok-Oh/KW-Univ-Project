#define max(x, y) ((x>y)?x:y) // define max function
#include "AVLNode.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>// header file declare
using namespace std;
class AVLTree
{
public:
	AVLNode * root;	// AVLTree Root
	ofstream * flog;

public:
	AVLTree(ofstream * flog);
	~AVLTree();

	AVLNode  *  Getroot();
	void	 	Setroot(AVLNode * AVLNode);
	bool		Insert(CityData * AVLNode);
	AVLNode *	Delete(int num);
	CityData *	Search(int num);
	bool		Print();
	int GetHeight(AVLNode * node) // get height function
	{
		if (node == NULL) return 0;
		return 1 + max(GetHeight(node->GetLeft()), GetHeight(node->GetRight()));
	}
	void RenewmBF(AVLNode * node) // renew all mBF function
	{
		if (node != NULL) {
			node->SetmBF(GetBalance(node));
			RenewmBF(node->GetLeft());
			RenewmBF(node->GetRight());
		}
		return;
	}
	int GetBalance(AVLNode * node) // Get Balance function
	{
		if (node == NULL) return 0;
		return (GetHeight(node->GetLeft()) - GetHeight(node->GetRight()));
	}
	AVLNode * CheckBalance(AVLNode * node) { // balance checking end rotation
		if (node == NULL)
			return NULL;
		int balance = node->GetmBF();
		if (balance > 1 && node->GetLeft()->GetmBF() >= 0) { // LL rotation
			node=RightRotation(node);
		}
		else if (balance > 1 && node->GetLeft()->GetmBF() < 0) { // LR rotation
			node->SetLeft(LeftRotation(node->GetLeft()));
			node=RightRotation(node);
		}
		else if (balance < -1 && node->GetRight()->GetmBF() <= 0) { // RR rotation
			node=LeftRotation(node);
		}
		else if (balance < -1 && node->GetRight()->GetmBF() > 0) { // RL rotation
			node->SetRight(RightRotation(node->GetRight()));
			node=LeftRotation(node);
		}
		
		return node;
	}

	// right rotation
	AVLNode *RightRotation(AVLNode* a)
	{
		AVLNode *b = a->GetLeft();
		a->SetLeft(b->GetRight());
		b->SetRight(a);
		return b;
	}

	// left rotation
	AVLNode *LeftRotation(AVLNode* a)
	{
		AVLNode *b = a->GetRight();
		a->SetRight(b->GetLeft());
		b->SetLeft(a);
		return b;
	}


};

