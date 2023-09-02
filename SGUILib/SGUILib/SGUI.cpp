#include "SGUI.h"

#include <iostream>

bool SGUI::Layer::Run()
{
    try
    {
        std::shared_ptr<SGUI::Item> currentItem = nullptr;
        while (this->_hotExit == false)
        {
            while (this->_items.empty() == false && !kbhit() && this->_hotExit == false)
            {
                setactivepage(1 - getactivepage());

                currentItem = this->_items.front();
                currentItem->Run();

                setvisualpage(getactivepage());
                clearmouseclick(VK_LBUTTON);
                clearmouseclick(VK_RBUTTON);
            }

            char key = getch();
            if (key == 27) {
                this->_hotExit = true;
                return false;
            }
        }        
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << "\n";
        return false;
    }

    return true;
}

void SGUI::Core::PushLayer(std::shared_ptr<SGUI::Layer> layer)
{
    this->_layers.push(layer);
}

void SGUI::Core::RunCore()
{
    std::shared_ptr<SGUI::Layer> topLayer = nullptr;
    while (!this->_layers.empty())
    {
        topLayer = this->_layers.top();
        if (!topLayer->Run())
        {
            break;
        }
        this->_layers.pop();
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
