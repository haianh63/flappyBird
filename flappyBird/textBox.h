#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
using namespace std;
class textBox
{
private:
	TTF_Font* font;
	SDL_Texture* textTexture = nullptr;
	SDL_Rect textRect{ 225,80,10,20};
	string text;
	SDL_Color color{ 255,255,255,0 };
public:
	void loadFont(string filepath, int size);
	void setText(string text, SDL_Renderer* ren);
	void draw(SDL_Renderer* ren);
	void setColor(int r, int g, int b, int a);
	~textBox();
};

