#include "graphicalplan.h"

GraphicalPlan::GraphicalPlan(float scrollingSpeed): _scrollingSpeed(scrollingSpeed)
{

}

void GraphicalPlan::addObject(GraphicalObject *pObject)
{
	_objects.push_back(pObject);
}

void GraphicalPlan::display()
{
	Window * pWindow = Window::Instance();

	SDL_Rect spriteRect;
	Spritesheet * pSpritesheet;
	float sizeCoef, x, y;
	SDL_RendererFlip flip;

	for (std::vector<GraphicalObject *>::iterator i = _objects.begin() ; i != _objects.end(); i++)
	{
		spriteRect = (*i)->spriteRect().toSdlRect();
		pSpritesheet = (*i)->pSpritesheet();
		sizeCoef = (*i)->sizeCoef();
		x = (*i)->x();
		y = (*i)->y();
		flip = (*i)->flip();

		SDL_Rect renderRect = {(int)(pWindow->width()/2 - spriteRect.w/2*sizeCoef + x),
		                       (int)(pWindow->height()/2 - spriteRect.h/2*sizeCoef + y),
		                       (int)(spriteRect.w*sizeCoef),
		                       (int)(spriteRect.h*sizeCoef)};

		SDL_RenderCopyEx(pWindow->pRenderer(),pSpritesheet->pTexture(),&spriteRect,&renderRect,0.0,NULL,flip);
	}
}

void GraphicalPlan::setScrollingSpeed(float scrollingSpeed)
{
    _scrollingSpeed = scrollingSpeed;
}
