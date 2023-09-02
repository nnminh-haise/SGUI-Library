#include "SGUm.h"

void SGUm::Text(std::string message)
{
    outtext((char*)message.c_str());
}

void SGUm::Text(std::string message, int x, int y)
{
    outtextxy(x, y, (char*)message.c_str());
}

void SGUm::Text(std::string message, SGUe::Vec2 topLeft)
{
    outtextxy(topLeft.x, topLeft.y, (char*)message.c_str());
}


void SGUm::Draw(SGUe::Vec4 vec4)
{
    bar(vec4.topLeft.x, vec4.topLeft.y,
        vec4.bottomRight.x, vec4.bottomRight.y);
}

void SGUm::Draw(SGUe::TextBox textBox)
{
    setfillstyle(SOLID_FILL, textBox.GetBackgroundColor());
    SGUm::Draw(textBox.GetCoordinates());
    setcolor(textBox.GetTextColor());
    setbkcolor(textBox.GetBackgroundColor());
    SGUm::Text(textBox.GetText(), textBox.GetCoordinates().topLeft);
}

