#include "SGUe.h"

SGUe::Vec2::Vec2()
    : x(0), y(0)
{
}

SGUe::Vec2::Vec2(int x, int y)
    : x(x), y(y)
{
}

SGUe::Vec4::Vec4()
    : topLeft(SGUe::Vec2()), bottomRight(SGUe::Vec2())
{
}

SGUe::Vec4::Vec4(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY)
    : topLeft(SGUe::Vec2(topLeftX, topLeftY)), bottomRight(SGUe::Vec2(bottomRightX, bottomRightY))
{
}

SGUe::Vec4::Vec4(SGUe::Vec2 ab, SGUe::Vec2 cd)
    : topLeft(ab), bottomRight(cd)
{
}

SGUe::TextBox::TextBox()
    : _coordinates(SGUe::Vec4(10, 10, 100, 100)), _text("Text box"), _backgroundColor(WHITE), _textColor(BLACK)
{
}

SGUe::TextBox::TextBox(std::string text)
    : _coordinates(SGUe::Vec4(10, 10, 100, 100)), _text(text), _backgroundColor(WHITE), _textColor(BLACK)
{
}

SGUe::TextBox::TextBox(std::string text, SGUe::Vec4 coordinates)
    : _coordinates(coordinates), _text(text), _backgroundColor(WHITE), _textColor(BLACK)
{
}

SGUe::TextBox::TextBox(std::string text, SGUe::Vec4 coordinates, int textColor)
    : _coordinates(coordinates), _text(text), _backgroundColor(WHITE), _textColor(textColor)
{
}

SGUe::TextBox::TextBox(std::string text, SGUe::Vec4 coordinates, int textColor, int backgroundColor)
    : _coordinates(coordinates), _text(text), _backgroundColor(backgroundColor), _textColor(textColor)
{
}

void SGUe::TextBox::SetText(std::string text)
{
    this->_text = text;
}

std::string SGUe::TextBox::GetText()
{
    return this->_text;
}

void SGUe::TextBox::SetCoordinates(SGUe::Vec4 coordinates)
{
    this->_coordinates = coordinates;
}

SGUe::Vec4 SGUe::TextBox::GetCoordinates()
{
    return this->_coordinates;
}

void SGUe::TextBox::SetBackgroundColor(int backgroundColor)
{
    this->_backgroundColor = backgroundColor;
}

int SGUe::TextBox::GetBackgroundColor()
{
    return this->_backgroundColor;
}

void SGUe::TextBox::SetTextColor(int textColor)
{
    this->_textColor = textColor;
}

int SGUe::TextBox::GetTextColor()
{
    return this->_textColor;
}
