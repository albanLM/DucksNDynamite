#include "window.h"

Window *Window::_instance = nullptr;

Window::Window()
{
	/* Initializing SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "Error while initializing SDL: " << SDL_GetError() << "\n";
	}

	// Load support for the JPG and PNG image formats
	int flags = IMG_INIT_JPG|IMG_INIT_PNG;
	int imgSupport = IMG_Init(flags);
	if((imgSupport & flags) != flags) {
		std::cerr << "Error while initializing image support by SDL_Image: " << IMG_GetError() << "\n";
		IMG_Quit();
		SDL_Quit();
	}

	createWindow();
}

Window::~Window(){
	destroyWindow();

	IMG_Quit();
	SDL_Quit();
}

Window* Window::Instance()
{
	if (_instance == nullptr)
	{
		_instance = new Window;
	}
	return _instance;
}

void Window::createWindow()
{
	_pSdlWindow = SDL_CreateWindow("Ducks N Dynamite",
	                           SDL_WINDOWPOS_UNDEFINED,
	                           SDL_WINDOWPOS_UNDEFINED,
	                           _width,
	                           _height,
	                           SDL_WINDOW_SHOWN);
	if(_pSdlWindow)
	{
		_pRenderer = SDL_CreateRenderer(_pSdlWindow,-1,SDL_RENDERER_ACCELERATED);
		if (_pRenderer)
		{
			SDL_SetRenderDrawColor(_pRenderer, 0, 0, 0, 255);
		}
	}
}

void Window::destroyWindow()
{
	SDL_DestroyRenderer(_pRenderer);
	SDL_DestroyWindow(_pSdlWindow);
}

int Window::height() const
{
	return _height;
}

int Window::width() const
{
	return _width;
}

SDL_Renderer *Window::pRenderer() const
{
	return _pRenderer;
}


void Window::resize(int width, int height)
{
	destroyWindow();
	_width = width;
	_height = height;
	createWindow();
}
