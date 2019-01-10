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
		textBuffer->SetChar(currentX, currentY, ' ');
		currentX = newXPos;
		currentY = newYPos;
		textBuffer->SetChar(currentX, currentY, sign);
	}
}

COORD Player::Shoot()
{
	bool hit = false;

	/*switch (direction)
	{
	case DirectionEnum::North:
		shotStartY = currentY - 1;
		shotStartX = currentX;
		break;
	case DirectionEnum::East:
		shotStartY = currentY;
		shotStartX = currentX + 1;
		break;
	case DirectionEnum::South:
		shotStartY = currentY + 1;
		shotStartX = currentX;
		break;
	case DirectionEnum::West:
		shotStartY = currentY;
		shotStartX = currentX - 1;
		break;
	}*/

	shotStartX = currentX;
	shotStartY = currentY;

	SetNewPos(direction, &shotStartX, &shotStartY);

	short newXPos = shotStartX;
	short newYPos = shotStartY;

	while (!hit)
	{
		SetNewPos(direction, &newXPos, &newYPos);

		shotEndX = newXPos;
		shotEndY = newYPos;

		char test = textBuffer->GetChar(newXPos, newYPos);
		if (test != 'x' && test != 'B' && test != '*') {
			
			textBuffer->SetChar(shotEndX, shotEndY, '.');
		}
		else
		{
			return {shotEndX, shotEndY};
		}
	}
	
}



Player::~Player()
{
}
