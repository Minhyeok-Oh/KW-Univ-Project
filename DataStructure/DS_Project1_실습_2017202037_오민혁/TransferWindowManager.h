#pragma once

#include "BinarySearchTree.h"

#include <iostream>
#include <string>

class TransferWindowManager
{
private:
	int m_budget; // budget

	BinarySearchTree fwBST; // forward Binary Search Tree
	BinarySearchTree mfBST; // midfielder Binary Search Tree
	BinarySearchTree dfBST; // defender Binary Search Tree
	BinarySearchTree gkBST; // goalkeeper Binary Search Tree

public:

	struct SoccerTeam 
	{
		SoccerPlayerData fw; // make SoccerPlayerData form forward data
		SoccerPlayerData mf; // make SoccerPlayerData form midfielder data
		SoccerPlayerData df; // make SoccerPlayerData form defender data
		SoccerPlayerData gk; // make SoccerPlayerData form goalkeeper data

		int sum_transfer_fee;
		int sum_ability;

		SoccerTeam(); // constructor
		SoccerTeam(SoccerPlayerData fw, SoccerPlayerData mf, SoccerPlayerData df, SoccerPlayerData gk); // storing SoccerPlayerData form
		friend std::ostream& operator<<(std::ostream& os, const SoccerTeam& team); // define print operator overloading
	};

	TransferWindowManager(std::string file_dir, int budget); // declare running program function
	
	friend std::ostream& operator<<(std::ostream& os, const TransferWindowManager& manager); // declare printing operator overloading

	SoccerTeam getBestTeam(); //  declare getting best team function
};

