#pragma once

#ifndef __SGUI_LIB_METHODS__
#define __SGUI_LIB_METHODS__

#include <string>
#include "SGUe.h"
#include "graphics.h"

namespace SGUm {
	void Text(std::string message);

	void Text(std::string message, int x, int y);

	void Text(std::string message, SGUe::Vec2 topLeft);

	void Draw(SGUe::Vec4 rec);

	void Draw(SGUe::TextBox textBox);
};

#endif // !__SGUI_LIB_METHODS__
