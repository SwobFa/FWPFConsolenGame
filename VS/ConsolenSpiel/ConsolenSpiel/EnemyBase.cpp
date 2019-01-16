#include "pch.h"
#include "EnemyBase.h"
#include <iostream>

using namespace std;

EnemyBase::EnemyBase(short currentX, short currentY, TextBuffer * textBuffer, short speed, DirectionEnum startDirection) : Figure(currentX, currentY, textBuffer), speed(speed)
{
	sign = 'B';
	textBuffer->SetChar(currentX, currentY, sign);
	direction = startDirection;
}

DirectionEnum EnemyBase::GetRandomDirection()
{
	int random = rand() % 4;
	switch (random)
	{
	case 0:
		return DirectionEnum::North;
	case 1:
		return DirectionEnum::East;
	case 2:
		return DirectionEnum::South;
	default:
		return  DirectionEnum::West;
	}
}

void EnemyBase::ChangeDirection()
{
	if (moveCounter % 10 == 0)
	{
		direction = GetRandomDirection();
		moveCounter = 0;
	}
}

void EnemyBase::MoveOneStep()
{
	short newXPos = currentX;
	short newYPos = currentY;

	SetNewPos(direction, &newXPos, &newYPos);

	char test = textBuffer->GetChar(newXPos, newYPos);
	if (test != 'x' && test != 'P' && test != '*' && test != 'B') {
		textBuffer->SetChar(currentX, currentY, ' ');
		currentX = newXPos;
		currentY = newYPos;
		textBuffer->SetChar(currentX, currentY, sign);
	} 
	else
	{
		direction = GetRandomDirection();
	}
}




EnemyBase::~EnemyBase()
{
}
