#include "pch.h"
#include "Application.h"
#include "Platform/WIN32/WinEntry.h"

ENTRYAPP(Application)

Application::Application()
{
}

Application::~Application()
{
}

VOID Application::SetupPerGameSettings()
{
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
}

VOID Application::Initialize()
{
	Logger::PrintDebugSeperator();
	Logger::PrintLog(L"Application Starting...\n");
	Logger::PrintLog(L"Game Name: %s\n", PerGameSettings::GameName());
	Logger::PrintLog(L"Boot Time: %s\n", Time::GetDateTimeString().c_str());
	Logger::PrintDebugSeperator();

	Logger::StartMTail();
}

VOID Application::Update()
{
	MessageBox(0, L"Loop", 0, 0);
}
