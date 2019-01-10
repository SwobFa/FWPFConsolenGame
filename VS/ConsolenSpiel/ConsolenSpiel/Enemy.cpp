#include "pch.h"
#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(short currentX, short currentY, TextBuffer * textBuffer, short speed, DirectionEnum startDirection) : Figure(currentX, currentY, textBuffer), speed(speed)
{
	sign = 'B';
	textBuffer->SetChar(currentX, currentY, sign);
	direction = startDirection;
}

void Enemy::Move()
{
	if (Health > 0) {
		ticks++;
		if (ticks == speed)
		{

			if (moveCounter % 10 == 0)
			{
				direction = GetRandomDirection();
				moveCounter = 0;
			}

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

			ticks = 0;
			moveCounter++;
		}
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

void Enemy::Hit(_COORD const coords)
{
	if (currentX == coords.X && currentY == coords.Y)
	{
		Health--;
		if (Health == 0)
		{
			textBuffer->SetChar(currentX, currentY, ' ');
		}


	}
}


COORD Enemy::Shoot()
{
	return { 0,0 };
}



Enemy::~Enemy()
{
}
