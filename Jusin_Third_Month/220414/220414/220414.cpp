// 220414.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//
// Window 초기화 화면 (C언어 기반)
// 여러개의 프로그램을 동시에 돌림(멀티 프로세스)
// 함수 호출 규약에 대해 공부하기 (soen.kr)

#include "stdafx.h"
#include "220414.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다. (윈도우 창을 업로드할때 윈도우 창의 데이터를 저장하는 부분)
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass(HINSTANCE hInstance); // 창생성과 관련된 디자인
BOOL                InitInstance(HINSTANCE, int);		  // 실질적으로 창을 생성하는 함수
// 윈도우가 호출하는 함수 CALLBACK
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);  // 윈도우 프로시저 윈도우 메시지 처리 함수
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// 메인 함수
// 무조건 모든 문자열이 2바이트 (유니코드만 쓴다.) (wchar_t)
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY220414, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

	// 단축키
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY220414));

	// 메세지 동시성
    MSG msg;

    // 기본 메시지 루프입니다.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) // 단축키 처리
        {
            TranslateMessage(&msg); // 키보드
            DispatchMessage(&msg);  // 시스템 메세지 Winproc
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
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
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   RECT rc{ 0,0,800,600 };

   // 핸들
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, // 출력하고자 하는 창의 left 와 top의 좌표
	   rc.right - rc.left,
	   rc.bottom - rc.top, // 출력하고자 하는 창의 가로 세로 사이즈 
	   nullptr, nullptr, hInstance, nullptr);

   // 리소스(프로세스, 파일, 스레드)

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd); // 창을 갱신한다.

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적:  주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

std::list<RECT> EnemyRECT;
std::list<RECT> listRECT;
RECT rc{ 100,100,200,200 };

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) // 파라미터 W 키보드 L 마우스
{
    switch (message)
    {
	case WM_CREATE:
		// 타이머를 설치하는 함수 , 윈도우 핸들, 타이머의 id, 타이머 주기, null인경우 wm_timer를 실행
		SetTimer(hWnd, 0, 0, 0);
		
		break;

	case WM_TIMER:
		// 윈도우 화면 갱신 함수, 함수 호출시 WM_PAINT 메시지 발생
		// 윈도우 핸들, 갱신할 범위 지정, null인 경우 전체, false 냐 true에 따라 상태변경
		// false 인경우 새로 그리는 부분만 갱신, true인 경우 그려져있지 않는 모든 영역도 갱신
		InvalidateRect(hWnd, 0, true);
		
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다.
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
    case WM_PAINT: // 그리기
        {
            PAINTSTRUCT ps;

            HDC hdc = BeginPaint(hWnd, &ps);

			// 출력에 대한 정보를 가진 데이터 (도화지)
			// 커널 유저 DVI 이중 위는 DVI
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.

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

// 정보 대화 상자의 메시지 처리기입니다.
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
