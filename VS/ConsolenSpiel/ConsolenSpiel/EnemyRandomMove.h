#pragma once
#include "EnemyBase.h"
class EnemyRandomMove : public EnemyBase
{
public:
	EnemyRandomMove(short currentX, short currentY, TextBuffer * textBuffer, short speed, DirectionEnum startDirection);
	~EnemyRandomMove();

	void Move();

};

