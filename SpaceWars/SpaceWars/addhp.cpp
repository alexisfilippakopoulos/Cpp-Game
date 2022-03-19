#include "addhp.h"
#include "graphics.h"
#include "config.h"
void AddHp::draw()
{
	graphics::Brush brush;
	brush.outline_opacity = 0.0f;
	brush.texture = std::string(ASSET_PATH) + "addhp.png";
	graphics::drawRect(pos_x, pos_y, size, size, brush);
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

void AddHp::update()
{
	pos_y += 0.1 * graphics::getDeltaTime() / 5.0f;
}

void AddHp::init()
{
}

//constractor
AddHp::AddHp(float size1, float posx,float posy)
{
	pos_x = posx;
	pos_y = posy;
	size = size1;
}

Disk AddHp::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radious =size*0.45f;
	return disk;
}
