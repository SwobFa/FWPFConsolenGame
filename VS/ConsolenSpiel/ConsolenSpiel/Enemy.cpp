#include "pch.h"
#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(unsigned currentX, unsigned currentY, TextBuffer * textBuffer, unsigned speed, DirectionEnum startDirection) : Figure(currentX, currentY, textBuffer), speed(speed)
{
	sign = 'B';
	textBuffer->SetChar(currentX, currentY, sign);
	direction = startDirection;
}

void Enemy::Move()
{
	ticks++;
	if(ticks == speed)
	{

		if(moveCounter % 10 == 0)
		{
			direction = GetRandomDirection();
			moveCounter = 0;
		}

		unsigned newXPos = currentX;
		unsigned newYPos = currentY;

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

		ticks = 0;
		moveCounter++;
	}
}

DirectionEnum Enemy::GetRandomDirection()
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

char Enemy::Shoot()
{
	return 'x';
}



Enemy::~Enemy()
{
}
