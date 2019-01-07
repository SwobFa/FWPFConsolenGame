#ifndef TEXTBUFFER_H
#define TEXTBUFFER_H

class TextBuffer
{
public:
	unsigned Width, Height;

	char * field = nullptr;
	TextBuffer(unsigned width, unsigned height, char * map);
	~TextBuffer();
	void SetChar(unsigned x, unsigned y, char character);
	char GetChar(unsigned x, unsigned y);
	void Render();
};

#endif // TEXTBUFFER_H
