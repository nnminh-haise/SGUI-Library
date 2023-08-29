#pragma once

#ifndef __GUI_LIB__
#define __GUI_LIB__

#include "graphics.h"
#include <stack>
#include <queue>
#include <string>

namespace SGUI {
	namespace SGUe
	{
		void Text(std::string message);

		void TextAt(int x, int y, std::string message);
	};

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

	private:
		int _id = -1;

		bool _closeBtn = false;
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

