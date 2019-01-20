#ifndef ENEMYWALLRUNNER_H
#define ENEMYWALLRUNNER_H

#include "EnemyBase.h"

class EnemyWallRunner : public EnemyBase
{
public:
	EnemyWallRunner(short const & currentX, short const & currentY, TextBuffer * textBuffer, long const & speed, DirectionEnum const & startDirection);
	~EnemyWallRunner();

	void Move();
};

#endif
