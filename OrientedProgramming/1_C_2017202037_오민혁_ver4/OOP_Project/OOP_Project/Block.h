#pragma once
#include "pch.h"
class Block
{
	int m_number, m_x, m_y;
	Block* p_Up;
	Block* p_Down;
	Block* p_Left;
	Block* p_Right;
public:
	Block();
	~Block();

	int GetNumber();
	int GetX();
	int GetY();
	void SetNumber(int Number);
	void SetX(int X);
	void SetY(int Y);


	void SetUp(Block* Up);
	void SetDown(Block* Down);
	void SetRight(Block* Right);
	void SetLeft(Block* Left);

	Block* GetUp();
	Block* GetDown();
	Block* GetRight();
	Block* GetLeft();
};