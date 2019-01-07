#include "pch.h"
#include "Figure.h"


Figure::Figure(unsigned currentX, unsigned currentY, TextBuffer * textBuffer) : currentX(currentX), currentY(currentY), textBuffer(textBuffer)
{
	direction = DirectionEnum::North;
}

void Figure::Move(DirectionEnum direction)
{
	
}

void Figure::Shoot()
{
	
}

void Figure::SetNewPos(DirectionEnum direction, unsigned* xPos, unsigned* yPos)
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
		if (*yPos < textBuffer->Height - 1)
			(*yPos)++;
		break;
		// d
	case DirectionEnum::East:
		if (*xPos < textBuffer->Width - 1)
			(*xPos)++;
		break;
	default:
		break;
	}
}


Figure::~Figure()
{
}
