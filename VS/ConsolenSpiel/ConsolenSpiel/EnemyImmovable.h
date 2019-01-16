#pragma once
#include "EnemyBase.h"
class EnemyImmovable : public EnemyBase
{
public:
	EnemyImmovable(short currentX, short currentY, TextBuffer * textBuffer, short speed, DirectionEnum startDirection);
	~EnemyImmovable();

	void Move();
};
