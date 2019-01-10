#include "pch.h"
#include "Figure.h"


Figure::Figure(short currentX, short currentY, TextBuffer * textBuffer) : currentX(currentX), currentY(currentY), textBuffer(textBuffer)
{

}

void Figure::Move(DirectionEnum direction)
{
	
}

COORD Figure::Shoot()
{
	return {0,0};
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

void Figure::ClearBullets()
{
	/*if(shotTickCounter == 50)
	{
		
		textBuffer->SetChar(shotStartX, shotStartY, ' ');
		if(shotStartX == shotEndX)
		{

			while (test != ' ')
			{
				
			}
		}

		
	}
	shotTickCounter++*/;
}



Figure::~Figure()
{
}
