#include "enemy.h"
#include "graphics.h"
#include "util.h"
#include "SpaceWars.h"
#include "config.h"

void Enemy::update()
{
    if (pos_y1<=CANVAS_HEIGHT/4)
    {
        pos_y1 += speed * graphics::getDeltaTime() / 5.0f;
        pos_x1 += speed * graphics::getDeltaTime() / 5.0f;
    }
    if (pos_y1 > CANVAS_HEIGHT / 4 && pos_y1<=CANVAS_HEIGHT/2)
    {
        pos_y1 += speed * graphics::getDeltaTime() / 5.0f;
    }
    if (pos_y1 > CANVAS_HEIGHT / 2)
    {
        pos_y1 += speed * graphics::getDeltaTime() / 5.0f;
        pos_x1 -= speed * graphics::getDeltaTime() / 5.0f;
    }
    if (pos_y1 > CANVAS_HEIGHT)
    {
        active = false;
    }

}

void Enemy::drawbosslife(Enemy * i)
{
    // zwh enemy
    graphics::Brush bru;
    float boss_life = i ? i->get_enemylife() : 0.0f;
    bru.outline_opacity = 0.0f; // aspro perigramma 
    bru.fill_color[0] = 1.3f;
    bru.fill_color[1] = 1.9f;
    bru.texture = ""; //sbinw texture
    bru.fill_secondary_color[0] = 1.09f * (1 - boss_life) + boss_life * 0.2f; // analoga me thn zwi exei pio skoyro h pio anoixto xrwma 
    bru.fill_secondary_color[1] = 0.2f;
    bru.fill_secondary_color[2] = 0.2f * (1 - boss_life) + boss_life * 1.0f;
    bru.gradient = true; // etsi kanei fade ton apo panw xrwmatwn 
    // kanw to fade orizodio
    bru.gradient_dir_u = 1.0f;
    bru.gradient_dir_v = 0.0f;
    graphics::drawRect(i->getPosX() - ((1 - boss_life) * 150 / 2), i->getPosY() - 55, boss_life * 150, 3, bru); // h zwh sbinei apo dexi aaristera 
    bru.outline_opacity = 0.0f;
    bru.gradient = false;
    bru.fill_opacity = 0.0f;
    graphics::drawRect(i->getPosX(), i->getPosY() - 55, 150, 3, bru); // to perigramma pisw apo thn zvw sta8ero na mhn fengei otan xanw zvh 
}

void Enemy::update2()
{
    pos_y1 += speed * graphics::getDeltaTime() / 5.0f;
    if (pos_y1 > CANVAS_HEIGHT+size)
    {
        active = false;
    }
}





void Enemy::update1()
{

    if (pos_y1 <= CANVAS_HEIGHT / 4)
    {
        pos_y1 += speed * graphics::getDeltaTime() / 5.0f;
        pos_x1 -= speed * graphics::getDeltaTime() / 5.0f;
    }
    if (pos_y1 > CANVAS_HEIGHT / 4 && pos_y1 <= CANVAS_HEIGHT / 2)
    {
        pos_y1 += speed * graphics::getDeltaTime() / 5.0f;
    }
    if (pos_y1 > CANVAS_HEIGHT / 2)
    {
        pos_y1 += speed * graphics::getDeltaTime() / 5.0f;
        pos_x1 += speed * graphics::getDeltaTime() / 5.0f;
    }
    if (pos_y1 > CANVAS_HEIGHT)
    {
        active = false;
    }
}

void Enemy::drawBoss()
{
    brush.texture = std::string(ASSET_PATH) + "finalBoss.png";
    brush.fill_opacity = 1.0f;
    brush.outline_opacity = 0.0f;
    graphics::drawRect(pos_x1, pos_y1, size+30, size-40, brush);
    graphics::resetPose();
    brush.texture = std::string(ASSET_PATH) + "engineboss.png";
    graphics::drawRect(pos_x1, pos_y1 -25 ,20 , 20, brush);
    if (graphics::getKeyState(graphics::SCANCODE_T))
    {
        graphics::Brush br;
        br.outline_opacity = 1.0f;
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

void Enemy::drawPreBoss()
{
    brush.texture = std::string(ASSET_PATH) + "preboss.png";
    brush.fill_opacity = 1.0f;
    brush.outline_opacity = 0.0f;
    graphics::drawRect(pos_x1, pos_y1, size, size, brush);
    graphics::resetPose();
    if (graphics::getKeyState(graphics::SCANCODE_T))
    {
        graphics::Brush br;
        br.outline_opacity = 1.0f;
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

void Enemy::updateBoss()
{
    // dejia arister akinhsh
        float offset = 400 * sinf(graphics::getGlobalTime() / 3000.0f) / 6;
        pos_x1 -= offset / 200 ;

    
}

void Enemy::draw()
{
    // enmy draw
    float t = 50 * cosf(graphics::getGlobalTime() / 1000.0f);
    float offset = CANVAS_HEIGHT * sinf(graphics::getGlobalTime() / 1000.0f) / 6;

    brush.outline_opacity = 0.0f;
    graphics::setOrientation(-180.0f);
    brush.texture = std::string(ASSET_PATH) + "boss_2.png";
    graphics::drawRect(pos_x1, pos_y1, size, size, brush);
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



void Enemy::init()
{

}


void Enemy::updatex1()
{// kinhsh diagvnia
    pos_y1 += speed * graphics::getDeltaTime() / 3.0f;
    pos_x1 += speed * graphics::getDeltaTime() / 3.0f;


    if (pos_y1 > CANVAS_HEIGHT+size)
    {
        active = false;
    }
}

Enemy::Enemy(float l, float pos_x, float pos_y, float si,float sp)
{//constaructor
    float t = 50 * cosf(graphics::getGlobalTime() / 1000.0f);
    float offset = CANVAS_HEIGHT * sinf(graphics::getGlobalTime() / 1000.0f) / 6;
    pos_x1 = pos_x;
    pos_y1 = pos_y;
    life = l;
    size = si;
    speed = sp;
}

Enemy::~Enemy()
{
}
void Enemy::drawx()
{
    graphics::Brush brush;
    float t = 50 * cosf(graphics::getGlobalTime() / 1000.0f);
    float offset = CANVAS_HEIGHT * sinf(graphics::getGlobalTime() / 1000.0f) / 6;

    brush.outline_opacity = 0.0f;
    graphics::setOrientation(-180.0f);
    brush.texture = std::string(ASSET_PATH) + "boss_1.png";
    graphics::drawRect(pos_x1, pos_y1, size, size, brush);
    graphics::resetPose();

    // collision
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




void Enemy::updatex()
{
    // kinhsh enemy
    pos_y1 += speed * graphics::getDeltaTime() / 3.0f;
    pos_x1 -= speed * graphics::getDeltaTime() / 3.0f;

    if (pos_y1 > CANVAS_HEIGHT+size)
    {
        active = false;
    }
}

Disk Enemy::getCollisionHull() const
{
    Disk disk;
    disk.cx = pos_x1 ;
    disk.cy = pos_y1 ;
    disk.radious = size * 0.45f;
    return disk;
}