#pragma once

#include "SoccerPlayerData.h"
#include <iostream>

class TreeNode
{
	friend class BinarySearchTree;
	friend class TransferWindowManager;
private:
	SoccerPlayerData m_data; // private member (get soccerplayerdata private member)
	TreeNode* m_left; // private member
	TreeNode* m_right; // private member
public:
	TreeNode() :m_left(NULL), m_right(NULL) {} // constructor
	~TreeNode() { } // destructor
	
	TreeNode(SoccerPlayerData & data, TreeNode* left = NULL, TreeNode* right = NULL) // constructor
	{
		this->m_data = data; // data 
		this->m_left = left; // left node
		this->m_right = right; // right node
	}
	
	TreeNode* getLeftNode() const { return m_left; } // moving at left node function
	TreeNode* getRightNode() const { return m_right; } // moving at right node function
	void setLeftNode(TreeNode* pNew); // setting left node function
	void setRightNode(TreeNode* pNew); // setting right node function
	void setData(SoccerPlayerData& data) { m_data = data; }; // setting SoccerPlayerData data function

	// printing operator overloading function
	friend std::ostream& operator<<(std::ostream& os, const TreeNode* node)
	{
		if(node != NULL)
			os << node->m_data; // print node data
		return os;
	}
};
