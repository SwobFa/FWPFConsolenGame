#ifndef TEXTBUFFER_HPP
#define TEXTBUFFER_HPP

class TextBuffer
{

    unsigned width, height;
public:
    char * field = nullptr;
    TextBuffer(unsigned width, unsigned height);
    ~TextBuffer();
    void SetChar(unsigned x, unsigned y, char character);
    char GetChar(unsigned x, unsigned y);
    void Render();
};

#endif // TEXTBUFFER_HPP
