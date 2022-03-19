#pragma once

#pragma once
#include "gameObject.h"
#include "graphics.h"

class Bullet :  public Collidable {

	float pos_x1, pos_y1;
	float speed=0.7f;
	graphics::Brush brush;// sou iposxomai oti iparxei
	bool active = true;

public:

	float getPosY() { return pos_y1; }
	float getPosX() { return pos_x1; }
	void update();
	void draw() ;
	void init() ;
	bool isActive() { return active; }
	Bullet(float pos_x,float pos_y);
	Disk getCollisionHull() const override;


};
