#pragma once

#include <string>

class MyGameEngine_API Logger
{
private:
	static Logger* inst;
public:
	static Logger* Instance() { return inst; }
public:
	Logger();
	~Logger();

	//print to Log File
	static VOID PrintLog(const WCHAR* fmt, ...); //정적 무효 유형 함수
	static std::wstring LogDirectory();
	static std::wstring LogFile();
};