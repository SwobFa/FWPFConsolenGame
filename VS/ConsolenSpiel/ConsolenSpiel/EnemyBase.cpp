#include "pch.h"
#include "EnemyBase.h"
#include <iostream>
#include "AppConstants.h"

using namespace std;

EnemyBase::EnemyBase(short const & currentX, short const & currentY, TextBuffer * textBuffer, long const & speed, DirectionEnum const & startDirection) : Figure(currentX, currentY, textBuffer), speed(speed)
{
	textBuffer->SetChar(currentX, currentY, AppConstants::ENEMYCHAR);
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

void EnemyBase::MoveOneStep()
{
	short newXPos = currentX;
	short newYPos = currentY;

	GetNextPos(direction, &newXPos, &newYPos);

	char charOnPos = textBuffer->GetChar(newXPos, newYPos);
	if (charOnPos != AppConstants::BORDERCHAR && charOnPos != AppConstants::PLAYERCHAR && charOnPos != AppConstants::COINCHAR && charOnPos != AppConstants::ENEMYCHAR) {
		textBuffer->SetChar(currentX, currentY, ' ');
		currentX = newXPos;
		currentY = newYPos;
		textBuffer->SetChar(currentX, currentY, AppConstants::ENEMYCHAR);
	} 
	else
	{
		direction = GetRandomDirection();
	}
}




EnemyBase::~EnemyBase()
{
}
