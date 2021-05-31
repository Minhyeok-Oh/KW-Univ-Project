
#include "pch.h"
#include "Board.h"
#include <iostream>
#include <time.h>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

Board::Board()
{
	Block* Current = Block_Header;
	// step 1. make 1-dimension double linked list
	for (int i = 0; i < 16; i++) {
		Block* NewBlock = new Block();
		int x = i % 4, y = i / 4;
		NewBlock->SetNumber(0);
		NewBlock->SetX(x);
		NewBlock->SetY(y);

		if (!Block_Header) {
			Block_Header = NewBlock;
			Current = Block_Header;
		}
		else {
			Current -> SetRight(NewBlock);
			NewBlock->SetLeft(Current);
			Current = Current->GetRight();
		}
	}

	Block*Down = Block_Header;
	Block* Up = Block_Header;
	// for setting Down Block
	for (int i = 0; i < 4; i++) {
		Down = Down->GetRight();
	}
	// step 2. up and down bidirectional block connection
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			Down->SetUp(Up);
			Up->SetDown(Down);

			Down = Down->GetRight();
			Up = Up->GetRight();
		}
	}

	Current = Block_Header;
	// edge connection quit
	for (int i = 0; i < 16; i++) {
		if (i % 4 == 0 && i != 0) {
			Current->GetLeft()->SetRight(nullptr);
			Current->SetLeft(nullptr);
		}
		Current = Current->GetRight();
	}
	// random block
	for (int i = 0; i < 2; i++)
		RandomBlock();
}

Block* Board::GetBlockHeader(){
	return this->Block_Header;
}

Block* Board::SearchBlock(int x, int y) {
	Block* Search = Block_Header;
	for (int i = 0; i < x; i++)
		Search = Search->GetRight();
	for (int i = 0; i < y; i++)
		Search = Search->GetDown();
	return Search;
}

void Board::LocationSwapping(Block* A, Block* B) {
	int temp_x = A->GetX();
	int temp_y = A->GetY();

	A->SetX(B->GetX());
	A->SetY(B->GetY());
	B->SetX(temp_x);
	B->SetY(temp_y);
	if (B->GetX() == 0 && B->GetY() == 0)
		Block_Header = B;
	else if (A->GetX() == 0 && A->GetY() == 0)
		Block_Header = A;
}

bool Board::RandomBlock() {
	srand(time(NULL));

	while (1) {
		int x = rand() % 4;
		int y = rand() % 4;

		if (SearchBlock(x, y)->GetNumber() == 0) {
			SearchBlock(x, y)->SetNumber(2);
			return true;
		}
	}
	return false;
}

void Board::BlockSwapping(Block* Swap, int direction) // up = 1, down = 2, right = 3 , left = 4
{
	Block* Change = nullptr; // 


	if (direction == 1) { // up
		Change = Swap->GetUp();

		LocationSwapping(Change, Swap);

		

		Block* SwapU = Swap->GetUp(), * SwapD = Swap->GetDown(), * SwapR = Swap->GetRight(), * SwapL = Swap->GetLeft();

		Block* ChangeUp = Change->GetUp(), * ChangeDown = Change->GetDown(), * ChangeR = Change->GetRight(), * ChangeL = Change->GetLeft();

		if (Change->GetUp() == nullptr && SwapD == nullptr){ // up an down blocking
			Change->SetUp(Swap); Swap->SetDown(Change); Change->SetDown(nullptr); Swap->SetUp(nullptr);
		}
		else if (ChangeUp == nullptr){ // up blocking
			Swap->SetDown(Change); Change->SetUp(Swap); Change->SetDown(SwapD); SwapD->SetUp(Change); Swap->SetUp(nullptr);
		}
		else if (SwapD == nullptr){ // down blocking
			Swap->SetDown(Change); Change->SetUp(Swap);	Swap->SetUp(ChangeUp); ChangeUp->SetDown(Swap); Change->SetDown(nullptr);
		}
		else{
			Swap->SetDown(Change); Change->SetUp(Swap);	ChangeUp->SetDown(Swap); Swap->SetUp(ChangeUp);	Change->SetDown(SwapD);	SwapD->SetUp(Change);
		}
		// right and left block renewal
		if (SwapR) {
			SwapR->SetLeft(Change);	Change->SetRight(SwapR);
		}
		
		if (ChangeR){
			ChangeR->SetLeft(Swap);	Swap->SetRight(ChangeR);
		}
		if (SwapL) {
			SwapL->SetRight(Change); Change->SetLeft(SwapL);
		}
		if (ChangeL){
			ChangeL->SetRight(Swap); Swap->SetLeft(ChangeL);
		}		
	}
	else if (direction == 2) { // down
		Change = Swap->GetDown();
		LocationSwapping(Change, Swap);

		Block* SwapU = Swap->GetUp(), * SwapD = Swap->GetDown(), * SwapR = Swap->GetRight(), * SwapL = Swap->GetLeft();

		Block* ChangeUp = Change->GetUp(), * ChangeDown = Change->GetDown(), * ChangeR = Change->GetRight(), * ChangeL = Change->GetLeft();

		

		if (ChangeDown == nullptr && SwapU == nullptr){ // down and up blocking
			Change->SetDown(Swap);	Swap->SetUp(Change); Change->SetUp(nullptr); Swap->SetDown(nullptr);
		}
		else if (ChangeDown == nullptr){ // down blocking
			Swap->SetUp(Change); Change->SetDown(Swap); Change->SetUp(SwapU); SwapU->SetDown(Change); Swap->SetDown(nullptr);
		}
		else if (SwapU == nullptr){ // up blocking
			Swap->SetUp(Change); Change->SetDown(Swap);	Swap->SetDown(ChangeDown); ChangeDown->SetUp(Swap);	Change->SetUp(nullptr);
		}
		else{
			Swap->SetUp(Change); Change->SetDown(Swap);	SwapU->SetDown(Change);	Change->SetUp(SwapU); Swap->SetDown(ChangeDown); ChangeDown->SetUp(Swap);
		}
		//right and left renewal
		if (SwapR) {
			SwapR->SetLeft(Change); Change->SetRight(SwapR);
		}
		if (ChangeR){
			ChangeR->SetLeft(Swap);	Swap->SetRight(ChangeR);
		}

		if (SwapL) {
			SwapL->SetRight(Change); Change->SetLeft(SwapL);
		}
		if (ChangeL){
			ChangeL->SetRight(Swap); Swap->SetLeft(ChangeL);
		}
	}
	else if (direction ==3) { // right
		Change = Swap->GetRight();

		LocationSwapping(Change, Swap);

		Block* SwapU = Swap->GetUp(), * SwapD = Swap->GetDown(), * SwapR = Swap->GetRight(), * SwapL = Swap->GetLeft();

		Block* ChangeUp = Change->GetUp(),*ChangeDown = Change->GetDown(), * ChangeR = Change->GetRight(), * ChangeL = Change->GetLeft();


		if (ChangeR == nullptr && SwapL == nullptr){ // right and left blocking
			Change->SetRight(Swap);	Swap->SetLeft(Change); Change->SetLeft(nullptr); Swap->SetRight(nullptr);
		}
		else if (SwapL == nullptr){ // left blocking
			Swap->SetLeft(Change);	Change->SetRight(Swap);	ChangeR->SetLeft(Swap);	Swap->SetRight(ChangeR); Change->SetLeft(nullptr);
		}
		else if (ChangeR == nullptr){ // right blocking
			Swap->SetLeft(Change);	Change->SetRight(Swap);	SwapL->SetRight(Change); Change->SetLeft(SwapL); Swap->SetRight(nullptr);
		}
		else{
			Swap->SetLeft(Change);	Change->SetRight(Swap);	SwapL->SetRight(Change); Change->SetLeft(SwapL); Swap->SetRight(ChangeR); ChangeR->SetLeft(Swap);
		}

		// up and down renewal
		if (SwapU) {
			SwapU->SetDown(Change);	Change->SetUp(SwapU);
		}
		if (ChangeUp) {
			ChangeUp->SetDown(Swap); Swap->SetUp(ChangeUp);
		}
		if (SwapD) {
			SwapD->SetUp(Change); Change->SetDown(SwapD);
		}
		if (ChangeDown){
			ChangeDown->SetUp(Swap); Swap->SetDown(ChangeDown);
		}
		
	}
	else if (direction == 4) { // left
		Change = Swap->GetLeft();

		LocationSwapping(Change, Swap);

		Block* SwapU = Swap->GetUp(); Block* SwapD = Swap->GetDown(); Block* SwapR = Swap->GetRight(); Block* SwapL = Swap->GetLeft();

		Block* ChangeUp = Change->GetUp(); Block* ChangeDown = Change->GetDown(); Block* ChangeR = Change->GetRight(); Block* ChangeL = Change->GetLeft();

		if (ChangeL == nullptr && SwapR == nullptr){ // left and right blocking
			Change->SetLeft(Swap); Swap->SetRight(Change); Change->SetRight(nullptr); Swap->SetLeft(nullptr);
		}
		else if (ChangeL == nullptr){ // left blocking
			Swap->SetRight(Change);	Change->SetLeft(Swap); Change->SetRight(SwapR);	SwapR->SetLeft(Change);	Swap->SetLeft(nullptr);
		}
		else if (SwapR == nullptr){ // right blocking
			Swap->SetRight(Change);	Change->SetLeft(Swap); Swap->SetLeft(ChangeL);	ChangeL->SetRight(Swap); Change->SetRight(nullptr);
		}
		else{
			Swap->SetRight(Change);	Change->SetLeft(Swap); Change->SetRight(SwapR);	SwapR->SetLeft(Change);	Swap->SetLeft(ChangeL);	ChangeL->SetRight(Swap);
		}

		if (SwapU) {
			SwapU->SetDown(Change);	Change->SetUp(SwapU);
		}
		if (ChangeUp) {
			ChangeUp->SetDown(Swap); Swap->SetUp(ChangeUp);
		}
		if (SwapD) {
			SwapD->SetUp(Change); Change->SetDown(SwapD);
		}
		if (ChangeDown){
			ChangeDown->SetUp(Swap); Swap->SetDown(ChangeDown);
		}
	}
	
}

bool Board::Move(char direction) {

	Block* Current = 0;
	bool TFTMobile = 0;

	if(direction=='u') { // board up
		// all block move up
		for (int x = 0; x <= 3; x++){
			for (int i = 0; i < 3; i++){
				for (int y = 0; y < 3; y++){
					Current = SearchBlock(x, y);
					if (Current->GetNumber() == 0){ // if current number == 0
						BlockSwapping(Current, 2); // down block swapping
						if (Current->GetUp()->GetNumber() != 0)
							TFTMobile = true;
					}
				}
			}
		}
		// all block check whether same number
		for (int x = 0; x <= 3; x++){
			for (int y = 0; y < 3; y++){
				Current = SearchBlock(x, y);
				if (Current->GetDown() && Current->GetNumber() == Current->GetDown()->GetNumber() && Current->GetNumber() != 0)	{ // if same number
					Current->SetNumber(Current->GetNumber() + Current->GetDown()->GetNumber()); // add
					Current->GetDown()->SetNumber(0);
					TFTMobile = true;
				}
			}
		}

		// after add all block move up 
		for (int x = 0; x <= 3; x++){
			for (int i = 0; i < 3; i++){
				for (int y = 0; y < 3; y++)	{
					Current = SearchBlock(x, y);
					if (Current->GetNumber() == 0){
						BlockSwapping(Current, 2);
						if (Current->GetUp()->GetNumber() != 0)
							TFTMobile = true;
					}
				}
			}
		}
	}
	else if(direction=='d'){ // down
		for (int x = 3; x >= 0; x--){
			for (int i = 0; i < 3; i++){
				for (int y = 3; y > 0; y--){
					Current = SearchBlock(x, y);
					if (!Current->GetNumber()){
						BlockSwapping(Current, 1);
						if (Current->GetDown()->GetNumber() != 0)
							TFTMobile = true;
					}
				}
			}
		}

		for (int x = 0; x <= 3; x++){
			for (int y = 3; y > 0; y--){
				Current = SearchBlock(x, y);

				if (Current->GetUp() && Current->GetNumber() == Current->GetUp()->GetNumber() && Current->GetNumber() != 0)	{
					Current->SetNumber(Current->GetNumber() + Current->GetUp()->GetNumber());
					Current->GetUp()->SetNumber(0);
					TFTMobile = true;
				}
			}
		}
		for (int x = 3; x >= 0; x--){
			for (int i = 0; i < 3; i++)	{
				for (int y = 3; y > 0; y--)	{

					Current = SearchBlock(x, y);
					if (!Current->GetNumber()){
						BlockSwapping(Current, 1);//위쪽 블럭과 swap
						if (Current->GetDown()->GetNumber() != 0)
							TFTMobile = true;
					}
				}
			}
		}
	}
	else if (direction == 'l') { // left
		
		for (int y = 0; y <= 3; y++) {
			for (int i = 0; i < 3; i++) {
				for (int x = 0; x < 3; x++) {

					Current = SearchBlock(x, y);
					if (!Current->GetNumber()) {
						BlockSwapping(Current, 3);
						if (Current->GetLeft()->GetNumber() != 0)
							TFTMobile = true;
					}
				}
			}
		}

		for (int y = 0; y <= 3; y++) {
			for (int x = 0; x < 3; x++) {
				Current = SearchBlock(x, y);
				if (Current->GetRight() && Current->GetNumber() == Current->GetRight()->GetNumber() && Current->GetNumber() != 0) {
					Current->SetNumber(Current->GetNumber() + Current->GetRight()->GetNumber());
					Current->GetRight()->SetNumber(0);
					TFTMobile = 1;
				}
			}
		}

		for (int y = 0; y <= 3; y++) {
			for (int i = 0; i < 3; i++) {
				for (int x = 0; x < 3; x++) {
					Current = SearchBlock(x, y);
					if (Current->GetNumber() == 0) {
						BlockSwapping(Current, 3);
						if (Current->GetLeft()->GetNumber() != 0)
							TFTMobile = 1;
					}
				}
			}
		}
	}
	else if(direction=='r'){ // right

		for (int y = 0; y <= 3; y++){
			for (int i = 0; i < 3; i++)	{
				for (int x = 3; x > 0; x--)	{
					Current = SearchBlock(x, y);
					if (Current->GetNumber() == 0){
						BlockSwapping(Current, 4);
						if (Current->GetRight()->GetNumber() != 0)
							TFTMobile = 1;
					}
				}
			}
		}

		for (int y = 0; y <= 3; y++){
			for (int x = 3; x > 0; x--){
				Current = SearchBlock(x, y);
				if (Current->GetLeft() && Current->GetNumber() == Current->GetLeft()->GetNumber() && Current->GetNumber() != 0)	{
					Current->SetNumber(Current->GetNumber() + Current->GetLeft()->GetNumber());
					Current->GetLeft()->SetNumber(0);
					TFTMobile = 1;
				}
			}
		}

		for (int y = 0; y <= 3; y++){
			for (int i = 0; i < 3; i++)	{
				for (int x = 3; x > 0; x--)	{
					Current = SearchBlock(x, y);
					if (Current->GetNumber() == 0)
					{
						BlockSwapping(Current, 4);
						if (Current->GetRight()->GetNumber() != 0)
							TFTMobile = 1;
					}
				}
			}
		}
	}

	return TFTMobile;
}


/*
bool Board::IsFull() {
	Block* horizontal = Block_Header;
	Block* vertical = Block_Header;
	
	for (int i = 0; i < 16; i++) {
		if()
	}
}
*/

void Board::Clockwise()
{
	int Start = 0;

	Start = SearchBlock(3, 2)->GetNumber(); // start [3,2]
	SearchBlock(3, 2)->SetNumber(SearchBlock(2, 0)->GetNumber());	SearchBlock(2, 0)->SetNumber(SearchBlock(0, 1)->GetNumber());
	SearchBlock(0, 1)->SetNumber(SearchBlock(1, 3)->GetNumber());	SearchBlock(1, 3)->SetNumber(Start);
	Start = SearchBlock(3, 1)->GetNumber();
	SearchBlock(3, 1)->SetNumber(SearchBlock(1, 0)->GetNumber());	SearchBlock(1, 0)->SetNumber(SearchBlock(0, 2)->GetNumber());
	SearchBlock(0, 2)->SetNumber(SearchBlock(2, 3)->GetNumber());	SearchBlock(2, 3)->SetNumber(Start);
	Start = SearchBlock(3, 0)->GetNumber();
	SearchBlock(3, 0)->SetNumber(SearchBlock(0, 0)->GetNumber());	SearchBlock(0, 0)->SetNumber(SearchBlock(0, 3)->GetNumber());
	SearchBlock(0, 3)->SetNumber(SearchBlock(3, 3)->GetNumber());	SearchBlock(3, 3)->SetNumber(Start);
	Start = SearchBlock(2, 1)->GetNumber();
	SearchBlock(2, 1)->SetNumber(SearchBlock(1, 1)->GetNumber());	SearchBlock(1, 1)->SetNumber(SearchBlock(1, 2)->GetNumber());
	SearchBlock(1, 2)->SetNumber(SearchBlock(2, 2)->GetNumber());	SearchBlock(2, 2)->SetNumber(Start);
}


void Board::Counterclockwise()
{
	int Start = 0;
	Start = SearchBlock(2, 1)->GetNumber(); // start [2,1]
	SearchBlock(2, 1)->SetNumber(SearchBlock(2, 2)->GetNumber()); SearchBlock(2, 2)->SetNumber(SearchBlock(1, 2)->GetNumber());
	SearchBlock(1, 2)->SetNumber(SearchBlock(1, 1)->GetNumber()); SearchBlock(1, 1)->SetNumber(Start);
	Start = SearchBlock(3, 2)->GetNumber();
	SearchBlock(3, 2)->SetNumber(SearchBlock(1, 3)->GetNumber()); SearchBlock(1, 3)->SetNumber(SearchBlock(0, 1)->GetNumber());
	SearchBlock(0, 1)->SetNumber(SearchBlock(2, 0)->GetNumber()); SearchBlock(2, 0)->SetNumber(Start);
	Start = SearchBlock(3, 1)->GetNumber();
	SearchBlock(3, 1)->SetNumber(SearchBlock(2, 3)->GetNumber()); SearchBlock(2, 3)->SetNumber(SearchBlock(0, 2)->GetNumber()); 
	SearchBlock(0, 2)->SetNumber(SearchBlock(1, 0)->GetNumber()); SearchBlock(1, 0)->SetNumber(Start);
	Start = SearchBlock(3, 0)->GetNumber();
	SearchBlock(3, 0)->SetNumber(SearchBlock(3, 3)->GetNumber()); SearchBlock(3, 3)->SetNumber(SearchBlock(0, 3)->GetNumber());
	SearchBlock(0, 3)->SetNumber(SearchBlock(0, 0)->GetNumber()); SearchBlock(0, 0)->SetNumber(Start);
}

bool Board::isWin()
{
	Block* horizontal = Block_Header,*vertical = Block_Header;
	while (vertical){
		while (horizontal){
			if (horizontal->GetNumber() == 2048)
				return true;
			horizontal = horizontal->GetRight();
		}
		vertical = vertical->GetDown();
		horizontal = vertical;
	}
	return false;
}



bool Board::isLose()
{
	Block* horizontal = Block_Header,* vertical = Block_Header;
	while (vertical){
		while (horizontal){
			if (horizontal->GetNumber() == 0)
				return false;			
			else{ // if same number do exist, no lose
				if (horizontal->GetUp())
					if (horizontal->GetNumber() == horizontal->GetUp()->GetNumber())
						return false;
				if (horizontal->GetDown())
					if (horizontal->GetNumber() == horizontal->GetDown()->GetNumber())
						return false;
				if (horizontal->GetRight())
					if (horizontal->GetNumber() == horizontal->GetRight()->GetNumber())
						return false;
				if (horizontal->GetLeft())
					if (horizontal->GetNumber() == horizontal->GetLeft()->GetNumber())
						return false;
			}
			horizontal = horizontal->GetRight();
		}
		vertical = vertical->GetDown();
		horizontal = vertical;
	}
	return true;
}

void Board::ResetGame() { // Game initialize
	Block* horizontal = Block_Header;
	Block* vertical = Block_Header;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			horizontal->SetNumber(0);
			horizontal = horizontal->GetRight();
		}
		vertical = vertical->GetDown();
		horizontal = vertical;
	}
	for (int i = 0; i < 2; i++)
		RandomBlock();
}

void Board::OutLog(CFile& Log, int turnNum, int direction) {

	char buffer[100] = { 0, };
	Block* horizontal = Block_Header,* vertical = Block_Header;

	_itoa(turnNum, buffer, 10);
	Log.Write(buffer, strlen(buffer));
	if (direction == 1) // up
		Log.Write(". Key_Up\n", 9);
	else if (direction == 2)// down
		Log.Write(". Key_Down\n", 11);
	else if (direction == 3)// right
		Log.Write(". Key_Right\n", 12);
	else if (direction == 4) // left
		Log.Write(". Key_Left\n", 11);
	else if (direction == 5) // l to r
		Log.Write(". Mouse_Left_to_Right\n", 22);
	else if (direction == 6) // r to l
		Log.Write(". Mouse_Right_to_Left\n", 22);

	Log.Write("[result]\n", 9);
	while (vertical){
		while (horizontal){
			if (horizontal->GetNumber() == 0) // space print
				Log.Write("\t", 1);			
			else{
				_itoa(horizontal->GetNumber(), buffer, 10);
				Log.Write(buffer, strlen(buffer));
				Log.Write("\t", 1);
			}
			horizontal = horizontal->GetRight();
		}
		Log.Write("\n", 1);
		vertical = vertical->GetDown();
		horizontal = vertical;
	}
	Log.Write("\n", 1);
	Log.Write("\n", 1);
}