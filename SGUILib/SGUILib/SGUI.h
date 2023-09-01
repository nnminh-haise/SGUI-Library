#pragma once

#ifndef __GUI_LIB__
#define __GUI_LIB__

#include "graphics.h"
#include "SGUe.h"
#include <stack>
#include <queue>
#include <string>
#pragma comment(lib, "graphics.lib")

namespace SGUI {
	class Item
	{
	public:
		void Activate();

		void Deactivate();

		bool Status();

		virtual void Run() = 0;

	public:
		bool _status = false;
	};

	class Window
	{
	public:
		Window();

		~Window();

		void Main();

		void PushItem(std::shared_ptr<SGUI::Item> item);

	private:
		int _id = -1;

		bool _closeBtn = false;

		std::queue<std::shared_ptr<SGUI::Item>> _itemQueue{};
	};

	class Core
	{
	public:
		void PushWindow(SGUI::Window& newWindow);

		void RunCore();

	private:
		std::stack<Window> _windowStack;
	};
}

#endif // !GUI_LIB

