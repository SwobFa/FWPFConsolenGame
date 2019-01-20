#ifndef FIGURE_H
#define FIGURE_H
#include "DirectionEnum.h"
#include "TextBuffer.h"
#include <windows.h>

class Figure
{

	void ClearBulletsHorizontal(short const & startX, short const & endX, short const & yCoord);
	void ClearBulletsVertical(short const & startY, short const & endY, short const & xCoord);

protected:

	short currentX, currentY;
	short shotStartX, shotEndX;
	short shotStartY, shotEndY;
	long lastShotMs;
	DirectionEnum direction = DirectionEnum::South;
	TextBuffer * textBuffer;

	void GetNextPos(DirectionEnum const & direction, short * xPos, short * yPos);

public:

	Figure(short const  & startX, short const  & startY, TextBuffer * textBuffer);
	~Figure();

	COORD Shoot();
	void ClearBullets();
	void Hit(COORD coords);
	short Health = 3;
	
};

#endif