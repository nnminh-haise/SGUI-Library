#include "SGUI.h"

#include <iostream>

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

            /*while (this->_itemQueue.empty() == false) {
                SGUI::Item& currentItem = this->_itemQueue.front();
                currentItem.Run();
            }*/

            SGUe::TextAt(100, 100, "hello");

            setvisualpage(getactivepage());
            clearmouseclick(VK_LBUTTON);
            clearmouseclick(VK_RBUTTON);
        }
    }
}

void SGUI::Window::PushItem(SGUI::Item& item)
{
    this->_itemQueue.push(item);
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

void SGUI::Item::Run()
{
    outtextxy(100, 100, (char*)"hi");
}
