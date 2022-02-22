#include "Sound.h"
#include <iostream>

Sound::Sound()
{

}

bool Sound::Load(const std::string& filename)
{
	m_sound = Mix_LoadWAV(filename.c_str());

	if (!m_sound)
	{
		std::cout << "Error loading audio file." << std::endl;
		return false;
	}

	return true;
}

void Sound::Unload()
{
	Mix_FreeChunk(m_sound);
}

void Sound::SetVolume(int volume)
{
	Mix_VolumeChunk(m_sound, volume);
}

void Sound::Play(int loop)
{
	static int channel = 0;

	if ((channel = Mix_PlayChannel(0, m_sound, loop)) == -1)
	{
		std::cout << "Error playing audio file." << std::endl;
	}
}