#pragma once
#include <stack>
#include <string>
#include <iostream>
using namespace std;

class SoccerPlayerData
{
	friend class TreeNode; // for accessing TreeNode class
	friend class BinarySearchTree; // for accessing BinarySearchTree class
	friend class TransferWindowManager; // for accessing TransferWindowManager class
private:
	std::string m_name; // private member m_name
	std::string m_position; // private member m_position

	int m_transfer_fee; // private member m_transfer_fee
	int m_ability; // private member m_ability

public:
	SoccerPlayerData() { }
	SoccerPlayerData(std::string name, std::string position, int transfer_fee, int ability) // SoccerPlayerData making form function
		:
		m_name(name),
		m_position(position),
		m_transfer_fee(transfer_fee),
		m_ability(ability)
	{
	}

	friend std::ostream& operator<<(std::ostream& os, const SoccerPlayerData& node) { // define Printing Operator Overloading 
		os << "(node.m_name: " << node.m_name << "), " // making print form
			<< "(node.m_position: " << node.m_position << "), "
			<< "(node.m_transfer_fee: " << node.m_transfer_fee << "), "
			<< "(node.m_ability: " << node.m_ability << ")";
		return os;
	}
};
