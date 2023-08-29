
#include <iostream>
#include "SGUILib/SGUI.h"


//class MessageBx : public SGUI::Item
//{
//public:
//    void Run() override {
//        SGUe::TextAt(100, 100, "hello");
//    }
//};

int main()
{
    std::cout << "GUI Lib Dev!\n";
 
    //SGUI::Item msbx;

    SGUI::Window wind;
    //wind.PushItem(msbx);

    SGUI::Core appCore;
    appCore.PushWindow(wind);

    appCore.RunCore();

    return 0;
}
