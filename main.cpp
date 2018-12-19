#include <iostream>
#include <conio.h>
#include "Textbuffer.hpp"
#include <windows.h>
#include <fstream>

using namespace std;

const unsigned width = 51;
const unsigned height = 15;


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
    std::ifstream in("C:\\Users\\Steve\\Documents\\Uni\\Git\\build-ConsolenSpiel-MinGW-Debug\\debug\\map.txt");
    std::string contents((std::istreambuf_iterator<char>(in)),
                         std::istreambuf_iterator<char>());

    char * map = new char[contents.length()];
    strcpy(map, contents.c_str());

    unsigned currentXPos = 0;
    unsigned currentYPos = 0;
    int inputChar = 0;

    TextBuffer * tb = new TextBuffer(width,height, map);
    tb->SetChar(1,1,player);

    while (inputChar != 27) {

        std::system("cls");
        //tb->field = map1.Design_ptr;
        tb->Render();
        if(_kbhit())
        {
            inputChar = _getch();

            if (inputChar == 119 || inputChar == 97 || inputChar == 115 || inputChar == 100)
            {
                unsigned newXPos = currentXPos;
                unsigned newYPos = currentYPos;

                SetNewPos(inputChar, &newXPos, &newYPos);
                char test = tb->GetChar(newXPos, newYPos);
                if (test == '\0'){
                    tb->SetChar(currentXPos,currentYPos, ' ');
                    currentXPos = newXPos;
                    currentYPos = newYPos;
                    tb->SetChar(currentXPos,currentYPos, player);
                }
                /*tb->SetChar(currentXPos,currentYPos, ' ');
                SetNewPos(inputChar, &currentXPos, &currentYPos);
                tb->SetChar(currentXPos,currentYPos, player);*/
            }
        }

        Sleep(300);

    }


    return 0;
}
