#include <Windows.h>

#define MAX_NAME_STRING 265 // WindowClass의 최대 길이를 설정해 놓는다.
#define HInstance() GetModuleHandle(NULL)

// 밑에 wcex.lpszClassName, 윈도우 이름을 설정을 위한 변수이다. 다음과 같이 설정해 윈도우 이름 변경에 사용하도록 할것
WCHAR		WindowClass[MAX_NAME_STRING]; 
WCHAR		WindowTitle[MAX_NAME_STRING];

INT			WindowWidth;
INT			WindowHeight;

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	//Initialize Global Variables
	wcscpy_s(WindowClass, TEXT("TutorialOneClass"));
	wcscpy_s(WindowTitle, TEXT("Our First Window"));
	WindowWidth = 1366;
	WindowHeight = 768;
	//Create Window Class

	WNDCLASSEX wcex;

	//변경할 가능성이 거의 없는 문법
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	//이번 프로젝트에서 거의 변경하지 않는 문법
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); //일반적으로 볼 수있는 커서로 설정
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH); //배경은 현재 흰색으로 설정

	//이번 프로젝트에서 변경을 하여 변화를 주기 위한 문법
	wcex.hIcon = LoadIcon(0, IDI_APPLICATION); //idi 응용 프로그램을 입력하는 순간 이 내용으로 다시 돌아오겠다.
	wcex.hIconSm = LoadIcon(0, IDI_APPLICATION); //..
	wcex.lpszClassName = WindowClass;
	wcex.lpszMenuName = nullptr;
	wcex.hInstance = HInstance(); //지금 실행하는 인스턴스를 찾는다.
	wcex.lpfnWndProc = DefWindowProc; //창이 어떻게 작동할지에 대한 지침 즉, 크기 변경 및 닫거나 종료하는 특정 명열을 포함하도록 재정의
	RegisterClassEx(&wcex);//레지스터 클래스 등록, 예시

	//Create and Display our Window
	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);
	if (!hWnd)
	{
		MessageBox(0, L"Failed to Create Window!.", 0, 0);
		return 0;
	}

	ShowWindow(hWnd, SW_SHOW);

	//Listen for Message events

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}