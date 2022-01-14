#include <iostream>
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

static HGLRC hRC;		// Постоянный контекст рендеринга
static HDC hDC;			// Приватный контекст устройства GDI
BOOL	keys[256];		// Массив для процедуры обработки клавиатуры
int x = 0, z = 0;

GLvoid InitGL(GLsizei Width, GLsizei Height)	// Вызвать после создания
// окна GL
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// Очистка экрана в черный цвет
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glShadeModel(GL_FLAT);
	glEnable(GL_CULL_FACE);
}

GLvoid ReSizeGLScene(GLsizei Width, GLsizei Height)
{
	if (Height == 0)		// Предотвращение деления на ноль, 
//если окно слишком мало
Height = 1;

	glViewport(0, 0, Width, Height);   // Сброс текущей области вывода 
}

GLvoid DrawGLScene(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT); 	// Очистка экрана

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glLineWidth(3);
	glBegin(GL_LINES);           // Режим рисования – одиночные линии
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(-0.7, 0.0, 0.0);
	glEnd();

	GLfloat VertexArray[10][3];
	GLfloat ColorArray[10][3];
	GLubyte IndexArray[1][10];
	GLubyte IndexArray1[1][10];
	
	
	VertexArray[0][0] = 0.5;
	VertexArray[0][1] = 0.0;
	VertexArray[0][2] = 0.0;

	VertexArray[1][0] = 0.0;
	VertexArray[1][1] = 0.6;
	VertexArray[1][2] = 0.3;

	VertexArray[2][0] = 0.0;
	VertexArray[2][1] = 0.3;
	VertexArray[2][2] = 0.6;

	VertexArray[3][0] = 0.0;
	VertexArray[3][1] = -0.3;
	VertexArray[3][2] = 0.6;

	VertexArray[4][0] = 0.0;
	VertexArray[4][1] = -0.6;
	VertexArray[4][2] = 0.3;

	VertexArray[5][0] = 0.0;
	VertexArray[5][1] = -0.6;
	VertexArray[5][2] = -0.3;

	VertexArray[6][0] = 0.0;
	VertexArray[6][1] = -0.3;
	VertexArray[6][2] = -0.6;

	VertexArray[7][0] = 0.0;
	VertexArray[7][1] = 0.3;
	VertexArray[7][2] = -0.6;

	VertexArray[8][0] = 0.0;
	VertexArray[8][1] = 0.6;
	VertexArray[8][2] = -0.3;

	VertexArray[9][0] = -0.5;
	VertexArray[9][1] = 0.0;
	VertexArray[9][2] = 0.0;

	ColorArray[0][0] = 0.0;
	ColorArray[0][1] = 0.0;
	ColorArray[0][2] = 1.0;

	ColorArray[1][0] = 0.6;
	ColorArray[1][1] = 0.98;
	ColorArray[1][2] = 0.6;

	ColorArray[2][0] = 1.0;
	ColorArray[2][1] = 0.84;
	ColorArray[2][2] = 0.8;

	ColorArray[3][0] = 0.8;
	ColorArray[3][1] = 0.36;
	ColorArray[3][2] = 0.36;

	ColorArray[4][0] = 1.0;
	ColorArray[4][1] = 0.27;
	ColorArray[4][2] = 0.0;

	ColorArray[5][0] = 0.82;
	ColorArray[5][1] = 0.13;
	ColorArray[5][2] = 0.56;

	ColorArray[6][0] = 0.54;
	ColorArray[6][1] = 0.17;
	ColorArray[6][2] = 0.89;

	ColorArray[7][0] = 0.0;
	ColorArray[7][1] = 1.0;
	ColorArray[7][2] = 1.0;

	ColorArray[8][0] = 0.0;
	ColorArray[8][1] = 0.5;
	ColorArray[8][2] = 1.0;

	ColorArray[9][0] = 0.0;
	ColorArray[9][1] = 0.0;
	ColorArray[9][2] = 1.0;

	IndexArray[0][0] = 0;
	IndexArray[0][1] = 1;
	IndexArray[0][2] = 2;
	IndexArray[0][3] = 3;
	IndexArray[0][4] = 4;
	IndexArray[0][5] = 5;
	IndexArray[0][6] = 6;
	IndexArray[0][7] = 7;
	IndexArray[0][8] = 8;
	IndexArray[0][9] = 1;

	IndexArray1[0][0] = 9;
	IndexArray1[0][1] = 8;
	IndexArray1[0][2] = 7;
	IndexArray1[0][3] = 6;
	IndexArray1[0][4] = 5;
	IndexArray1[0][5] = 4;
	IndexArray1[0][6] = 3;
	IndexArray1[0][7] = 2;
	IndexArray1[0][8] = 1;
	IndexArray1[0][9] = 8;

	
	glVertexPointer(3, GL_FLOAT, 0, VertexArray);
	glColorPointer(3, GL_FLOAT, 0, ColorArray);
	glDrawElements(GL_TRIANGLE_FAN, 10, GL_UNSIGNED_BYTE, IndexArray);
	glDrawElements(GL_TRIANGLE_FAN, 10, GL_UNSIGNED_BYTE, IndexArray1);

	GLfloat lineArray[2][3];
	GLfloat colorLineArray[2][3];
	GLfloat indexLineArray[1][2];

	lineArray[0][0] = 0.5;
	lineArray[0][1] = 0.0;
	lineArray[0][2] = 0.0;

	lineArray[1][0] = -0.2;
	lineArray[1][1] = 0.0;
	lineArray[1][2] = 0.0;

	colorLineArray[0][0] = 0.5;
	colorLineArray[0][1] = 0.7;
	colorLineArray[0][2] = 0.2;

	colorLineArray[1][0] = 0.2;
	colorLineArray[1][1] = 0.4;
	colorLineArray[1][2] = 0.9;

	indexLineArray[0][0] = 0;
	indexLineArray[0][1] = 1;
	
	glFrustum(-10, 10, -10, 10, 4, 4);
	glRotatef(0.03, x, 0, z);

	glEnd();
}

LRESULT CALLBACK WndProc(HWND	hWnd,
	UINT	message,
	WPARAM	wParam,
	LPARAM	lParam)
{
	RECT	Screen;		// используется позднее для размеров окна
	GLuint	PixelFormat;
	static	PIXELFORMATDESCRIPTOR pfd =
	{
	sizeof(PIXELFORMATDESCRIPTOR),	// Размер этой структуры
	1,				// Номер версии (?)
	PFD_DRAW_TO_WINDOW |		// Формат для Окна
	PFD_SUPPORT_OPENGL |		// Формат для OpenGL
	PFD_DOUBLEBUFFER,		// Формат для двойного буфера
	PFD_TYPE_RGBA,		// Требуется RGBA формат
	16,				// Выбор 16 бит глубины цвета
	0, 0, 0, 0, 0, 0,		// Игнорирование цветовых битов (?)
	0,				// нет буфера прозрачности
	0,				// Сдвиговый бит игнорируется (?)
	0,				// Нет буфера аккумуляции
	0, 0, 0, 0,			// Биты аккумуляции игнорируются (?)
	16,				// 16 битный Z-буфер (буфер глубины)
	0,				// Нет буфера траффарета
	0,				// Нет вспомогательных буферов (?)
	PFD_MAIN_PLANE,		// Главный слой рисования
	0,				// Резерв (?)
	0, 0, 0			// Маски слоя игнорируются (?)
	};
	switch (message)	// Тип сообщения
	{
	case WM_CREATE:
		hDC = GetDC(hWnd);	// Получить контекст устройства для окна
		PixelFormat = ChoosePixelFormat(hDC, &pfd);
		// Найти ближайшее совпадение для нашего формата пикселов
		if (!PixelFormat)
		{
			MessageBox(0, "Can't Find A SuitablePixelFormat.", "Error", MB_OK | MB_ICONERROR);
			PostQuitMessage(0);
			// Это сообщение говорит, что программа должна завершиться
			break;	// Предтовращение повтора кода
		}
		if (!SetPixelFormat(hDC, PixelFormat, &pfd))
		{
			MessageBox(0, "Can't Set ThePixelFormat.", "Error", MB_OK | MB_ICONERROR);
			PostQuitMessage(0);
			break;
		}
		hRC = wglCreateContext(hDC);
		if (!hRC)
		{
			MessageBox(0,
				"Can't Create A GLRenderingContext.",
				"Error", MB_OK | MB_ICONERROR);
			PostQuitMessage(0);
			break;
		}
		if (!wglMakeCurrent(hDC, hRC))
		{
			MessageBox(0, "Can't activate GLRC.", "Error", MB_OK | MB_ICONERROR);
			PostQuitMessage(0);
			break;
		}
		GetClientRect(hWnd, &Screen);
		InitGL(Screen.right, Screen.bottom);
		break;
	case WM_DESTROY:
	case WM_CLOSE:
		ChangeDisplaySettings(NULL, 0);

		wglMakeCurrent(hDC, NULL);
		wglDeleteContext(hRC);
		ReleaseDC(hWnd, hDC);
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		keys[wParam] = TRUE;
		break;

	case WM_KEYUP:
		keys[wParam] = FALSE;
		break;
	case WM_SIZE:
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));
		break;
	default:
		return (DefWindowProc(hWnd, message, wParam, lParam));
	}
	return (0);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	MSG		msg;	// Структура сообщения Windows
	WNDCLASS	wc;   // Структура класса Windows для установки типа окна
	HWND		hWnd;	// Сохранение дескриптора окна
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "OpenGL WinClass";
	if (!RegisterClass(&wc))
	{
		MessageBox(0,
			"Failed To Register The WindowClass.",
			"Error", MB_OK | MB_ICONERROR);
		return FALSE;
	}
	hWnd = CreateWindow("OpenGL WinClass",
		"First OpenGL program",	// Заголовок вверху окна

		WS_POPUP |
		WS_CLIPCHILDREN |
		WS_CLIPSIBLINGS,
		0, 0,			// Позиция окна на экране
		720, 720,		// Ширина и высота окна
		NULL,
		NULL,
		hInstance,
		NULL);
	if (!hWnd)
	{
		MessageBox(0, "Window Creation Error.", "Error", MB_OK | MB_ICONERROR);
		return FALSE;
	}
	if (!hWnd)
	{
		MessageBox(0, "Window Creation Error.", "Error", MB_OK | MB_ICONERROR);
		return FALSE;
	}

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	SetFocus(hWnd);
	while (1)
	{		// Обработка всех сообщений
		while (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				return TRUE;
			}
		}
		z = 0;
		x = 0;
		if (keys[VK_ESCAPE]) SendMessage(hWnd, WM_CLOSE, 0, 0);	// Если ESC - выйти
		if (keys[VK_LEFT])
		{
			z = 1;
		}
		if (keys[VK_RIGHT])
		{
			z = -1;
		}
		if (keys[VK_UP])
		{
			x = -1;
		}
		if (keys[VK_DOWN])
		{
			x = 1;
		}

		DrawGLScene();				// Нарисовать сцену
		SwapBuffers(hDC);		// Переключить буфер экрана
		if (keys[VK_ESCAPE]) SendMessage(hWnd, WM_CLOSE, 0, 0);	// Если ESC - выйти
	}
}
