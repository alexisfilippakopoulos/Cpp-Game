#pragma once

#include "gameobject.h"
#include "config.h"

class Player : public GameObject , public Collidable
{
	float speed = 13.0f;
	float pos_x = CANVAS_WIDTH / 2, pos_y = CANVAS_HEIGHT - 100.0f;
	float life = 1.0f; // gai zwh 
	int i = 0;
public:
	void draw1();
	void draw2();
	void draw3();
	void update() override;
	void init() override;
	void drawlife(Player * i);
	Disk  getCollisionHull() const override;
	float getPosY() { return pos_y; }
	float getPosX() { return pos_x; }
	float getLife() const { return life; } //gia na kanw xrisi tiw pliroforias life 
	void  drainLife(float amount) { life = std::max< float>(0.0f, life - amount); } // meivne zwh alla mhn pas katw apo 0
	void soundFire();
};