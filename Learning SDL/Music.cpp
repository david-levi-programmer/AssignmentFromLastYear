#include <iostream>
#include "Music.h"

bool Music::Initialize()
{
	if(Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024) == -1)
	{
		std::cout << "Error initalising audio system." << std::endl;
		return false;
	}

	return true;
}

void Music::Shutdown()
{
	Mix_CloseAudio();
}

bool Music::Load(const std::string& filename)
{
	m_music = Mix_LoadMUS(filename.c_str());

	if (!m_music)
	{
		std::cout << "Error loading audio file." << std::endl;
		return false;
	}

	return true;
}

void Music::Unload()
{
	Mix_FreeMusic(m_music);
}

void Music::SetVolume(int volume)
{
	float normalizedValue = volume / 128;
	Mix_VolumeMusic(volume);
}

void Music::Play(PlayLoop playLoop)
{
	if(!Mix_PlayingMusic())
	{
		if(Mix_PlayMusic(m_music, static_cast<int>(playLoop)) == -1)
		{
			std::cout << "Error playing audio file." << std::endl;
		}
	}
}

void Music::Pause()
{
	if (Mix_PausedMusic())
	{
		Mix_PauseMusic();
	}
}

void Music::Resume()
{
	if (!Mix_PausedMusic())
	{
		Mix_ResumeMusic();
	}
}

void Music::Stop()
{
	if (Mix_PlayingMusic())
	{
		Mix_HaltMusic();
	}
}