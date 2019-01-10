#ifndef FIGURE_H
#define FIGURE_H
#include "DirectionEnum.h"
#include "TextBuffer.h"
#include <windows.h>

class Figure
{
protected:
	char sign;
	short currentX, currentY;
	DirectionEnum direction = DirectionEnum::South;
	TextBuffer * textBuffer;
	void SetNewPos(DirectionEnum direction, short * xPos, short * yPos);
	short shotStartX, shotEndX;
	short shotStartY, shotEndY;
	short shotTickCounter;
public:
	Figure(short currentX, short currentY, TextBuffer * textBuffer);
	~Figure();
	virtual void Move(DirectionEnum direction);
	virtual COORD Shoot();
	virtual void ClearBullets();
	short Health = 3;
	
};

#endif