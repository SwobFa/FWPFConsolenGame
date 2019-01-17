#ifndef FIGURE_H
#define FIGURE_H
#include "DirectionEnum.h"
#include "TextBuffer.h"
#include <windows.h>

class Figure
{

	void ClearBulletsHorizontal(short startX, short endX, short yCoord);
	void ClearBulletsVertical(short startY, short endY, short xCoord);

protected:

	char sign;
	short currentX, currentY;
	short shotStartX, shotEndX;
	short shotStartY, shotEndY;
	long lastShotMs;
	DirectionEnum direction = DirectionEnum::South;
	TextBuffer * textBuffer;
	bool shotFired = false;

	void SetNewPos(DirectionEnum direction, short * xPos, short * yPos);

public:

	Figure(short currentX, short currentY, TextBuffer * textBuffer);
	~Figure();

	COORD Shoot();
	void ClearBullets();
	void Hit(COORD coords);
	short Health = 3;
	
};

#endif