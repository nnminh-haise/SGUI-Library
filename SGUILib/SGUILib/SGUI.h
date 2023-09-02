#pragma once

#ifndef __SGUI_LIB__
#define __SGUI_LIB__

#include "graphics.h"
#include "SGUe.h"
#include "SGUm.h"
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

	class Layer
	{
	public:
		virtual void Main() = 0;

		bool Run();

	public:
		int _id = -1;

		bool _hotExit = false;

		std::queue<std::shared_ptr<SGUI::Item>> _items{};
	};

	class Core
	{
	public:
		void PushLayer(std::shared_ptr<SGUI::Layer> layer);

		void RunCore();

	private:
		std::stack<std::shared_ptr<SGUI::Layer>> _layers;
	};
}

#endif // !__SGUI_LIB__

