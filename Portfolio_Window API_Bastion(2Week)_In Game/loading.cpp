#include "stdafx.h"
#include "loading.h"

HRESULT loadItem::initForImage(string keyName, int width, int height)
{
	_kind = LOAD_KIND_IMAGE_0;


	_imageResource.keyName = keyName;
	_imageResource.width = width;
	_imageResource.height = height;

	return S_OK;
}

HRESULT loadItem::initForImage(string keyname, const char * fileName, int width, int height, BOOL isTrans, COLORREF transColor)
{
	_kind = LOAD_KIND_IMAGE_1;

	_imageResource.keyName = keyname;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::initForImage(string keyName, const char * fileName, float x, float y, int width, int height, BOOL isTrans, COLORREF transColor)
{
	_kind = LOAD_KIND_IMAGE_2;

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.x = x;
	_imageResource.y = y;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::initForFrameImage(string keyName, const char * fileName, int width, int height, int frameX, int frameY, BOOL isTrans, COLORREF transColor)
{

	_kind = LOAD_KIND_FRAMEIMAGE_0;

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.frameX = frameX;
	_imageResource.frameY = frameY;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::initForFrameImage(string keyName, const char * fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL isTrans, COLORREF transColor)
{

	_kind = LOAD_KIND_FRAMEIMAGE_1;

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.x = x;
	_imageResource.y = y;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.frameX = frameX;
	_imageResource.frameY = frameY;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::initForAnimation(string animationKeyName, string imageKeyName, int fps, bool reverse, bool loop)
{
	_kind = LOAD_KIND_ANIMATION_0;

	_animationResource.animationKeyName = animationKeyName;
	_animationResource.imageKeyName = imageKeyName;
	_animationResource.fps = fps;
	_animationResource.reverse = reverse;
	_animationResource.loop = loop;

	return S_OK;
}

HRESULT loadItem::initForAnimation(string animationKeyName, string imageKeyName, int * playArr, int arrLen, int fps, bool loop)
{
	_kind = LOAD_KIND_ANIMATION_1;

	_animationResource.animationKeyName = animationKeyName;
	_animationResource.imageKeyName = imageKeyName;
	_animationResource.playArr = playArr;
	_animationResource.arrLen = arrLen;
	_animationResource.fps = fps;
	_animationResource.loop = loop;

	return S_OK;
}

HRESULT loadItem::initForAnimation(string animationKeyName, string imageKeyName, int start, int end, int fps, bool reverse, bool loop)
{
	_kind = LOAD_KIND_ANIMATION_2;

	_animationResource.animationKeyName = animationKeyName;
	_animationResource.imageKeyName = imageKeyName;
	_animationResource.start = start;
	_animationResource.end = end;
	_animationResource.fps = fps;
	_animationResource.reverse = reverse;
	_animationResource.loop = loop;

	return S_OK;
}

HRESULT loadItem::initForSound(string keyName, string soundName, bool bgm, bool loop)
{
	_kind = LOAD_KIND_SOUND;

	_soundResource.keyName = keyName;
	_soundResource.soundName = soundName;
	_soundResource.bgm = bgm;
	_soundResource.loop = loop;

	return S_OK;
}


loading::loading()
{
}


loading::~loading()
{
}

HRESULT loading::init()
{
	//로딩화면 백그라운드 초기화
	_background = IMAGEMANAGER->addImage("Loading_Background", "images/UI/Loading/Loading_Background.bmp", WINSIZEX, WINSIZEY);

	//로딩바 초기화를 하자
	_loadingBar = new progressBar;
	_loadingBar->init("images/UI/Loading/LoadingBar_Front.bmp", "images/UI/Loading/LoadingBar_Back.bmp", 100, WINSIZEY / 2 + 300, 800, 36);
	_loadingBar->setGauge(0, 0);

	_feather = IMAGEMANAGER->addImage("Loading_Feather", "images/UI/Loading/Loading_Feather.bmp", 40, 19, true, RGB(255, 0, 255));
	_character = IMAGEMANAGER->addImage("Loading_Character", "images/UI/Loading/Loading_Character.bmp", 300, 187, true, RGB(255, 0, 255));

	//로딩바 게이지 초기화
	_currentGauge = 0;
	
	return S_OK;
	
}

void loading::release()
{
	SAFE_DELETE(_loadingBar);
}

void loading::update()
{
	_loadingBar->update();
}

void loading::render()
{
	_background->render(getMemDC());
	_loadingBar->render();
	_feather->render(getMemDC(), _loadingBar->getX() + _loadingBar->getWidth() - 40, WINSIZEY / 2 + 270);
	_character->render(getMemDC(), 50, 400);
}

void loading::loadImage(string keyName, int width, int height)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, width, height);

	_vLoadItem.push_back(item);
}

void loading::loadImage(string keyName, const char * fileName, int width, int height, BOOL isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, fileName, width, height, isTrans, transColor);

	_vLoadItem.push_back(item);
}

void loading::loadImage(string keyName, const char * fileName, float x, float y, int width, int height, BOOL isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, fileName, x, y, width, height, isTrans, transColor);

	_vLoadItem.push_back(item);
}

void loading::loadFrameImage(string keyName, const char * fileName, int width, int height, int frameX, int frameY, BOOL isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForFrameImage(keyName, fileName, width, height, frameX, frameY, isTrans, transColor);

	_vLoadItem.push_back(item);
}

void loading::loadFrameImage(string keyName, const char * fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForFrameImage(keyName, fileName, x, y, width, height, frameX, frameY, isTrans, transColor);

	_vLoadItem.push_back(item);
}

void loading::loadAnimation(string animationKeyName, string imageKeyName, int fps, bool reverse, bool loop)
{
	loadItem* item = new loadItem;
	item->initForAnimation(animationKeyName, imageKeyName, fps, reverse, loop);

	_vLoadItem.push_back(item);
}

void loading::loadAnimation(string animationKeyName, string imageKeyName, int * playArr, int arrLen, int fps, bool loop)
{
	loadItem* item = new loadItem;
	item->initForAnimation(animationKeyName, imageKeyName, playArr, arrLen, fps, loop);

	_vLoadItem.push_back(item);
}

void loading::loadAnimation(string animationKeyName, string imageKeyName, int start, int end, int fps, bool reverse, bool loop)
{
	loadItem* item = new loadItem;
	item->initForAnimation(animationKeyName, imageKeyName, start, end, fps, reverse, loop);

	_vLoadItem.push_back(item);
}

void loading::loadForSound(string keyName, string soundName, bool bgm, bool loop)
{
	loadItem* item = new loadItem;
	item->initForSound(keyName, soundName, bgm, loop);

	_vLoadItem.push_back(item);
}

BOOL loading::loadingDone()
{
	if (_currentGauge >= _vLoadItem.size())
	{
		return TRUE;
	}

	loadItem* item = _vLoadItem[_currentGauge];

	tagImageResource img = item->getImageResource();
	tagAnimationResource ani = item->getAnimationResource();
	tagSoundResource sound = item->getSoundResource();

	switch (item->getLoadingKind())
	{
	case LOAD_KIND_IMAGE_0:
		IMAGEMANAGER->addImage(img.keyName, img.width, img.height);
		break;
	case LOAD_KIND_IMAGE_1:
		IMAGEMANAGER->addImage(img.keyName, img.fileName, img.width, img.height, img.trans, img.transColor);
		break;
	case LOAD_KIND_IMAGE_2:
		IMAGEMANAGER->addImage(img.keyName, img.fileName, img.x, img.y, img.width, img.height, img.trans, img.transColor);
		break;
	case LOAD_KIND_FRAMEIMAGE_0:
		IMAGEMANAGER->addFrameImage(img.keyName, img.fileName, img.width, img.height, img.frameX, img.frameY, img.trans, img.transColor);
		break;
	case LOAD_KIND_FRAMEIMAGE_1:
		IMAGEMANAGER->addFrameImage(img.keyName, img.fileName, img.x, img.y, img.width, img.height, img.frameX, img.frameY, img.trans, img.transColor);
		break;
	case LOAD_KIND_ANIMATION_0:
		ANIMATIONMANAGER->addDefAnimation(ani.animationKeyName, ani.imageKeyName, ani.fps, ani.reverse, ani.loop);
		break;
	case LOAD_KIND_ANIMATION_1:
		ANIMATIONMANAGER->addAnimation(ani.animationKeyName, ani.imageKeyName, ani.playArr, ani.arrLen, ani.fps, ani.loop);
		break;
	case LOAD_KIND_ANIMATION_2:
		ANIMATIONMANAGER->addAnimation(ani.animationKeyName, ani.imageKeyName, ani.start, ani.end, ani.fps, ani.reverse, ani.loop);
		break;
		//필요하면만드셈
	case LOAD_KIND_SOUND:
		SOUNDMANAGER->addSound(sound.keyName, sound.soundName, sound.bgm, sound.loop);
		break;
	}
	//로딩바 이미지 변경
	_loadingBar->setGauge(_currentGauge, _vLoadItem.size());
	
	//카운트
	_currentGauge++;
	return FALSE;
}

