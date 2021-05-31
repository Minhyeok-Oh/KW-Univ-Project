#pragma once
#include <iostream>

using namespace std;

class BSTNode {
private:
	BSTNode* pLeft;
	BSTNode* pRight;
	BSTNode* pNext;

	int data;

public:

	BSTNode() {
		pLeft = nullptr;
		pRight = nullptr;
		pNext = nullptr;
		data = 0;
	}
	BSTNode(int Data)
	{
		pLeft = nullptr;
		pRight = nullptr;
		pNext = nullptr;
		data = Data;
	}
	~BSTNode() {}

	void SetLeft(BSTNode* Left) {
		pLeft = Left;
	}
	void SetRight(BSTNode* Right) {
		pRight = Right;
	}
	void SetNext(BSTNode* Next) {
		pNext = Next;
	}
	void SetData(int Data) {
		data = Data;
	}

	BSTNode* GetLeft() {
		return pLeft;
	}
	BSTNode* GetRight() {
		return pRight;
	}
	BSTNode* GetNext() {
		return pNext;
	}
	int GetData() {
		return data;
	}
};