#pragma once

#include "Platform/WIN32/iApplication.h"

class Application : public IApplication
{

public:
	Application();
	~Application();

public:
	VOID Initialize();
	VOID Update();
};