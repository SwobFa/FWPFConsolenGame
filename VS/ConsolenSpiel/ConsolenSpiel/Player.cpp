#include "pch.h"
#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(short currentX, short currentY, TextBuffer * textBuffer) : Figure(currentX, currentY, textBuffer)
{
	sign = 'P';
	textBuffer->SetChar(currentX, currentY, sign);
}

void Player::Move(DirectionEnum MovedDrection)
{
	direction = MovedDrection;
	short newXPos = currentX;
	short newYPos = currentY;

	SetNewPos(direction, &newXPos, &newYPos);

	char test = textBuffer->GetChar(newXPos, newYPos);
	if (test != 'x') {
		if (test == '*')
			CoinsCount++;
		else if (test == '.')
			Health--;
		textBuffer->SetChar(currentX, currentY, ' ');
		currentX = newXPos;
		currentY = newYPos;
		textBuffer->SetChar(currentX, currentY, sign);
	} 
}




Player::~Player()
{
}
