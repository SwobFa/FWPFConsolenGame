#include "pch.h"
#include <iostream>
#include "TextBuffer.h"
#include <sstream>
#include <Windows.h>

using namespace std;

TextBuffer::TextBuffer(short const & width, short const & height, char * map) : Width(width), Height(height), field(map) {
}

TextBuffer::~TextBuffer() {

}

void TextBuffer::SetChar(short const & x, short const & y, char const & character) {
	short position = y * Width + x;
	field[position] = character;
}

char TextBuffer::GetChar(short const & x, short const & y) {
	short const position = y * Width + x;
	if (position < (Height * Width))
		return field[position];
	return ' ';
}

void TextBuffer::SetAllChar(char const & character)
{
	short length = (Width*Height);
	for (short i = 0; i < length; i++)
	{
		field[i] = character;
	}
}

void TextBuffer::Render() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });

	short length = (Width*Height);
	stringstream ss;
	for (short i = 0; i < length; i++)
	{
		if ((i+1) % Width == 0)
		{
			cout << ss.str();
			ss.str("");
		}
		ss << field[i];
	}
}

