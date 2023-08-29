#include "SGUI.h"

SGUI::Window::Window()
{
    this->_id = initwindow(1000, 1000, "SGUI Default Window");
}

SGUI::Window::~Window()
{
    closegraph(this->_id);
}

void SGUI::Window::Main()
{
    while (this->_closeBtn == false)
    {
        while (!kbhit() && this->_closeBtn == false)
        {
            setactivepage(1 - getactivepage());


            setvisualpage(getactivepage());
            clearmouseclick(VK_LBUTTON);
            clearmouseclick(VK_RBUTTON);
        }
    }
}

void SGUI::Core::PushWindow(SGUI::Window& newWindow)
{
    this->_windowStack.push(newWindow);
}

void SGUI::Core::RunCore()
{
    while (!this->_windowStack.empty())
    {
        SGUI::Window& topWindow = this->_windowStack.top();
        topWindow.Main();
    }
}

void SGUI::SGUe::Text(std::string message)
{
    outtext((char*)message.c_str());
}

void SGUI::SGUe::TextAt(int x, int y, std::string message)
{
    outtextxy(x, y, (char*)message.c_str());
}

void SGUI::Item::Activate()
{
    this->_status = true;
}

void SGUI::Item::Deactivate()
{
    this->_status = false;
}

bool SGUI::Item::Status()
{
    return this->_status;
}
