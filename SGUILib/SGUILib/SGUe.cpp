#include "SGUe.h"
#include "graphics.h"

void SGUe::Text(std::string message)
{
    outtext((char*)message.c_str());
}

void SGUe::TextAt(int x, int y, std::string message)
{
    outtextxy(x, y, (char*)message.c_str());
}
