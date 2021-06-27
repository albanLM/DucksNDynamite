#ifndef GRAPHICALPLAN_H
#define GRAPHICALPLAN_H

#include <vector>
#include <iostream>

#include "graphical_object.h"
#include "window.h"

class GraphicalPlan
{
public:
	explicit GraphicalPlan(float scrollingSpeed);
	~GraphicalPlan();

    void addObject(GraphicalObject * pObject);
	void display();

	void setScrollingSpeed(float scrollingSpeed);

private:
	float _scrollingSpeed;
	std::vector<GraphicalObject *> _objects;
};

#endif // GRAPHICALPLAN_H
