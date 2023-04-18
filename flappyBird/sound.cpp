#include "sound.h"

void sound::loadSound(string filepath)
{
	soundEffect = Mix_LoadWAV(filepath.c_str());
}
sound::~sound() {
	Mix_FreeChunk(soundEffect);
	soundEffect = nullptr;
}

void sound::playSound()
{
	Mix_PlayChannel(-1, soundEffect, 0);
}
