#include "pch.h"
#include "Figure.h"


Figure::Figure(unsigned currentX, unsigned currentY, TextBuffer * textBuffer) : currentX(currentX), currentY(currentY), textBuffer(textBuffer)
{

}

void Figure::Move(DirectionEnum direction)
{
	
}

char Figure::Shoot()
{
	return 'x';
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
