#include "meteorite.h"
#include "graphics.h"
#include "config.h"
#include <random>
#include "util.h"
#include "SpaceWars.h"

void Meteorite::update()
{   // kinhsh enemy
	pos_y += speed * graphics::getDeltaTime()/3.0f;
	// peristorfi emeny
	rotation += 0.05f * graphics::getDeltaTime();
	// epanemfanisi enemy
	rotation = fmodf(rotation, 360);
	if (pos_y >CANVAS_HEIGHT) {
		active = false;
	}
}

void Meteorite::draw()
{
	graphics::setOrientation(rotation);
	brush.texture = std::string(ASSET_PATH) + "asteroid.png";
	brush.fill_opacity = 1.0f;
	graphics::drawRect(pos_x, pos_y, size, size, brush);
	graphics::resetPose(); // eleu8erwnw mnhmh apo enemy
	if (graphics::getKeyState(graphics::SCANCODE_T))
	{
		graphics::Brush br;
		br.outline_opacity = 1.0f; //8elw na blepw perigramma 
		br.texture = "";
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.3f;
		br.fill_color[2] = 0.5f;// xrwma
		br.gradient = false;
		br.fill_opacity = 0.3f; // na einai diafanew
		Disk hull = getCollisionHull();
		graphics::drawDisk(hull.cx, hull.cy, hull.radious, br);
	}
}

Meteorite::Meteorite(float s,float l,float sp,float psx,float psy)
{
	init();
	size = s;
	life = l;
	speed = sp;
	pos_x = psx;
	pos_y = psy;
}

void Meteorite::init()
{
	rotation = 360 * rand0to1();
	brush.outline_opacity = 0.0f;
}



Meteorite::~Meteorite()
{
}


Disk Meteorite::getCollisionHull() const
{
	Disk disk;
	disk.cy = pos_y;
	disk.cx = pos_x;
	disk.radious = size * 0.45f;
	return disk;
}

