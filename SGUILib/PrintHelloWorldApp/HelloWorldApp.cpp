
#include "HelloWorldApp.h"

HELLO_WORLD_APP::HelloWorldApp::HelloWorldApp()
{
	std::cerr << "Creating Hello world app!\n";
	
	this->_id = initwindow(1000, 1000, "Hello App Using SGUI");
}

HELLO_WORLD_APP::HelloWorldApp::~HelloWorldApp()
{
	std::cerr << "Destructing Hello world app!\n";

	closegraph(this->_id);
}

void HELLO_WORLD_APP::HelloWorldApp::Main()
{
	this->_greetingCard.Initialize();
	this->_greetingCard.SetGreets("Hello, my name is Haise");
	
	this->_items.push(std::make_shared<HelloCard>(this->_greetingCard));
}

HELLO_WORLD_APP::HelloCard::HelloCard()
	: _greeting("Hello world! This is a default greeting")
{
}

HELLO_WORLD_APP::HelloCard::HelloCard(std::string greeting)
	: _greeting(greeting)
{
}

void HELLO_WORLD_APP::HelloCard::SetGreets(std::string greeting)
{
	this->_greeting = greeting;
	this->_greetingTBX.SetText(greeting);
}

void HELLO_WORLD_APP::HelloCard::Initialize()
{
	this->_greetingTBX = SGUe::TextBox(
		this->_greeting, 
		SGUe::Vec4(100, 100, 500, 200), 
		RED,
		WHITE
	);
}

void HELLO_WORLD_APP::HelloCard::Run()
{
	SGUm::Draw(this->_greetingTBX);
}
