#include <Windows.h>

#define MAX_NAME_STRING 265 // WindowClass�� �ִ� ���̸� ������ ���´�.
#define HInstance() GetModuleHandle(NULL)

// �ؿ� wcex.lpszClassName, ������ �̸��� ������ ���� �����̴�. ������ ���� ������ ������ �̸� ���濡 ����ϵ��� �Ұ�
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

	//������ ���ɼ��� ���� ���� ����
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	//�̹� ������Ʈ���� ���� �������� �ʴ� ����
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); //�Ϲ������� �� ���ִ� Ŀ���� ����
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH); //����� ���� ������� ����

	//�̹� ������Ʈ���� ������ �Ͽ� ��ȭ�� �ֱ� ���� ����
	wcex.hIcon = LoadIcon(0, IDI_APPLICATION); //idi ���� ���α׷��� �Է��ϴ� ���� �� �������� �ٽ� ���ƿ��ڴ�.
	wcex.hIconSm = LoadIcon(0, IDI_APPLICATION); //..
	wcex.lpszClassName = WindowClass;
	wcex.lpszMenuName = nullptr;
	wcex.hInstance = HInstance(); //���� �����ϴ� �ν��Ͻ��� ã�´�.
	wcex.lpfnWndProc = DefWindowProc; //â�� ��� �۵������� ���� ��ħ ��, ũ�� ���� �� �ݰų� �����ϴ� Ư�� ���� �����ϵ��� ������
	RegisterClassEx(&wcex);//�������� Ŭ���� ���, ����

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