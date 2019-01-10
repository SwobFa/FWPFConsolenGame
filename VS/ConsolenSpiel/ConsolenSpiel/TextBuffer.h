#ifndef TEXTBUFFER_H
#define TEXTBUFFER_H

class TextBuffer
{
public:
	short Width, Height;

	char * field = nullptr;
	TextBuffer(short width, short height, char * map);
	~TextBuffer();
	void SetChar(short x, short y, char character);
	char GetChar(short x, short y);
	void Render();
};

#endif // TEXTBUFFER_H
