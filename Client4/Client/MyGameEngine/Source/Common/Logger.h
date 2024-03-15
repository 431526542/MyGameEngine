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
	static VOID PrintLog(const WCHAR* fmt, ...); //���� ��ȿ ���� �Լ�
	static std::wstring LogDirectory();
	static std::wstring LogFile();
};