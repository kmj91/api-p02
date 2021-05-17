#pragma once
#include "singletonBase.h"
#include "inc/fmod.hpp"
#pragma comment(lib, "lib/fmodex_vc.lib")

using namespace FMOD;

/*
FMOD
���带 �÷��� �ϱ� ���� �����ִ� �༮
������ ��������� ������ �ߴܵǾ����� ���򿡵�
���� ����. �����ϰ� ����� �� �ְ� �����ϴ�
Ȯ���ڰ� ���Ƽ� ���ֻ礿����

���� �������� :  fmod studio ����Ʈ ������ Ȯ�� ����

*/
//ä�ι��ۿ� ���� ����
#define EXTRACHANNELBUFFER 5
#define SOUNDBUFFER 100


//�� ���� ���� :  ���۰� �۾Ƽ� ������ ������ �ذ��ϱ� ����.
#define TOTALSOUNDBUFFER SOUNDBUFFER + EXTRACHANNELBUFFER

class soundManager : public singletonBase<soundManager>
{

private:
	typedef map<string, Sound**> arrSounds;
	typedef map<string, Sound**>::iterator arrSoundIter;


	System* m_system;	//fmod�� �ý��� Ŭ������.


						//���������͸� ���°� ����� ���� ���ڰ� ���������ͷ� �Ǿ��ִ�.
	Sound** m_sound;	//����Ŭ����
	Channel** m_channel;//ä�� Ŭ����

	arrSounds m_totalSounds; //�ʿ� ��� ���� ���

public:
	soundManager();
	~soundManager();


	HRESULT init();
	void release();
	void update();
	void render();

	//���� �߰�(Ű��, �����̸�, BGM, LOOP)
	void addSound(string keyName, string soundName, bool bgm = FALSE, bool loop = FALSE);

	//���� �÷���(Ű��, ���� 0.0f~1.0f)
	void play(string keyName, float volume = 1.0f);
	//����
	void stop(string keyName);
	//�Ͻ�����
	void pause(string keyName);
	//�ٽ����
	void resume(string keyName);
	//�������
	void allStop();

	//�÷��� ����?
	bool isPlaySound(string keyName);
	//�Ͻ����� ����?
	bool isPauseSound(string keyName);

};

