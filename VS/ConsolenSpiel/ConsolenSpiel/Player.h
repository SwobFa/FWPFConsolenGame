#ifndef PLAYER_H
#define PLAYER_H
#include "Figure.h"

class Player : public Figure
{
public:
	Player(short const & currentX, short const & currentY, TextBuffer * textBuffer);
	~Player();
	void Move(DirectionEnum const & direction);
	short CoinsCount;

};

#endif