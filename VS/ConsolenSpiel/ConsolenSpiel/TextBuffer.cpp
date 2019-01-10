#include "pch.h"
#include <iostream>
#include "TextBuffer.h"
#include <sstream>
#include <Windows.h>

using namespace std;

TextBuffer::TextBuffer(short width, short height, char * map) : Width(width), Height(height), field(map) {
}

TextBuffer::~TextBuffer() {
	delete[] field;
}

void TextBuffer::SetChar(short x, short y, char character) {
	short position = y * Width + x;
	field[position] = character;
}

char TextBuffer::GetChar(short x, short y) {
	short const position = y * Width + x;
	if (position < (Height * Width))
		return field[position];
	return ' ';
}

void TextBuffer::Render() {
	COORD const coord = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	short length = (Width*Height);
	stringstream ss;
	for (short i = 0; i < length; i++)
	{
		if ((i+1) % Width == 0)
		{
			cout << ss.str();
			ss.str("");
			ss.clear();
		}
		ss << field[i];
		//cout << field[i];
	}
}

