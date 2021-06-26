#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Window
{
public:
	~Window();

	static Window* Instance();

	void resize(int width, int height);

	SDL_Renderer *pRenderer() const;
	int width() const;
	int height() const;

private :
	Window();
	void createWindow();
	void destroyWindow();

	static Window * _instance;
	SDL_Window* _pSdlWindow;
	SDL_Renderer* _pRenderer;

	int _width = 640;
	int _height = 480;
};

#endif // WINDOW_H
