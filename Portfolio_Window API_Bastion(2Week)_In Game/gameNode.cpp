#include "stdafx.h"
#include "gameNode.h"
gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}

HRESULT gameNode::init()
{


	_hdc = GetDC(m_hWnd);
	_managerInit = false;
	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(m_hWnd);
	_managerInit = managerInit;

	if (managerInit)
	{
		//SetTimer(m_hWnd, 1, 10, NULL);
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		TIMEMANAGER->init();
		SCENEMANAGER->init();
		SOUNDMANAGER->init();
		ANIMATIONMANAGER->init();
		TXTDATA->init();
		INIDATA->init();
	}

	return S_OK;
}

//void gameNode::setBackBuffer()
//{
//	_backBuffer = new image;
//	_backBuffer->init(WINSIZEX, WINSIZEY);
//}
void gameNode::release()

{
	if (_managerInit)
	{
		//타이머 해제
		//KillTimer(m_hWnd, 1);
		KEYMANAGER->releaseSingleton();
		IMAGEMANAGER->releaseSingleton();
		TIMEMANAGER->releaseSingleton();
		SCENEMANAGER->releaseSingleton();
		SOUNDMANAGER->releaseSingleton();
		ANIMATIONMANAGER->releaseSingleton();
		EFFECTMANAGER->releaseSingleton();
		RND->releaseSingleton();
		TXTDATA->releaseSingleton();
		INIDATA->releaseSingleton();

		KEYMANAGER->release();
		IMAGEMANAGER->release();
		TIMEMANAGER->release();
		SCENEMANAGER->release();
		ANIMATIONMANAGER->release();
	}
	
	ReleaseDC(m_hWnd, _hdc);
}

void gameNode::update()
{

	//더블버퍼 이후 사용 하지 않는다.(true->false)
	InvalidateRect(m_hWnd, NULL, false);
}

void gameNode::render(/*HDC hdc*/)
{

}

void gameNode::setMap()
{
}

void gameNode::save()
{
}

void gameNode::load()
{
}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//PAINTSTRUCT ps;
	//HDC hdc;

	switch (iMessage)
	{
		case WM_MOUSEMOVE:
			m_ptMouse.x = LOWORD(lParam);
			m_ptMouse.y = HIWORD(lParam);
			break;
	case WM_KEYDOWN:

		//switch (wParam)
		//{
		//case VK_ESCAPE:
		//	PostQuitMessage(0);
		//	break;
		//}
		break;
	case WM_DESTROY : 
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
