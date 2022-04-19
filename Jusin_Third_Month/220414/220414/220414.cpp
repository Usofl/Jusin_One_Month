// 220414.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//
// Window �ʱ�ȭ ȭ�� (C��� ���)
// �������� ���α׷��� ���ÿ� ����(��Ƽ ���μ���)
// �Լ� ȣ�� �Ծ࿡ ���� �����ϱ� (soen.kr)

#include "stdafx.h"
#include "220414.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�. (������ â�� ���ε��Ҷ� ������ â�� �����͸� �����ϴ� �κ�)
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM                MyRegisterClass(HINSTANCE hInstance); // â������ ���õ� ������
BOOL                InitInstance(HINSTANCE, int);		  // ���������� â�� �����ϴ� �Լ�
// �����찡 ȣ���ϴ� �Լ� CALLBACK
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);  // ������ ���ν��� ������ �޽��� ó�� �Լ�
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// ���� �Լ�
// ������ ��� ���ڿ��� 2����Ʈ (�����ڵ常 ����.) (wchar_t)
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY220414, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

	// ����Ű
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY220414));

	// �޼��� ���ü�
    MSG msg;

    // �⺻ �޽��� �����Դϴ�.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) // ����Ű ó��
        {
            TranslateMessage(&msg); // Ű����
            DispatchMessage(&msg);  // �ý��� �޼��� Winproc
        }
    }

    return (int) msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY220414));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   RECT rc{ 0,0,800,600 };

   // �ڵ�
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, // ����ϰ��� �ϴ� â�� left �� top�� ��ǥ
	   rc.right - rc.left,
	   rc.bottom - rc.top, // ����ϰ��� �ϴ� â�� ���� ���� ������ 
	   nullptr, nullptr, hInstance, nullptr);

   // ���ҽ�(���μ���, ����, ������)

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd); // â�� �����Ѵ�.

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//

std::list<RECT> EnemyRECT;
std::list<RECT> listRECT;
RECT rc{ 100,100,200,200 };

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) // �Ķ���� W Ű���� L ���콺
{
    switch (message)
    {
	case WM_CREATE:
		// Ÿ�̸Ӹ� ��ġ�ϴ� �Լ� , ������ �ڵ�, Ÿ�̸��� id, Ÿ�̸� �ֱ�, null�ΰ�� wm_timer�� ����
		SetTimer(hWnd, 0, 0, 0);
		
		break;

	case WM_TIMER:
		// ������ ȭ�� ���� �Լ�, �Լ� ȣ��� WM_PAINT �޽��� �߻�
		// ������ �ڵ�, ������ ���� ����, null�� ��� ��ü, false �� true�� ���� ���º���
		// false �ΰ�� ���� �׸��� �κи� ����, true�� ��� �׷������� �ʴ� ��� ������ ����
		InvalidateRect(hWnd, 0, true);
		
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �޴� ������ ���� �м��մϴ�.
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT: // �׸���
        {
            PAINTSTRUCT ps;

            HDC hdc = BeginPaint(hWnd, &ps);

			// ��¿� ���� ������ ���� ������ (��ȭ��)
			// Ŀ�� ���� DVI ���� ���� DVI
            // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.

			//MoveToEx(hdc, 100, 100, nullptr);

			//LineTo(hdc, 200, 100);
			//LineTo(hdc, 200, 200);
			//LineTo(hdc, 100, 200);
			//LineTo(hdc, 100, 100);

			//Ellipse(hdc, 300, 300, 400, 400);

			Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

			for (auto iter = listRECT.begin(); iter != listRECT.end(); ++iter)
			{
				Rectangle(hdc, iter->left, iter->top, iter->right, iter->bottom);

				iter->top -= 10;
				iter->bottom -= 10;
			}

            EndPaint(hWnd, &ps);
        }
        break;
	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_RIGHT:
			rc.left += 10;
			rc.right += 10;
			break;
		case VK_LEFT:
			rc.left -= 10;
			rc.right -= 10;
			break;
		case VK_UP:
			rc.top -= 10;
			rc.bottom -= 10;
			break;
		case VK_DOWN:
			rc.top += 10;
			rc.bottom += 10;
			break;
		case VK_SPACE:
			listRECT.push_back(rc);
			break;
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;

		default:
			break;
		}

		break;
    case WM_DESTROY:
		KillTimer(hWnd, 0);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
