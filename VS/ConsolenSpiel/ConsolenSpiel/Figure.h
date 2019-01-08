#ifndef FIGURE_H
#define FIGURE_H
#include "DirectionEnum.h"
#include "TextBuffer.h"

class Figure
{
protected:
	char sign;
	unsigned currentX, currentY;
	DirectionEnum direction = DirectionEnum::South;
	TextBuffer * textBuffer;
	void SetNewPos(DirectionEnum direction, unsigned * xPos, unsigned * yPos);
public:
	Figure(unsigned currentX, unsigned currentY, TextBuffer * textBuffer);
	~Figure();
	virtual void Move(DirectionEnum direction);
	virtual void Shoot();
};

#endif