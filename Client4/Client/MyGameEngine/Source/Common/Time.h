#pragma once
#include <string>

namespace Time
{
	//Get current time in string format
	std::wstring MyGameEngine_API GetTime(BOOL stripped = FALSE);
	//Get current data in string format
	std::wstring MyGameEngine_API GetData(BOOL stripped = FALSE);
	//Get current data and time in string format
	std::wstring MyGameEngine_API GetDateTimeString(BOOL stripped = FALSE);
}