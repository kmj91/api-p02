#include "stdafx.h"
#include "Scene.h"

void Scene::LoadProcess()
{
}

//UTF-8 -> UTF-16
void Scene::UTF8toUTF16(const char *szText, WCHAR *szBuff, int iBuffLen) {
	int iRe = MultiByteToWideChar(CP_UTF8, 0, szText, strlen(szText), szBuff, iBuffLen);
	if (iRe < iBuffLen)
		szBuff[iRe] = L'\0';
	return;
}


Scene::Scene()
{
}


Scene::~Scene()
{
}
