#include<Windows.h>
#include <gl\glew.h>
#include <gl\GLU.h>
#include <gl\GL.h>
#include "Escena.h"
#include <time.h>
#include<mmsystem.h>
//#include <stdlib.h>
//#include "glext.h"
#pragma comment (lib, "glew32.lib") 
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib") 
#pragma comment(lib, "winmm.lib")

#define Timer1 100

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void DefPixelFormat(HDC hDC);

HDC hContextoVentana;
Escena *escena;
bool renderiza = false;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwndVentana;
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = "HUUUH";
	RegisterClassEx(&wc);
	RECT wr = { 0, 0, 1080, 720 };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	hwndVentana = CreateWindowEx(NULL,
		"HUUUH",
		"Dark Souls POO",
		WS_OVERLAPPEDWINDOW,
		800,
		100,
		wr.right - wr.left,
		wr.bottom - wr.top,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwndVentana, nCmdShow);

	glewInit();

	escena = new Escena(hwndVentana);

	SetTimer(hwndVentana, Timer1, 30, NULL);

	MSG msg = { 0 };
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				break;
		}
		else
		{
			if (renderiza)
			{
				escena->render(hContextoVentana);
				renderiza = false;
			}
		}
	}

	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HGLRC hContextoGL;
	static HDC hContextoAux;
	int ancho, alto;
	int aux = 0;
	//char epx[6] = "";
	//char epz[6] = "";
	//char epy[6] = "";
	//char edx[6] = "";
	//char edz[6] = "";
	//char edy[6] = "";
	//char ec[80] = "";

	switch (message)
	{
	case WM_CREATE:
		hContextoAux = GetDC(hWnd);
		hContextoVentana = hContextoAux;
		DefPixelFormat(hContextoVentana);
		hContextoGL = wglCreateContext(hContextoVentana);
		wglMakeCurrent(hContextoVentana, hContextoGL);
		srand(time(NULL));
		mciSendString("open \"Sonidos//Darkroot_Basin.mp3\" alias DB", NULL, 0, 0);
		mciSendString("open \"Sonidos//Anor_Londo.mp3\" alias AL", NULL, 0, 0);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		//case VK_RETURN:
		//	strcpy_s(epx, "");
		//	strcpy_s(edx, "");
		//	strcpy_s(epz, "");
		//	strcpy_s(edz, "");
		//	strcpy_s(epy, "");
		//	strcpy_s(edy, "");
		//	strcpy_s(ec, "");
		//	_itoa_s(escena->px, epx, 10);
		//	_itoa_s(escena->pz, epz, 10);
		//	_itoa_s(escena->py, epy, 10);
		//	_itoa_s(escena->dx, edx, 10);
		//	_itoa_s(escena->dz, edz, 10);
		//	_itoa_s(escena->dy, edy, 10);
		//	strcat(ec, "Px = ");
		//	strcat(ec, epx);
		//	strcat(ec, "   ");
		//	strcat(ec, "Pz = ");
		//	strcat(ec, epz);
		//	strcat(ec, "   ");
		//	strcat(ec, "Py = ");
		//	strcat(ec, epy);
		//	strcat(ec, "   ");
		//	strcat(ec, "Dx = ");
		//	strcat(ec, edx);
		//	strcat(ec, "   ");
		//	strcat(ec, "Dz = ");
		//	strcat(ec, edz);
		//	strcat(ec, "   ");
		//	strcat(ec, "Dy = ");
		//	strcat(ec, edy);
		//	MessageBox(hWnd, ec, "Camara", MB_OK);
		//	return 0;
		case VK_UP:
			escena->VoltearArriba();
			renderiza = true;
			return 0;
		case VK_DOWN:
			escena->VoltearAbajo();
			renderiza = true;
			return 0;
		case VK_LEFT:
			escena->VoltearIzquierda();
			renderiza = true;
			return 0;
		case VK_RIGHT:
			escena->VoltearDerecha();
			renderiza = true;
			return 0;
		case 0x44: //D
			aux = escena->px;
			escena->MoverDerecha();
			if (escena->px < aux)
			{
				if (escena->sswalk < 0.075 && escena->sswalkaux == false)
					escena->sswalk += 0.015;
				else if (escena->sswalk >= 0.075 && escena->sswalkaux == false)
					escena->sswalkaux = true;
				else if (escena->sswalk > 0 && escena->sswalkaux == true)
					escena->sswalk -= 0.015;
				else if (escena->sswalk <= 0 && escena->sswalkaux == true)
					escena->sswalkaux = false;
			}
			//escena->dx -= 1;
			//escena->px -= 1;
			renderiza = true;
			return 0;
		case 0x41: //A
			aux = escena->px;
			escena->MoverIzquierda();
			if (escena->px > aux)
			{
				if (escena->sswalk < 0.075 && escena->sswalkaux == false)
					escena->sswalk += 0.015;
				else if (escena->sswalk >= 0.075 && escena->sswalkaux == false)
					escena->sswalkaux = true;
				else if (escena->sswalk > 0 && escena->sswalkaux == true)
					escena->sswalk -= 0.015;
				else if (escena->sswalk <= 0 && escena->sswalkaux == true)
					escena->sswalkaux = false;
			}
			//escena->dx += 1;
			//escena->px += 1;
			renderiza = true;
			return 0;
		case 0x57: //W
			aux = escena->pz;
			escena->MoverAdelante();
			if (escena->pz > aux)
			{
				if (escena->sswalk < 0.075 && escena->sswalkaux == false)
					escena->sswalk += 0.015;
				else if (escena->sswalk >= 0.075 && escena->sswalkaux == false)
					escena->sswalkaux = true;
				else if (escena->sswalk > 0 && escena->sswalkaux == true)
					escena->sswalk -= 0.015;
				else if (escena->sswalk <= 0 && escena->sswalkaux == true)
					escena->sswalkaux = false;
				if (escena->pz <= 225 && escena->niebla.densidad > 0.0025)
					escena->niebla.densidad -= 0.00005;
			}
			//escena->dz += 1;
			//escena->pz += 1;
			renderiza = true;
			return 0;
		case 0x53: //S
			aux = escena->pz;
			escena->MoverAtras();
			if (escena->pz < aux)
			{
				if (escena->sswalk < 0.075 && escena->sswalkaux == false)
					escena->sswalk += 0.015;
				else if (escena->sswalk >= 0.075 && escena->sswalkaux == false)
					escena->sswalkaux = true;
				else if (escena->sswalk > 0 && escena->sswalkaux == true)
					escena->sswalk -= 0.015;
				else if (escena->sswalk <= 0 && escena->sswalkaux == true)
					escena->sswalkaux = false;
				if (escena->pz <= 225 && escena->niebla.densidad < 0.0125)
					escena->niebla.densidad += 0.00005;
			}
			//escena->dz -= 1;
			//escena->pz -= 1;
			renderiza = true;
			return 0;
		//case 0x44: //D
		//	//escena->MoverDerecha();
		//	escena->dx -= 1;
		//	escena->px -= 1;
		//	renderiza = true;
		//	return 0;
		//case 0x41: //A
		//	//escena->MoverIzquierda();
		//	escena->dx += 1;
		//	escena->px += 1;
		//	renderiza = true;
		//	return 0;
		//case 0x57: //W
		//	//escena->MoverAdelante();
		//	//if (escena->pz <= 225 && escena->niebla.densidad > 0.0025)
		//		//escena->niebla.densidad -= 0.00005;
		//	escena->dz += 1;
		//	escena->pz += 1;
		//	renderiza = true;
		//	return 0;
		//case 0x53: //S
		//	//escena->MoverAtras();
		//	//if (escena->pz <= 225 && escena->niebla.densidad < 0.0125)
		//		//escena->niebla.densidad += 0.00005;
		//	escena->dz -= 1;
		//	escena->pz -= 1;
		//	renderiza = true;
		//	return 0;
		//case 0x45: //E
		//	//escena->niebla.densidad = 0.025;
		//	//escena->dy -= 1;
		//	//escena->py -= 1;
		//	renderiza = true;
		//	return 0;
		//case 0x51: //Q
		//	escena->dy += 1;
		//	escena->py += 1;
		//	renderiza = true;
		//	return 0;
		}
	case WM_TIMER:
		renderiza = true;
		if (escena->pz <= 250 && escena->musica == false)
		{
			mciSendString("stop AL", NULL, 0, 0);	
			mciSendString("play DB repeat", NULL, 0, 0);
			escena->musica = true;
		}
		if (escena->pz >= 251 && escena->musica == true)
		{
			mciSendString("stop DB", NULL, 0, 0);
			mciSendString("play AL repeat", NULL, 0, 0);
			escena->musica = false;
		}
		if (escena->pz <= 250 && escena->pz >= 225 && escena->px < -160 && escena->bonfire == 1)
		{
			mciSendString("stop bonfire", NULL, 0, 0);
			mciSendString("close bonfire", NULL, 0, 0);
			mciSendString("open \"Sonidos//bonfire.mp3\" alias bonfire", NULL, 0, 0);
			mciSendString("play bonfire", NULL, 0, 0);
			escena->bonfire = 2;
		}
		break;
	case WM_DESTROY:
	{
		KillTimer(hWnd, Timer1);
		delete escena->noche;
		delete escena->dia;
		delete escena->cuenca;
		delete escena->lago;
		delete escena->DS_AL;
		delete escena->DS_BK[0];
		delete escena->DS_BK[1];
		delete escena->DS_BK[2];
		delete escena->DS_Bonfire;
		delete escena->DS_Stone;
		delete escena->DS_Hollow[0];
		delete escena->DS_Hollow[1];
		delete escena->DS_Hollow[2];
		delete escena->DS_CL[0];
		delete escena->DS_CL[1];
		delete escena->DS_CL[2];
		delete escena->DS_Bridge;
		delete escena->DS_CG[0];
		delete escena->DS_CG[1];
		delete escena->DS_CG[2];
		delete escena->DS_Hydra[0];
		delete escena->DS_Hydra[1];
		delete escena->DS_Hydra[2];
		delete escena->DS_Chest[0];
		delete escena->DS_Chest[1];
		delete escena->DS_Chest[2];
		delete escena->DS_Greatsword;
		delete escena->DS_Mimic[0];
		delete escena->DS_Mimic[1];
		delete escena->DS_Stair;
		delete escena->Tree[0];
		delete escena->Tree[1];
		delete escena->Tree[2];
		wglMakeCurrent(hContextoVentana, NULL);
		wglDeleteContext(hContextoGL);
		PostQuitMessage(0);
		return 0;
	} break;

	case WM_SIZE:
	{
		alto = HIWORD(lParam);
		ancho = LOWORD(lParam);
		if (alto == 0)
			alto = 1;
		glViewport(0, 0, ancho, alto);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (GLfloat)ancho / (GLfloat)alto, 1.0f, 10000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

void DefPixelFormat(HDC hDC)
{
	int bestmatch;

	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR), //tamaño de la estructura
		1, //numero de version
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, //soporta la ventana, el opengl y manejara doble buffer
		PFD_TYPE_RGBA, //formato de 32 bits rgba
		32, //tamaño del color en 32 bits
		0, 0, 0, 0, 0, 0, //bits de color, no se usan
		0, //no hay buffer para el alfa
		0, //ignore el bit de corrimiento
		0, //no hay buffer de acumulacion
		0, 0, 0, 0, //no hay bits de acumulacion
		16, //tamaño del flotante para el buffer z
		0, //no hay buffers de stencil
		0, //no hay buffers auxiliares
		PFD_MAIN_PLANE, //plano principal para dibujo
		0, //reservado
		0, 0, 0 //mascaras de capas ignoradas
	};

	bestmatch = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, bestmatch, &pfd);
}
