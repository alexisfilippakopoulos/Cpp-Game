#pragma once
#pragma once

#include "gameobject.h"
#include "config.h"

class EnemyBullet : public Collidable
{
	float speed = 3.0f;
	float pos_x1, pos_y1;
	bool active = true;
public:

	EnemyBullet(float pos_x, float pos_y);
	void draw();
	void drawBossShot();
	void update();

	void init();
	bool isActive() { return active; }
	float getPosY() { return pos_y1; }
	float getPosX() { return pos_x1; }
	Disk getCollisionHull() const override;

};