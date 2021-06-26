#ifndef GRAPHICALSCENE_H
#define GRAPHICALSCENE_H

#include <vector>
#include <iostream>
#include <SDL2/SDL.h>

#include "graphicalplan.h"
#include "graphicalobject.h"

class GraphicalScene
{
public:
	GraphicalScene();
	~GraphicalScene();

	void displayGame();
	void addPlan(float scrollingSpeed);
	void addObjectToPlan(GraphicalObject * pObject, int plan);

private:
	std::vector<GraphicalPlan*> _plans;
};

#endif // GRAPHICALSCENE_H
