#pragma once
#include <iostream>
#include "BSTNode.h"
#include "Queue.h"
using namespace std;

class Tree {
private:
	BSTNode* root;
	BSTNode* current, * parent;
	
public:
	Tree() {
		root = nullptr;
		current = parent = nullptr;
		
	}
	BSTNode* GetRoot() { // return ROOT of BST
		return root;
	}
	int Search(int num) {
		parent = root;
		current = root;
		while (current) {
			if (num == current->GetData()) return 1;
			parent = current;
			if (num < current->GetData()) current = current->GetLeft();
			else current = current->GetRight();
		}
		return 0;
	}
	bool Insert(BSTNode* newNode) {  // insert newnode to BST
		current = root;
		parent = root;
		if (root == nullptr) { // BST do not exist
			root = newNode;
			return true;
		}
		else {
			if (Search(newNode->GetData())) { // exception handling
				cout << newNode->GetData()<<" is duplicated" << endl;
				return false;
			}
			else {
				while (current != nullptr) {
					parent = current;
					if (newNode->GetData() < parent->GetData()) {
						current = current->GetLeft(); // left subtree
					}
					else {
						current = current->GetRight(); // right subtree
					}
				}
				if (newNode->GetData() < parent->GetData()) {
					parent->SetLeft(newNode);
				}
				else {
					parent->SetRight(newNode);
				}
			}
		}
		return true;
	}
	
	
	

	
	
};