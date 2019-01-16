#pragma once
#include "EnemyBase.h"
class EnemyWallRunner : public EnemyBase
{
public:
	EnemyWallRunner(short currentX, short currentY, TextBuffer * textBuffer, short speed, DirectionEnum startDirection);
	~EnemyWallRunner();

	void Move();
};

