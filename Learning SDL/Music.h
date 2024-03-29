#pragma once

#include <SDL_mixer.h>
#include <string>

class Music
{

public:

	enum class PlayLoop { PlayOnce = 1, PlayEndless = -1 };
	static bool Initialize();
	static void Shutdown();

	Music() {}
	bool Load(const std::string& filename);
	void Unload();

	void SetVolume(int volume);

	void Play(PlayLoop playLoop);
	void Pause();
	void Resume();
	void Stop();

private:

	Mix_Music* m_music = nullptr;

};