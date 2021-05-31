#pragma once
#include <stack>
#include <vector>
#include "TreeNode.h"

class BinarySearchTree
{
	friend class TransferWindowManager; // for accesing private member of TransferWindowManager
private:
	TreeNode * m_root; // get root node

public:
	BinarySearchTree() { m_root = NULL; } // constructor
	~BinarySearchTree() {
		destructorRecursive(m_root);} // destructor
	
	void destructorRecursive(TreeNode * Node)
	{
		if (Node)
		{
			destructorRecursive(Node->getLeftNode());
			destructorRecursive(Node->getRightNode());
			delete Node;
		}
	}
	TreeNode* PutDataInorder(TreeNode* Visit, vector<SoccerPlayerData>& v) {
		if (Visit == NULL)
			return NULL;
		PutDataInorder(Visit->getLeftNode(), v);
		v.push_back(Visit->m_data);
		PutDataInorder(Visit->getRightNode(), v);
	}

	void insert(SoccerPlayerData& data); // insert function
	void deletion(int ability); // ability = key, deletion function


	friend std::ostream& operator<<(std::ostream& os, const BinarySearchTree& tree) { // print operator overloading 
		
	// fill in your code to print in-order traversal of a binary search tree
		stack <TreeNode* > s; // make stack for storing TreeNode
		TreeNode * CurNode = tree.m_root; // set current node position with root of tree
		
		for(;;){
			while (CurNode != NULL) {
				s.push(CurNode); // push current node at stack
				CurNode = CurNode->getLeftNode(); // current node move at left node
			}
			if (!s.empty()) { // for empty is not empty
				CurNode = s.top(); // top of stack store at current node
				s.pop(); // remove top of stack

				os << CurNode << endl; // print current node 
				CurNode = CurNode->getRightNode(); // current node move at right node
			}
			else
				break;
		}
		return os;
	}
	
};
