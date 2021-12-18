#include "stdafx.h"
#include "soundManager.h"


soundManager::soundManager()
	:m_system(nullptr)
	, m_channel(nullptr)
	, m_sound(nullptr)
{
}


soundManager::~soundManager()
{
}

HRESULT soundManager::init()
{
	//���� �ý��� ����
	System_Create(&m_system);

	//���� ä�μ� ����
	m_system->init(TOTALSOUNDBUFFER, FMOD_INIT_NORMAL, 0);

	//���� ä�� �Ҵ�
	m_sound = new Sound *[TOTALSOUNDBUFFER];
	m_channel = new Channel *[TOTALSOUNDBUFFER];


	memset(m_sound, 0, sizeof(Sound*)*(TOTALSOUNDBUFFER));
	memset(m_channel, 0, sizeof(Channel*)*(TOTALSOUNDBUFFER));

	addSound("BGM_Bastion", "sound/BGM/BGM_Bastion.mp3", true, true);

	return S_OK;
}

void soundManager::release()
{
	if (m_channel != nullptr | m_sound != nullptr)
	{
		for (int i = 0; i < TOTALSOUNDBUFFER; i++)
		{
			if (m_channel != nullptr)
			{
				if (m_channel[i])m_channel[i]->stop();
			}
			if (m_sound != nullptr)
			{
				if (m_sound[i])m_sound[i]->release();
			}
		}
	}

	SAFE_DELETE(m_channel);
	SAFE_DELETE(m_sound);

	//�ý����� ���ڤ�
	if (m_system != nullptr)
	{
		m_system->release();
		m_system->close();
	}

	/*
	����
	fmod���� 3d�� ���� ������ �̷��� �����ϸ� ��.

	3d���� �Ÿ��� ���� ����
	m_channel[0]->set3DminMaxDistance()

	3d ���� ��ġ�� ���� ����
	m_channel[0]->set3DCustomRolloff()

	*/
}

void soundManager::update()
{
	m_system->update();
}

void soundManager::render()
{
}

void soundManager::addSound(string keyName, string soundName, bool bgm, bool loop)
{
	if (loop)
	{
		//���
		if (bgm)
		{
			m_system->createStream(soundName.c_str(), FMOD_LOOP_NORMAL, nullptr, &m_sound[m_totalSounds.size()]);
		}

		//����Ʈ
		else
		{
			m_system->createSound(soundName.c_str(), FMOD_LOOP_NORMAL, nullptr, &m_sound[m_totalSounds.size()]);
		}
	}

	else
	{
		m_system->createSound(soundName.c_str(), FMOD_DEFAULT, nullptr, &m_sound[m_totalSounds.size()]);
	}

	m_totalSounds.insert(make_pair(keyName, &m_sound[m_totalSounds.size()]));
}

void soundManager::play(string keyName, float volume)
{
	int count = 0;
	arrSoundIter iter = m_totalSounds.begin();
	//ä�ο��� �÷��� �ؾ��ϴ� ī��Ʈ ������.
	for (iter; iter != m_totalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			m_system->playSound(FMOD_CHANNEL_FREE, *iter->second, false, &m_channel[count]);
			m_channel[count]->setVolume(volume);
		}
	}
}

void soundManager::stop(string keyName)
{
	int count = 0;
	arrSoundIter iter = m_totalSounds.begin();
	for (iter; iter != m_totalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			m_channel[count]->stop();
			break;
		}
	}
}

void soundManager::pause(string keyName)
{
	int count = 0;
	arrSoundIter iter = m_totalSounds.begin();

	for (iter; iter != m_totalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			m_channel[count]->setPaused(true);
			break;
		}
	}
}

void soundManager::resume(string keyName)
{
	int count = 0;
	arrSoundIter iter = m_totalSounds.begin();

	for (iter; iter != m_totalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			m_channel[count]->setPaused(false);
			break;
		}
	}
}

void soundManager::allStop()
{
	for (int i = 0; i < m_totalSounds.size(); ++i)
	{
		m_channel[i]->stop();
	}
}

bool soundManager::isPlaySound(string keyName)
{
	int count = 0;
	bool isPlay;

	arrSoundIter iter = m_totalSounds.begin();

	for (iter; iter != m_totalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			m_channel[count]->isPlaying(&isPlay);
			break;
		}
	}

	return isPlay;
}

bool soundManager::isPauseSound(string keyName)
{
	int count = 0;
	bool isPause;

	arrSoundIter iter = m_totalSounds.begin();

	for (iter; iter != m_totalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			m_channel[count]->getPaused(&isPause);
			break;
		}
	}

	return isPause;
}