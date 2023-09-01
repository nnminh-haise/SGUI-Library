
#include <iostream>
#include "SGUILib/SGUI.h"


class MessageBx : public SGUI::Item
{
public:
    void Run() override {
        SGUe::TextAt(100, 100, "hello msbx");
    }
};

int main()
{
    std::cout << "GUI Lib Dev!\n";
 
    MessageBx msbx;

    SGUI::Window wind;
    wind.PushItem(std::make_shared<MessageBx>(msbx));

    SGUI::Core appCore;
    appCore.PushWindow(wind);

    appCore.RunCore();

    return 0;
}
