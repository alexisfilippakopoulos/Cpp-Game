#pragma once
#include "gameobject.h"
#include "graphics.h"
class Enemy : public GameObject, public Collidable
{
    float pos_x1, pos_y1;
    float speed;
    float size;
    graphics::Brush brush;
    bool active = true;
    float life;
public:
    void drawBoss();
    void updateBoss();
    void drawPreBoss();
    void draw();
    void update() override;
    void update1();
    void update2();
    void drawbosslife(Enemy* i);
    void init() override;    float getPosY()  { return pos_y1; }
    float getPosX() { return pos_x1; }
    bool isActive() { return active; }
    float get_enemylife() { return life; }
    void  drainEnemyLife(float amount) { life = std::max< float>(0.0f, life - amount); }
    Enemy(float l,float pos_x, float pos_y,float si,float sp);
    ~Enemy();
    void drawx();
    void updatex();
    void updatex1();
    Disk getCollisionHull() const override;
};

