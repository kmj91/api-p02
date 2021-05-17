#pragma once
#include"gameNode.h"
#include"progressBar.h"

//�ε� �������� ����
enum LOAD_KIND
{
	LOAD_KIND_IMAGE_0,	//�� ��Ʈ��	�̹���
	LOAD_KIND_IMAGE_1,	//�Ϲ� �̹���
	LOAD_KIND_IMAGE_2,	//�Ϲ� �̹���(��ġ��ǥ����)
	LOAD_KIND_FRAMEIMAGE_0,	//������
	LOAD_KIND_FRAMEIMAGE_1,	//������(��ġ ��ǥ ����)
	LOAD_KIND_ANIMATION_0,	//�ִϸ��̼�(ó������ ������)
	LOAD_KIND_ANIMATION_1,	//�ִϸ��̼�(�迭�� ��Ƽ�)
	LOAD_KIND_ANIMATION_2,	//�ִϸ��̼�(���۰� ������)
	LOAD_KIND_SOUND,
	LOAD_KIND_END
};

//�̹��� ���ҽ� ����ü
struct tagImageResource
{
	string keyName;			//Ű��
	const char* fileName;	//�����̸�
	int x, y;				//��ġ��ǥ
	int width, height;		//���μ��� ũ��
	int frameX, frameY;		//������ xy
	bool trans;				//��� ���ٲ���
	COLORREF transColor;
};

//�ִϸ��̼� ���ҽ� ����ü
struct tagAnimationResource
{
	string animationKeyName;	//�ִϸ��̼�Ű��
	string imageKeyName;			//�̹���Ű��
	int* playArr;				//�����ӹ迭
	int arrLen;					//�迭����
	int start, end;				//����,�� ������ �ε���
	int fps;					//����ӵ�
	bool reverse;				//���������
	bool loop;					//�ݺ�����
};

struct tagSoundResource
{
	string keyName;			//����Ű��
	string soundName;		//�����̸�
	bool bgm;				//��ݿ���(ȿ�����Ͻ� false)
	bool loop;				//��������
};

class loadItem
{
private:
	LOAD_KIND _kind;
	tagImageResource _imageResource;
	tagAnimationResource _animationResource;
	tagSoundResource _soundResource;
public:
	loadItem() {}
	~loadItem() {}

	//Ű ������ �� ��Ʈ�� �ʱ�ȭ
	HRESULT initForImage(string keyName, int width, int height);

	//Ű������ �̹��� ���� �ʱ�ȭ
	HRESULT initForImage(string keyname, const char* fileName, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	HRESULT initForImage(string keyName, const char* fileName, float x, float y, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	//Ű������ ������ �̹��� ���� �ʱ�ȭ
	HRESULT initForFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	HRESULT initForFrameImage(string keyName, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	HRESULT initForAnimation(string animationKeyName, string imageKeyName, int fps, bool reverse = false, bool loop = false);
	HRESULT initForAnimation(string animationKeyName, string imageKeyName, int* playArr, int arrLen, int fps, bool loop = false);
	HRESULT initForAnimation(string animationKeyName, string imageKeyName, int start, int end, int fps, bool reverse = false, bool loop = false);

	HRESULT initForSound(string keyName, string soundName, bool bgm = FALSE, bool loop = FALSE);

	//�ε� ������ ������ �����Ͷ�
	LOAD_KIND getLoadingKind() { return _kind; }

	//�̹��� ���ҽ��� ��������
	tagImageResource getImageResource() { return _imageResource; }
	tagAnimationResource getAnimationResource() { return _animationResource; }
	tagSoundResource getSoundResource() { return _soundResource; }
};

class loading :  public gameNode
{
private:
	typedef vector<loadItem*> arrLoadItem;

	arrLoadItem _vLoadItem;
	//�ε�ȭ�鿡�� ����� �̹��� �� �ε���
	image* _background;
	image* _feather;
	image* _character;
	//�ε�ȭ�鿡�� ����� �༮
	progressBar* _loadingBar;
	//�ε��� ������
	int _currentGauge;

public:
	loading();
	~loading();

	HRESULT init();
	void release();
	void update();
	void render();

	void loadImage(string keyName, int width, int height);

	void loadImage(string keyName, const char* fileName, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	void loadImage(string keyName, const char* fileName, float x, float y, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	void loadFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	void loadFrameImage(string keyName, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	void loadAnimation(string animationKeyName, string imageKeyName, int fps, bool reverse = false, bool loop = false);
	void loadAnimation(string animationKeyName, string imageKeyName, int* playArr, int arrLen, int fps, bool loop = false);
	void loadAnimation(string animationKeyName, string imageKeyName, int start, int end, int fps, bool reverse = false, bool loop = false);

	void loadForSound(string keyName, string soundName, bool bgm = FALSE, bool loop = FALSE);

	//�ε��Ϸ� �Ƴ�?(�ε� �Ϸ��� ������)
	BOOL loadingDone();

	//�ε� ������ ��������
	vector<loadItem*>getLoadItem() { return _vLoadItem; }

};

