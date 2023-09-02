#pragma once

#ifndef __HELLO_WORLD_APP__
#define __HELLO_WORLD_APP__

#include "../SGUILib/SGUI.h"
#include <string>

namespace HELLO_WORLD_APP {

	class HelloCard : public SGUI::Item
	{
	public:
		HelloCard();

		HelloCard(std::string greeting);

		void SetGreets(std::string greeting);

		void Initialize();

		void Run() override;

	public:
		using::SGUI::Item::Activate;

		using::SGUI::Item::Deactivate;

		using::SGUI::Item::Status;

	private:
		using::SGUI::Item::_status;

		std::string _greeting;

		SGUe::TextBox _greetingTBX;
	};

	class HelloWorldApp : public SGUI::Layer
	{
	public:
		HelloWorldApp();

		~HelloWorldApp();

		void Main() override;

	public:
		using SGUI::Layer::Run;

	private:
		using SGUI::Layer::_id;

		using SGUI::Layer::_items;

		using SGUI::Layer::_hotExit;

	private:
		HelloCard _greetingCard;
	};
}

#endif // !__HELLO_WORLD_APP__
