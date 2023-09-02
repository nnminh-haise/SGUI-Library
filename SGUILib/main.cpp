
#include <iostream>
#include "SGUILib/SGUI.h"
#include "PrintHelloWorldApp/HelloWorldApp.h"

int main()
{
    SGUI::Core appCore;

    HELLO_WORLD_APP::HelloWorldApp greetingApp;
    greetingApp.Main();

    appCore.PushLayer(std::make_shared<HELLO_WORLD_APP::HelloWorldApp>(greetingApp));

    appCore.RunCore();

    return 0;
}
