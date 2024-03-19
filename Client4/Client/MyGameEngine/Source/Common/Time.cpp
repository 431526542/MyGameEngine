#include "MyGameEngine.h"
#include <ctime>
#include <sstream>
#include <iomanip>

//Get time in format '00:00:00
//stripped = 000000
std::wstring Time::GetTime(BOOL stripped)
{
	//<ctime> �� ����Ͽ� �ð��� ������ �ð��� string ���� ���´�.
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now); 
	std::wstringstream wss;
	wss << std::put_time(&ltm, L"%T");

	std::wstring timeString = wss.str();

	if (stripped)
	{
		std::wstring chars = L":";
		for (WCHAR c : chars)
		{
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}
	return timeString;
}
std::wstring Time::GetData(BOOL stripped)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	std::wstringstream wss;
	wss << std::put_time(&ltm, L"%d/%m/%y");

	std::wstring timeString = wss.str();

	if (stripped)
	{
		std::wstring chars = L"/";
		for (WCHAR c : chars)
		{
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}
	return timeString;
}

//Get data time in format '00/00/00 00:00:00'
//Stripped = 0000000000
std::wstring Time::GetDateTimeString(BOOL stripped)
{
	std::wstring timeString = GetData(stripped) + L" " + GetTime(stripped);
	if (stripped)
	{
		std::wstring chars = L" ";
		for (WCHAR c : chars)
		{
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}

	return timeString;
}