#ifndef TEXTBUFFER_H
#define TEXTBUFFER_H

class TextBuffer
{
public:
	short Width, Height;

	char * field = nullptr;
	TextBuffer(short const & width, short const & height, char * map);
	~TextBuffer();
	void SetChar(short const & x, short const & y, char const & character);
	char GetChar(short const & x, short const & y);
	void SetAllChar(char const & character);
	void Render();
};

#endif // TEXTBUFFER_H
