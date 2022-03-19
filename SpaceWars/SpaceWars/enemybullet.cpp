#include "enemybullet.h"
#include <graphics.h>

EnemyBullet::EnemyBullet(float pos_x, float pos_y)
{
	pos_x1 = pos_x; pos_y1 = pos_y;
}

void EnemyBullet::draw()
{
	graphics::Brush brush;
	brush.outline_opacity = 0.0f;
	brush.texture = std::string(ASSET_PATH) + "1shot.png";
	graphics::drawRect(pos_x1, pos_y1, 20, 20, brush);
	graphics::resetPose();
	if (graphics::getKeyState(graphics::SCANCODE_Z))
	{
		graphics::Brush br;
		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.3f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 0.3f;
		br.gradient = false;
		Disk hull = getCollisionHull();
		graphics::drawDisk(hull.cx, hull.cy, hull.radious, br);
	}
}

void EnemyBullet::drawBossShot()
{
	graphics::Brush brush;
	brush.outline_opacity = 0.0f;
	brush.texture = std::string(ASSET_PATH) + "bossShot.png";
	graphics::drawRect(pos_x1, pos_y1, 20, 20, brush);
	graphics::resetPose();
	if (graphics::getKeyState(graphics::SCANCODE_Z))
	{
		graphics::Brush br;
		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.3f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 0.3f;
		br.gradient = false;
		Disk hull = getCollisionHull();
		graphics::drawDisk(hull.cx, hull.cy, hull.radious, br);
	}
}

void EnemyBullet::update()
{
	pos_y1 += speed * graphics::getDeltaTime() / 10.0f;

	if (pos_y1 > CANVAS_HEIGHT )
	{
		active = false;
	}
}



void EnemyBullet::init()
{
}



Disk EnemyBullet::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x1;
	disk.cy = pos_y1;
	disk.radious = 7.07f;
	return disk;
}
