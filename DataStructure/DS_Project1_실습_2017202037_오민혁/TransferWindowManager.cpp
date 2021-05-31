#include "TransferWindowManager.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

TransferWindowManager::SoccerTeam::SoccerTeam() // constructor
{
	//You don't need to edit this function.
}
//make soccer team
TransferWindowManager::SoccerTeam::SoccerTeam(SoccerPlayerData fw, SoccerPlayerData mf, SoccerPlayerData df, SoccerPlayerData gk)
{
	this->fw = fw;
	this->mf = mf;
	this->df = df;
	this->gk = gk;

	this->sum_transfer_fee = fw.m_transfer_fee + mf.m_transfer_fee + df.m_transfer_fee + gk.m_transfer_fee;
	this->sum_ability = fw.m_ability + mf.m_ability + df.m_ability + gk.m_ability;
}

// define printing soccer team operator overloading function
std::ostream& operator<<(std::ostream& os, const TransferWindowManager::SoccerTeam& team)
{
	os << team.fw << std::endl;
	os << team.mf << std::endl;
	os << team.df << std::endl;
	os << team.gk << std::endl;

	os << "sum_transfer_fee " << team.sum_transfer_fee << std::endl;
	os << "sum_ability " << team.sum_ability << std::endl;

	return os;
}

// define program executing function
TransferWindowManager::TransferWindowManager(std::string file_dir, int budget)
{
	m_budget = budget;

	std::ifstream in(file_dir); // file input
	std::string line; // file string

	while (std::getline(in, line)) // until be string
	{
	//Fill in the code to initialize 4 Binary Search Trees(fw, mf, df, gk)
		vector<string> v; // vector 

		istringstream ss(line); // for token string line

		while (getline(ss, line, ',')) // tokenize 
		{
			if (line[0] == ' ') 
				line.erase(0, 1); // remove space
			v.push_back(line); // store tokenizing string at vector
		}

		SoccerPlayerData PlayerData(v[0], v[1], stoi(v[2]), stoi(v[3]));

		if (!v[1].compare("Forward")) { // add forward
			fwBST.insert(PlayerData);
		}
		else if (!v[1].compare("Midfielder")) { // add midfielder
			mfBST.insert(PlayerData);
		}
		else if (!v[1].compare("Defender")) { // add defender
			dfBST.insert(PlayerData);
		}
		else if (!v[1].compare("Goalkeeper")) { // add goalkeeper
			gkBST.insert(PlayerData);
		}
	}
}
//define printing operator overloading function
std::ostream& operator<<(std::ostream& os, const TransferWindowManager& manager)
{
	os << "********Forward List********" << std::endl;
	os << manager.fwBST;
	os << "****************************" << std::endl;

	os << "********Midflder List********" << std::endl;
	os << manager.mfBST;
	os << "*****************************" << std::endl;

	os << "********Defender List********" << std::endl;
	os << manager.dfBST;
	os << "*****************************" << std::endl;

	os << "********Goalkeeper List********" << std::endl;
	os << manager.gkBST;
	os << "*******************************" << std::endl;

	return os;
}
// define getBestTeam function
TransferWindowManager::SoccerTeam TransferWindowManager::getBestTeam()
{
	SoccerTeam best_team;
	
	//Fill in the code to search the best_team from 4 BSTs
	//The datas for best team must be stored in the variable best_team.
	//*best team means the most powerful team that is defined in the project introduction file.
	best_team.sum_ability = 0;
	best_team.sum_transfer_fee = 0;

	vector <SoccerPlayerData> Vec_fw;
	vector <SoccerPlayerData> Vec_mf;
	vector <SoccerPlayerData> Vec_df;
	vector <SoccerPlayerData> Vec_gk;

	TreeNode * fwNode = fwBST.m_root;
	TreeNode * mfNode = mfBST.m_root;
	TreeNode * dfNode = dfBST.m_root;
	TreeNode * gkNode = gkBST.m_root;

	fwBST.PutDataInorder(fwNode, Vec_fw);
	mfBST.PutDataInorder(mfNode, Vec_mf);
	dfBST.PutDataInorder(dfNode, Vec_df);
	gkBST.PutDataInorder(gkNode, Vec_gk);

	SoccerPlayerData forward; // declare SoccerPlayerData forward
	SoccerPlayerData midfielder; // declare SoccerPlayerData midfielder
	SoccerPlayerData defender; // declare SoccerPlayerData defender
	SoccerPlayerData goalkeeper; // declare SoccerPlayerData goalkeeper

	for (int f = 0; f < Vec_fw.size(); f++) {
		forward = Vec_fw[f];// temporary data storing
		for (int m = 0; m < Vec_mf.size(); m++) {
			midfielder = Vec_mf[m];
			for (int d = 0; d < Vec_df.size(); d++) {
				defender = Vec_df[d];
				for (int g = 0; g < Vec_gk.size(); g++) {
					goalkeeper = Vec_gk[g];

					int transfer_fee_sum = forward.m_transfer_fee + midfielder.m_transfer_fee + defender.m_transfer_fee + goalkeeper.m_transfer_fee; // sum transfer fee
					int sum_ability = forward.m_ability + midfielder.m_ability + defender.m_ability + goalkeeper.m_ability; // sum ability

					if (transfer_fee_sum > m_budget) {
						continue;
					}
					else {
						if (best_team.sum_ability < sum_ability) { // strong team data renew
							best_team.fw = forward;
							best_team.mf = midfielder;
							best_team.df = defender;
							best_team.gk = goalkeeper;
							best_team.sum_ability = sum_ability;
							best_team.sum_transfer_fee = transfer_fee_sum;
						}
						else if (best_team.sum_ability == sum_ability) { 
							if (best_team.sum_transfer_fee > transfer_fee_sum) {
								best_team.fw = forward;
								best_team.mf = midfielder;
								best_team.df = defender;
								best_team.gk = goalkeeper;
								best_team.sum_ability = sum_ability;
								best_team.sum_transfer_fee = transfer_fee_sum;
							}
							else
								continue;
						}
						else
							continue;
					}
				}
			}
		}
	}
	// deletion best team data from binary search tree
	fwBST.deletion(best_team.fw.m_ability);
	mfBST.deletion(best_team.mf.m_ability);
	dfBST.deletion(best_team.df.m_ability);
	gkBST.deletion(best_team.gk.m_ability);

	return best_team;
}
