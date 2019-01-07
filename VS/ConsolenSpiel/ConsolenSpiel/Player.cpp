#include "pch.h"
#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(unsigned currentX, unsigned currentY, TextBuffer * textBuffer) : Figure(currentX, currentY, textBuffer)
{
	sign = 'P';
	textBuffer->SetChar(currentX, currentY, sign);
}

void Player::Move(DirectionEnum direction)
{
	unsigned newXPos = currentX;
	unsigned newYPos = currentY;

	SetNewPos(direction, &newXPos, &newYPos);

	char test = textBuffer->GetChar(newXPos, newYPos);
	if (test != 'x') {
		if (test == 'o')
			CoinsCount++;
		textBuffer->SetChar(currentX, currentY, ' ');
		currentX = newXPos;
		currentY = newYPos;
		textBuffer->SetChar(currentX, currentY, sign);
	}
}

void Player::Shoot()
{
	
}



Player::~Player()
{
}
