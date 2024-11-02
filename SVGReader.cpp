#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include <iostream>
#include "ShapeHeader/Shape.h"
#include "SVGParser.h"
using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")
// hello ming
VOID OnPaint(HDC hdc)
{
    bool isNameFile = false;
    SVGParser parser;
    parser.loadFile("sample.svg");
    Graphics graphics(hdc);

    xml_node<> *root_node = parser.getRootNode();

    for (xml_node<> *node = root_node->first_node(); node; node = node->next_sibling())
    {
        string shape = node->name();
        if (shape == "text")
        {
            if (!isNameFile)
                isNameFile = true;
            else
            {
                MyFigure::Text text(node, graphics);
                text.draw();
            }
        }
        else if (shape == "rect")
        {
            MyFigure::Rectangle rect(node, graphics);
            rect.draw();
        }
        else if (shape == "line")
        {
            MyFigure::Line line(node, graphics);
            line.draw();
        }
        else if (shape == "polygon")
        {
            MyFigure::Polygon polygon(node, graphics);
            polygon.draw();
        }
        else if (shape == "polyline")
        {
            MyFigure::Polyline polyline(node, graphics);
            polyline.draw();
        }
        else if (shape == "ellipse")
        {
            MyFigure::Ellipse ellipse(node, graphics);
            ellipse.draw();
        }
        else if (shape == "circle")
        {
            MyFigure::Circle circle(node, graphics);
            circle.draw();
        }
    }
}

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
    // Tạo cửa sổ console để xem output
    AllocConsole();
    FILE *stream;
    freopen_s(&stream, "CONOUT$", "w", stdout); // Chuyển hướng std::cout đến console
    freopen_s(&stream, "CONOUT$", "w", stderr); // Chuyển hướng std::cerr đến console
    freopen_s(&stream, "CONIN$", "r", stdin);   // Chuyển hướng std::cin đến console

    HWND hWnd;
    MSG msg;
    WNDCLASS wndClass;
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;

    // Khởi tạo GDI+
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = WndProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = hInstance;
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = TEXT("GettingStarted");

    RegisterClass(&wndClass);

    hWnd = CreateWindow(
        TEXT("GettingStarted"),  // Tên lớp cửa sổ
        TEXT("Getting Started"), // Tiêu đề cửa sổ
        WS_OVERLAPPEDWINDOW,     // Kiểu cửa sổ
        CW_USEDEFAULT,           // Vị trí x ban đầu
        CW_USEDEFAULT,           // Vị trí y ban đầu
        CW_USEDEFAULT,           // Kích thước x ban đầu
        CW_USEDEFAULT,           // Kích thước y ban đầu
        NULL,                    // Handle cửa sổ cha
        NULL,                    // Handle menu cửa sổ
        hInstance,               // Handle instance chương trình
        NULL);                   // Tham số khởi tạo

    ShowWindow(hWnd, iCmdShow);
    UpdateWindow(hWnd);

    // Vòng lặp xử lý thông điệp
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Đóng GDI+
    GdiplusShutdown(gdiplusToken);

    // Đóng cửa sổ console khi chương trình kết thúc
    FreeConsole();

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        OnPaint(hdc);
        EndPaint(hWnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}