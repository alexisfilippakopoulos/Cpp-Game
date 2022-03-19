#pragma once
#include "player.h"
#include "bullet.h"
#include "meteorite.h"
#include "Enemy.h"
#include "enemybullet.h"
#include "addhp.h"
	
class SpaceWars
{
	typedef enum { STATUS_START, STATUS_PLAYING, STATUS_CHOOSE, STATUS_BOSS, STATUS_END, STATUS_PAUSE, STATUS_INSTRUCTIONS } status_t;
	status_t status = STATUS_START;
	Player* player = nullptr;

	bool player_initialized = false;
	bool sound1 = true;

	Bullet* bullet[4] = { nullptr,nullptr };

	int numbullets = 0;
	Meteorite* meteorite = nullptr;

	void spawnbullet();
	void checkbullet();

	Enemy* enemy[5] = { nullptr,nullptr, nullptr, nullptr, nullptr };

	Enemy* boss = nullptr;
	int numboss = 0;
	void spawnboss();
	bool boss_init = true;

	Meteorite* meteorCircle[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

	float offsetX;
	float offsetY;
	Meteorite* Circle[8] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
	void spawnCircle(int i);
	void checkCircle(int i);
	float offsetXc;
	float offsetYc;
	int numc = 0;

	Meteorite* meteorBig = nullptr;

	Enemy* preboss[3] = { nullptr, nullptr, nullptr };
	int numofpreboss = 0;
	float offset = 250;

	Enemy* x[4] = { nullptr,nullptr,nullptr,nullptr };

	void spawnenemyx(int i);
	void checkenemyx(int i);
	float posx_;
	float posy_;
	int numx = 0;

	void spawnPreBoss(int i);

	void spawnMeteorCircle(int i);
	void checkMeteorCircle(int i);

	void spawnMeteorBig();
	void checkMeteorBig();

	void spawnenemy(int i);
	void checkenemy(int i);
	int numenemies = 0;
	float posofboss = 0.0f;
	float t;


	EnemyBullet* enemyBullet[5] = { nullptr,nullptr, nullptr, nullptr, nullptr };
	void spawnEnemybullet(int i, int j);
	void checkEnemybullet(int i);

	EnemyBullet* bossBullet;
	void spawnBossbullet();
	void checkBossbullet();
	float x1;


	EnemyBullet* bossBulletAdv[2] = {nullptr,nullptr};
	void spawnBossBulletAdv(int i);
	void checkBossBulletAdv(int i);



	AddHp* addhp = nullptr;
	int numaddhp = 0;
	float s;
	void spawnaddhp();
	




	void updateStartScreen();
	void updateLevelScreen();

	void drawStartScreen();
	void drawLevelScreen();

	void updatePauseScreen();
	void updateEndScreen();

	void drawPauseScreen();
	void drawEndScreen();

	void updateChooseScreen();
	void drawChooseScreen();


	void spawnmeteorite();
	void checkmeteorite();

	bool checkcollision_enemyshot(int i, int j); 
	bool checkcollision_prebossshot(int i, int j);
	bool checkcollision_xshot(int i, int j);
	bool checkcollision_meteorCircleshot(int i, int j);
	bool checkcollision_Circleshot(int i, int j);
	bool checkcollision_meteoriteshot(int i);
	bool checkcollision_meteoriteplayer();
	bool checkcollision_enemybulletplayer(int i);
	bool checkcollision_meteorBigshot(int i);
	bool checkcollision_meteorBigplayer();
	bool checkcollision_meteorCircleplayer(int i);
	bool checkcollision_playeraddhp();
	bool checkcollision_Circleplayer(int i);
	bool checkcollision_xplayer(int i);
	bool checkcollision_bossShot(int i);
	bool checkcollision_bossShotToPlayer();
	bool checkcollision_bossShotAdvToplayer(int i);


	void soundHitEnemy();
	void soundBossEnter();
	void soundShot();
	void soundExplosion();
	void soundHitMeteor();
	void soundMaintheme();
	void soundSpacecraftHit();
	void soundDeath();
	void soundHpadd();
	void soundwin();
	void spawnenemyx();
	void checkenemyx();
	void soundBossDeath();

	void GameDelete();
	int spacecraft;

	int score = 0;
	int score1 = 0;

public:
	void draw();
	void update();
	void init();

	SpaceWars();
	~SpaceWars(); 
	bool f = false;
};