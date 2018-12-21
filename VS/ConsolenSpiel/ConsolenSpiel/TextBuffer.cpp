#include "pch.h"
#include <iostream>
#include "TextBuffer.h"
#include <sstream>
#include <Windows.h>

using namespace std;

TextBuffer::TextBuffer(unsigned width, unsigned height, char * map) : width(width), height(height), field(map) {
}

TextBuffer::~TextBuffer() {
	delete[] field;
}

void TextBuffer::SetChar(unsigned x, unsigned y, char character) {
	unsigned position = y * width + x;
	field[position] = character;
}

char TextBuffer::GetChar(unsigned x, unsigned y) {
	unsigned position = y * width + x;
	if (position < (height * width))
		return field[position];
	return ' ';
}

void TextBuffer::Render() {
	COORD coord = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	unsigned length = (width*height);
	stringstream ss;
	for (unsigned i = 0; i < length; i++)
	{
		if ((i+1) % width == 0)
		{
			cout << ss.str();
			ss.str("");
			ss.clear();
		}
		ss << field[i];
		//cout << field[i];
	}
}

