#pragma once
#include "gameobject.h"

class AddHp :public Collidable
{
	float pos_x;
	float pos_y;
	float size;
public:
	void draw();
	void update();
	void init();
	AddHp(float size1, float posx,float posy);
	Disk getCollisionHull() const override;
};