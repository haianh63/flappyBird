#include "textBox.h"

void textBox::loadFont(string filepath, int size)
{
	font = TTF_OpenFont(filepath.c_str(),size);
}

void textBox::setText(string text, SDL_Renderer *ren)
{
	if (this->text != text && text != "") {
		if (textTexture != nullptr) {
			SDL_DestroyTexture(textTexture);
		}
		this->text = text;

		SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
		textTexture = SDL_CreateTextureFromSurface(ren, surface);
		SDL_FreeSurface(surface);
		SDL_QueryTexture(textTexture, nullptr, nullptr, &textRect.w, &textRect.h);
		textRect.x = 480 / 2 - textRect.w / 2;
	}
}

void textBox::draw(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, textTexture, nullptr, &textRect);
}

void textBox::setColor(int r, int g, int b, int a)
{
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
}

textBox::~textBox()
{
	if (textTexture != nullptr) {
		SDL_DestroyTexture(textTexture);
	}
	TTF_CloseFont(font);
}
