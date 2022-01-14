#pragma once

#include <windows.h>

namespace keyboard
{
		void setHook();

		void getState(BYTE* state) noexcept;
		
		bool isControlDown() noexcept;

		constexpr bool isDown(SHORT keystatus) noexcept;
};
