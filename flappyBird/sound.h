#pragma once
#include <SDL_mixer.h>
#include <SDL.h>
#include <string>
using namespace std;
class sound
{
private:
	Mix_Chunk* soundEffect = nullptr;
public:
	void loadSound(string filepath);
	~sound();
	void playSound();
};

