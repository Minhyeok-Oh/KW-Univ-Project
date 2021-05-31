#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "Block.h"
class Board
{
private:
	Block* Block_Header;
public:
	Board();

	Block* GetBlockHeader();
	Block* SearchBlock(int x, int y);
	

	bool RandomBlock();
	//bool IsFull();

	

	void BlockSwapping(Block* Swap, int direction);
	bool Move(char direction);
	//bool BoardUp();
	//bool BoardDown();
	//bool BoardLeft();
	//bool BoardRight();
	void LocationSwapping(Block* A, Block* B);

	void OutLog(CFile& Log, int turnNum, int direction);
	bool isWin();
	bool isLose();

	void Clockwise();
	void Counterclockwise();
	
	void ResetGame();




	
	
};