#include <iostream>
#include "TransferWindowManager.h"

using namespace std;

int main(int argc, char** argv)
{
	TransferWindowManager transfer_window_manager(argv[1], atoi(argv[2])); // program execute form
	cout << transfer_window_manager << endl; // print operator overloading
	TransferWindowManager::SoccerTeam team = transfer_window_manager.getBestTeam(); // call function getBestTeam
	cout << "Best Players" << endl;
	cout << team << endl;
	cout << "-----" << endl;
	cout << "The Transfer window close" << endl;
	cout << transfer_window_manager << endl; // printing without best player
    return 0;
}

