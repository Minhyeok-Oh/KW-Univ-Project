#include "pch.h"
#include "Block.h"

Block::Block()
{
}
Block::~Block()
{

}
int Block::GetNumber()
{
	return this->m_number;
}

int Block::GetX()
{
	return this->m_x;
}

int Block::GetY()
{
	return this->m_y;
}

void Block::SetNumber(int Number)
{
	this->m_number = Number;
}
void Block::SetX(int X)
{
	this->m_x = X;
}
void Block::SetY(int Y)
{
	this->m_y = Y;
}

void Block::SetUp(Block* Up)
{
	this->p_Up = Up;
}

void Block::SetDown(Block* Down)
{
	this->p_Down = Down;
}

void Block::SetRight(Block* Right)
{
	this->p_Right = Right;
}
void Block::SetLeft(Block* Left)
{
	this->p_Left = Left;
}

Block* Block::GetUp() {
	return this->p_Up;
}

Block* Block::GetDown() {
	return this->p_Down;
}

Block* Block::GetRight() {
	return this->p_Right;
}
Block* Block::GetLeft() {
	return this->p_Left;
}