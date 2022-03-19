#pragma once
#include "gameobject.h"
#include "graphics.h"

class Meteorite : public  GameObject, public Collidable {

	float pos_x, pos_y;
	float size;
	float rotation;
	float speed;
	graphics::Brush brush;// sou iposxomai oti iparxei
	bool active = true;
	float life;
public:

	void update() override;
	void draw();
	void init() override;
	bool isActive() { return active; }
	float getLife() { return life; }
	void drainLife(float amount) { life = life - amount; }
	float getMeteorCirclePosX() { return pos_x; }
	float getMeteorCirclePosy() { return pos_y; }
	Meteorite(float s,float l,float sp, float psx, float psy);
	~Meteorite();
	Disk getCollisionHull() const override;


}; 