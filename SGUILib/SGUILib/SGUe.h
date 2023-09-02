#pragma once

#ifndef __SGUI_LIB_ELEMENTS__
#define __SGUI_LIB_ELEMENTS__

#include <string>
#include "graphics.h"
#include <iostream>

namespace SGUe {
	struct Vec2
	{
		Vec2();

		Vec2(int x, int y);

		int x{};
		int y{};
	};

	struct Vec4
	{
		Vec4();

		Vec4(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY);

		Vec4(SGUe::Vec2 topLeft, SGUe::Vec2 bottomRight);

		Vec2 topLeft{};
		Vec2 bottomRight{};
	};

	class TextBox
	{
	public:
		TextBox();

		TextBox(std::string text);

		TextBox(std::string text, SGUe::Vec4 coordinates);

		TextBox(std::string text, SGUe::Vec4 coordinates, int textColor);

		TextBox(std::string text, SGUe::Vec4 coordinates, int textColor, int backgroundColor);

		void SetText(std::string text);

		std::string GetText();

		void SetCoordinates(SGUe::Vec4 coordinates);

		SGUe::Vec4 GetCoordinates();

		void SetBackgroundColor(int backgroundColor);

		int GetBackgroundColor();

		void SetTextColor(int textColor);

		int GetTextColor();

	private:
		SGUe::Vec4 _coordinates;

		std::string _text;

		int _backgroundColor = WHITE;

		int _textColor = BLACK;
	};
};

#endif // !__SGUI_LIB_ELEMENTS__
