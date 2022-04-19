// 220414_shoot.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "220414_shoot.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

template<typename T>
void List_Release(T& _list)
{
	for (auto& iter : _list)
	{
		if (iter)
		{
			delete iter;
			iter = nullptr;
		}
	}
}

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
    LoadStringW(hInstance, IDC_MY220414_SHOOT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY220414_SHOOT));

    MSG msg;

    // �⺻ �޽��� �����Դϴ�.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY220414_SHOOT));
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

std::list<CMonster*> listMonster;

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

   for (int i = 0; i < 3; ++i)
   {
	   listMonster.push_back(new CMonster({ 575 - (i * 200), 50, 650 - (i * 200), 100 }));
   }

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

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

RECT rc{300, 450, 400, 550 };
std::list<CBullet*> listBullet;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.
			Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

			for (auto iter = listMonster.begin(); iter != listMonster.end(); ++iter)
			{
				RECT Mrc = (*iter)->Get_RECT();
				Ellipse(hdc, Mrc.left, Mrc.top, Mrc.right, Mrc.bottom);
			}


			for (auto iter = listBullet.begin(); iter != listBullet.end(); ++iter)
			{
				RECT Brc = (*iter)->Get_RECT();

				if ((*iter)->Hit_Monster(listMonster))
				{
					iter = listBullet.erase(iter);
					if (iter == listBullet.end())
					{
						break;
					}
				}
				else
				{
					Ellipse(hdc, Brc.left, Brc.top, Brc.right, Brc.bottom);
					(*iter)->shoot();
				}
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
		case VK_W:
			listBullet.push_back(new CBullet({ rc.left + 25,rc.top + 25, rc.right - 25,rc.bottom - 25 }, Bullet_UP));
			break;
		case VK_A:
			listBullet.push_back(new CBullet({ rc.left + 25,rc.top + 25, rc.right - 25,rc.bottom - 25 }, Bullet_Left));
			break;
		case VK_S:
			listBullet.push_back(new CBullet({ rc.left + 25,rc.top + 25, rc.right - 25,rc.bottom - 25 }, Bullet_Down));
			break;
		case VK_D:
			listBullet.push_back(new CBullet({ rc.left + 25,rc.top + 25, rc.right - 25,rc.bottom - 25 }, Bullet_Right));
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
		List_Release(listBullet);
		List_Release(listMonster);
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
