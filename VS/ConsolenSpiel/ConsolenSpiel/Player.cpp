#include "pch.h"
#include "Player.h"
#include <iostream>
#include "AppConstants.h"

using namespace std;

Player::Player(short const & currentX, short const & currentY, TextBuffer * textBuffer) : Figure(currentX, currentY, textBuffer)
{
	textBuffer->SetChar(currentX, currentY, AppConstants::PLAYERCHAR);
}

void Player::Move(DirectionEnum const & MovedDrection)
{
	direction = MovedDrection;
	short newXPos = currentX;
	short newYPos = currentY;

	GetNextPos(direction, &newXPos, &newYPos);

	char charOnPos = textBuffer->GetChar(newXPos, newYPos);
	if (charOnPos != AppConstants::BORDERCHAR) {
		if (charOnPos == AppConstants::COINCHAR)
			CoinsCount++;
		else if (charOnPos == AppConstants::BULLETCHAR)
			Health--;
		textBuffer->SetChar(currentX, currentY, ' ');
		currentX = newXPos;
		currentY = newYPos;
		textBuffer->SetChar(currentX, currentY, AppConstants::PLAYERCHAR);
	} 
}




Player::~Player()
{
}
