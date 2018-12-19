#include <iostream>
#include "Textbuffer.hpp"

using namespace std;

TextBuffer::TextBuffer(unsigned width, unsigned height, MapBase * map) : field(map->Design_ptr), width(width), height(height) {
}

TextBuffer::~TextBuffer() {
    delete [] field;
}

void TextBuffer::SetChar(unsigned x, unsigned y, char character) {
    unsigned position =  y * width + x;
    field[position] = character;
}

char TextBuffer::GetChar(unsigned x, unsigned y) {
    unsigned position =  y * width + x;
    if (position < (height * width))
        return field[position];
    return ' ';
}

void TextBuffer::Render() {
    unsigned length = (width*height);

    for(unsigned i = 0; i < length; i++)
    {
        cout << field[i];
        if ((i + 1) % width == 0) {
            cout << endl;
        }
    }
}

