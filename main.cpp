#include <iostream>
#include <conio.h>
#include "Textbuffer.hpp"

using namespace std;

const unsigned width = 50;
const unsigned height = 10;


const char player = 'P';

void SetNewPos(int input, unsigned * xPos, unsigned * yPos) {
    switch (input) {
    // w
    case 119:
        if (*yPos > 0)
            (*yPos)--;
        break;
        // a
    case 97:
        if (*xPos > 0)
            (*xPos)--;

        break;
        // s
    case 115:
        if (*yPos < height-1)
            (*yPos)++;
        break;
        // d
    case 100:
        if (*xPos < width-1)
            (*xPos)++;
        break;
    default:
        break;
    }
}

int main()
{
    unsigned currentXPos = 0;
    unsigned currentYPos = 0;
    int inputChar = 0;

    TextBuffer * tb = new TextBuffer(width,height);
    tb->SetChar(0,0,player);

 /*   tb->SetChar(15,2,'O');
    tb->SetChar(12,4,'O');
    tb->SetChar(5,7,'O');
    tb->SetChar(25,9,'O');
    tb->SetChar(10,3,'O'); */

    while (inputChar != 27) {

        std::system("cls");
        //tb->field = map1.Design_ptr;
        tb->Render();

        inputChar = _getch();

        if (inputChar == 119 || inputChar == 97 || inputChar == 115 || inputChar == 100)
        {
            /* unsigned newXPos = currentXPos;
            unsigned newYPos = currentYPos;

            SetNewPos(inputChar, &newXPos, &newYPos);
            char test = tb->GetChar(newXPos, newYPos);
            if (test == '\0'){
                tb->SetChar(currentXPos,currentYPos, ' ');
                currentXPos = newXPos;
                currentYPos = newYPos;
                tb->SetChar(currentXPos,currentYPos, player);
            }*/
            tb->SetChar(currentXPos,currentYPos, ' ');
            SetNewPos(inputChar, &currentXPos, &currentYPos);
            tb->SetChar(currentXPos,currentYPos, player);
        }

    }


    return 0;
}
