#include "bullet.h"
#include "config.h"


void Bullet::update()
{
	// kinhsh enemy
	pos_y1 -= speed * graphics::getDeltaTime();
	
	
	if (pos_y1 < 0) {
		active = false;
	}

}

void Bullet::draw()
{// sxediasi bullet
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

void Bullet::init()
{
}

Bullet::Bullet(float pos_x,float pos_y)

{
	pos_x1 = pos_x;
	pos_y1 = pos_y;
}

//collision
Disk Bullet::getCollisionHull() const
{
	Disk disk;
	disk.cy = pos_y1;
	disk.cx = pos_x1;
	disk.radious = 7.07f;
	return disk;
}

