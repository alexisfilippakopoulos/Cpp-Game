#include "player.h"
#include "graphics.h"
#include "SpaceWars.h"


// draw gia plalyer 1
void Player::draw1()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "player_1.png";
	br.outline_opacity = 0.0f;

	//draw backround
	graphics::drawRect(pos_x, pos_y, 100, 60, br);

	if (graphics::getKeyState(graphics::SCANCODE_T))
	{
		br.outline_opacity = 1.0f; //8elw na blepw perigramma 
		br.texture = "";
		br.fill_color[0] = 0.3f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 0.5f;// xrwma
		br.gradient = false;
		br.fill_opacity = 0.0f; // na einai diafanew
		Disk hull = getCollisionHull();
		graphics::drawDisk(hull.cx, hull.cy, hull.radious, br);
	}

	// draw ble fvtia
	br.texture = std::string(ASSET_PATH) + "engine1.png";
	br.outline_opacity = 0.0f;

	graphics::Brush bru;
	//draw fwtia otan xanei zwh 
	graphics::drawRect(getPosX(), getPosY() + 27, 20, 20, br);

	bru.texture = std::string(ASSET_PATH) + "fire.png";
	bru.outline_opacity = 0.0f;

	if (getLife() < 0.75f && getLife() > 0.5f)
	{
		//draw fwtia
		graphics::drawRect(getPosX(), getPosY() - 20, 50, 50, bru);
		//sound gia fwtia
		if (i == 0) {
			soundFire();
			i++;
		}

	}
	else if (getLife() < 0.5f && getLife() > 0.25f)
	{
		graphics::drawRect(getPosX(), getPosY() - 20, 50, 50, bru);
		graphics::drawRect(getPosX() + 30, getPosY() - 15, 50, 50, bru);
		if (i == 1) {
			soundFire();
			i++;
		}
	}
	else if (getLife() <= 0.25f)
	{
		graphics::drawRect(getPosX(), getPosY() - 20, 50, 50, bru);
		graphics::drawRect(getPosX() + 30, getPosY() - 15, 50, 50, bru);
		graphics::drawRect(getPosX() - 30,getPosY() - 15, 50, 50, bru);
		if (i == 2) {
			soundFire();
			i=0;
		}
	}
	
}

void Player::draw2()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "player_2.png";
	br.outline_opacity = 0.0f;

	//draw backround
	graphics::drawRect(pos_x, pos_y, 100, 60, br);

	if (graphics::getKeyState(graphics::SCANCODE_T))
	{
		br.outline_opacity = 1.0f; //8elw na blepw perigramma 
		br.texture = "";
		br.fill_color[0] = 0.3f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 0.5f;// xrwma
		br.gradient = false;
		br.fill_opacity = 0.0f; // na einai diafanew
		Disk hull = getCollisionHull();
		graphics::drawDisk(hull.cx, hull.cy, hull.radious, br);
	}

	br.texture = std::string(ASSET_PATH) + "engine1.png";
	br.outline_opacity = 0.0f;

	// draw ble fvtia po
	graphics::drawRect(getPosX(), getPosY() + 33, 20, 20, br);

	graphics::Brush bru;

	bru.texture = std::string(ASSET_PATH) + "fire.png";
	bru.outline_opacity = 0.0f;
	//draw fwtia otan xanei zwh 
	if (getLife() < 0.75f && getLife() > 0.5f)
	{


		graphics::drawRect(getPosX(), getPosY() - 20, 50, 50, bru);
		if (i == 0) {
			soundFire();
			i++;
		}


	}
	else if (getLife() < 0.5f && getLife() > 0.25f) {
		graphics::drawRect(getPosX(), getPosY() - 20, 50, 50, bru);
		graphics::drawRect(getPosX() + 40, getPosY() - 20, 50, 30, bru);
		if (i == 1) {
			soundFire();
			i++;
		}


	}
	else if (getLife() <= 0.25f) {
		graphics::drawRect(getPosX(), getPosY() - 20, 50, 50, bru);
		graphics::drawRect(getPosX() + 40,getPosY() - 20, 50, 30, bru);
		graphics::drawRect(getPosX() - 40, getPosY() - 20, 50, 30, bru);
		if (i == 2) {
			soundFire();
			i = 0;
		}
	}

}

void Player::draw3()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "player_3.png";
	br.outline_opacity = 0.0f;

	//draw backround
	graphics::drawRect(pos_x, pos_y, 100, 60, br);

	if (graphics::getKeyState(graphics::SCANCODE_T))
	{
		br.outline_opacity = 1.0f; //8elw na blepw perigramma 
		br.texture = "";
		br.fill_color[0] = 0.3f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 0.5f;// xrwma
		br.gradient = false;
		br.fill_opacity = 0.0f; // na einai diafanew
		Disk hull = getCollisionHull();
		graphics::drawDisk(hull.cx, hull.cy, hull.radious, br);
	}

	br.texture = std::string(ASSET_PATH) + "engine1.png";
	br.outline_opacity = 0.0f;

	//draw fwtia ble
	graphics::drawRect(getPosX(), getPosY() + 30, 16, 20, br);

	graphics::Brush bru;
	bru.texture = std::string(ASSET_PATH) + "fire.png";
	bru.outline_opacity = 0.0f;
	
	if (getLife() < 0.75f && getLife() > 0.5f)
	{
		//draw fwtia otan xanei zwh 
		graphics::drawRect(getPosX(), getPosY() - 20, 50, 50, bru);
		if (i == 0) {
			soundFire();
			i++;
		}
	}
	else if (getLife() < 0.5f && getLife() > 0.25f) {
		graphics::drawRect(getPosX(), getPosY() - 20, 50, 50, bru);
		graphics::drawRect(getPosX() + 30, getPosY() + 12, 50, 30, bru);
		if (i == 1) {
			soundFire();
			i++;
		}

	}
	else if (getLife() <= 0.25f) {
		graphics::drawRect(getPosX(), getPosY() - 20, 50, 50, bru);
		graphics::drawRect(getPosX() + 30, getPosY() + 12, 50, 30, bru);
		graphics::drawRect(getPosX() - 30, getPosY() + 12, 50, 30, bru);
		if (i == 2) {
			soundFire();
			i = 0;
		}
	}
}

void Player::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_A))//aristera
	{
		pos_x -= speed * graphics::getDeltaTime() / 30.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_D))//dejia
	{
		pos_x += speed * graphics::getDeltaTime() / 30.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_W))//panw
	{
		pos_y -= speed * graphics::getDeltaTime() / 30.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_S))//katw
	{
		pos_y += speed * graphics::getDeltaTime() / 30.0f;
	}


	if (pos_x < 50) pos_x = 50;
	if (pos_x > CANVAS_WIDTH-50) pos_x = CANVAS_WIDTH - 50;
	if (pos_y < 30)pos_y = 30;
	if (pos_y > CANVAS_HEIGHT - 30)pos_y = CANVAS_HEIGHT - 30;
}

void Player::init()
{
}

void Player :: drawlife(Player * i) {

	graphics::Brush br;
	// gia mpara zwhs paixth
	float player_life = i ? i->getLife() : 0.0f;
	br.outline_opacity = 0.0f; // aspro perigramma 
	br.fill_color[1] = 0.2f;
	br.fill_color[0] = 1.0f;
	br.fill_color[2] = 0.0f;
	br.texture = ""; //sbinw texture
	br.fill_secondary_color[1] = 1.0f * (1 - player_life) + player_life * 1.0f; // analoga me thn zwi exei pio skoyro h pio anoixto xrwma 
	br.fill_secondary_color[0] = 0.5f * (1 - player_life) + player_life * 0.2f;
	br.fill_secondary_color[2] = 0.0f;
	br.gradient = true; // etsi kanei fade ton apo panw xrwmatwn 
	// kanw to fade orizodio
	br.gradient_dir_u = 1.0f;
	br.gradient_dir_v = 0.0f;
	graphics::drawRect(CANVAS_WIDTH - 100 - ((1 - player_life) * 120 / 2), 30, player_life * 120, 20, br); // h zwh sbinei apo dexi aaristera 
	br.outline_opacity = 1.0f;
	br.gradient = false;
	br.fill_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH - 100, 30, 120, 20, br); // to perigramma pisw apo thn zvw sta8ero na mhn fengei otan xanw zvh 

}

Disk Player::getCollisionHull() const
{
	Disk disk;
	disk.cy = pos_y;
	disk.cx = pos_x;
	disk.radious = 55.0f;
	return disk;
	
}

void Player::soundFire()
{
	graphics::playSound(std::string(ASSET_PATH) + "firee.wav", 0.3f, false);
}
