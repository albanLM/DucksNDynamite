#include "graphical_scene.h"

GraphicalScene::GraphicalScene()
{

}

GraphicalScene::~GraphicalScene()
{
	for (auto i = _plans.rbegin() ; i != _plans.rend(); i++)
	{
		delete *i;
	}
}

void GraphicalScene::displayGame()
{
	Window* pWindow = Window::Instance();
	SDL_RenderClear(pWindow->pRenderer());
	for (auto i = _plans.rbegin() ; i != _plans.rend(); i++)
	{
		(*i)->display();
	}
	SDL_RenderPresent(pWindow->pRenderer());
}

void GraphicalScene::addPlan(float scrollingSpeed)
{
	GraphicalPlan * pGraphicalPlan = new GraphicalPlan(scrollingSpeed);
	_plans.push_back(pGraphicalPlan);
}

void GraphicalScene::addObjectToPlan(GraphicalObject *pObject, int plan)
{
	if((int)_plans.size()>plan) _plans.at(plan)->addObject(pObject);
}
