#include "pch.h"
#include "Figure.h"
#include "MillisecondsHelper.h"


Figure::Figure(short currentX, short currentY, TextBuffer * textBuffer) : currentX(currentX), currentY(currentY), textBuffer(textBuffer)
{

}

void Figure::SetNewPos(DirectionEnum direction, short* xPos, short* yPos)
{

	switch (direction) {
		// w
	case DirectionEnum::North:
		if (*yPos > 0)
			(*yPos)--;
		break;
		// a
	case DirectionEnum::West:
		if (*xPos > 0)
			(*xPos)--;

		break;
		// s
	case DirectionEnum::South:
		if (*yPos <= textBuffer->Height - 1)
			(*yPos)++;
		break;
		// d
	case DirectionEnum::East:
		if (*xPos <= textBuffer->Width - 1)
			(*xPos)++;
		break;
	default:
		break;
	}
}


void Figure::Hit(_COORD const coords)
{
	if (currentX == coords.X && currentY == coords.Y)
	{
		Health--;
		if (Health == 0)
		{
			textBuffer->SetChar(currentX, currentY, ' ');
		}


	}
}

COORD Figure::Shoot()
{
	if ((get_milliseconds() - lastShotMs >= 1000 || lastShotMs == 0) && Health > 0)
	{
		lastShotMs = get_milliseconds();
		shotStartX = currentX;
		shotStartY = currentY;

		SetNewPos(direction, &shotStartX, &shotStartY);

		short newXPos = shotStartX;
		short newYPos = shotStartY;

		while (true)
		{
			char charOnPos = textBuffer->GetChar(newXPos, newYPos);
			if (charOnPos != 'x' && charOnPos != 'B' && charOnPos != '*' &&  charOnPos != 'P') {

				textBuffer->SetChar(newXPos, newYPos, '.');

				shotEndX = newXPos;
				shotEndY = newYPos;
			}
			else
			{
				return { newXPos, newYPos };
			}
			SetNewPos(direction, &newXPos, &newYPos);
		}
	}

	return {0,0};
}


void Figure::ClearBullets()
{

	if (shotStartX != 0 && shotStartY != 0 && shotEndX != 0 && shotEndY != 0)
	{
		if (get_milliseconds() - lastShotMs >= 150)
		{
			if (shotStartX == shotEndX)
				shotStartY < shotEndY ? ClearBulletsVertical(shotStartY, shotEndY, shotStartX) : ClearBulletsVertical(shotEndY, shotStartY, shotStartX);
			else
				shotStartX < shotEndX ? ClearBulletsHorizontal(shotStartX, shotEndX, shotStartY) : ClearBulletsHorizontal(shotEndX, shotStartX, shotStartY);

			shotStartX = shotEndX = shotStartY = shotEndY = 0;
		}
	}

}

void Figure::ClearBulletsHorizontal(short startX, short endX, short yCoord)
{
	short currentXToDelete = startX;

	while (currentXToDelete <= endX)
	{
		char charOnPos = textBuffer->GetChar(currentXToDelete, yCoord);
		if (charOnPos == '.')
			textBuffer->SetChar(currentXToDelete, yCoord, ' ');

		currentXToDelete++;
	}

}

void Figure::ClearBulletsVertical(short startY, short endY, short xCoord)
{
	short currentYToDelete = startY;

	while (currentYToDelete <= endY)
	{
		char charOnPos = textBuffer->GetChar(xCoord, currentYToDelete);
		if (charOnPos == '.')
			textBuffer->SetChar(xCoord, currentYToDelete, ' ');

		currentYToDelete++;
	}
}





Figure::~Figure()
{
}
