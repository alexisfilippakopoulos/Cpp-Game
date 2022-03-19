#include "SpaceWars.h"
#include "graphics.h"
#include "config.h"

// dhmiourgei sfaira an den exoyme 
void SpaceWars::spawnbullet()
{
	soundShot();
	if (!bullet[numbullets])
	{
		bullet[numbullets] = new Bullet(player->getPosX(), player->getPosY());
		numbullets++;
	}
}


// diagrafei thn sfaira an bgei apo to plaisio
void SpaceWars::checkbullet()

{
	if (numbullets == 4)
	{
		numbullets = 0;
	}
	if (bullet[numbullets] && !bullet[numbullets]->isActive())
	{
		delete bullet[numbullets];
		bullet[numbullets] = nullptr;
	}
}

// dhmioyrge tous enemy poy erxontai diagvnia
void SpaceWars::spawnenemyx(int i)
{
	// an exoyn dhmioyrgh8ei hdh 2
	if (!x[i] && numx < 4)
	{
		x[i] = new Enemy(4,posx_, 0.0f+posy_,70,0.13f);
		numx++;
	}

}

//digrafei toys enemy poy erxontai diagvnia an einai ektos plaisiou
void SpaceWars::checkenemyx(int i)
{
	if (x[i])
	{
		if (!x[i]->isActive()) {
			numx++;
			delete x[i];
			x[i] = nullptr;
		}
	}
}

//dhmioyrgv ta sta8era pree boss prin to teliko stadio
void SpaceWars::spawnPreBoss(int i)
{
	if (!preboss[i] && numofpreboss < 3)
	{
		preboss[i] = new Enemy(20,offset, 90,100,0);
		numofpreboss++;
		offset += 250;
	}
}

// dhmioyrgv to trigwno apo mini meteorites otan spaei o megalos
void SpaceWars::spawnMeteorCircle(int i)
{	

	if (!meteorCircle[i])
	{
		meteorCircle[i] = new Meteorite(35.0f, 1.0f, 0.30f, meteorBig->getMeteorCirclePosX()+offsetX, meteorBig->getMeteorCirclePosy()+offsetY);
	}
}

// diagrafei to trigvno apo mini meteorites
void SpaceWars::checkMeteorCircle(int i)
{
	if (meteorCircle[i] && !meteorCircle[i]->isActive()) {
		delete meteorCircle[i];
		meteorCircle[i] = nullptr;
	}
}

// dhmioygei ton megalo meteoriti 
void SpaceWars::spawnMeteorBig()
{
	if (!meteorBig) {
		meteorBig = new Meteorite(100.0f,4.0f,0.15f, CANVAS_WIDTH * rand0to1(),0.0f);
	}
}



//diagrafei ton megalo meteoriti otan bgei ektos plaisioy
void SpaceWars::checkMeteorBig()
{
	if (meteorBig && !meteorBig->isActive()) {
		delete meteorBig;
		meteorBig = nullptr;
	}
}


// dhmioyrgei ta enemy boss
void SpaceWars::spawnenemy(int i)
{
	// an exoyn dhmioyrgh8ei hdh 5
	if (!enemy[i] && numenemies < 5)
	{
		enemy[i] = new Enemy(3,posofboss+t, -50.0f,70,0.3f);
		numenemies++;
	}

}

//diagrafei to enmy ektos o8onis
void SpaceWars::checkenemy(int i)
{
	if (enemy[i])
	{
		if (!enemy[i]->isActive())
		{
			delete enemy[i];
			enemy[i] = nullptr;
			numenemies++;
		}
	}
}

void SpaceWars::updateStartScreen()	//allazei to status apo starting se playing screen
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		status = STATUS_CHOOSE;
	}
}

void SpaceWars::drawStartScreen() //draw start screen
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "space_start.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);




	graphics::drawText(30, 300, 20, "Press ENTER to start!", br);



	graphics::drawText(20, 150, 40, "SPACEWARS", br);




}
void SpaceWars::updateLevelScreen()// update level se kedriki o8onim game
{
	//dimioyrgei paixti
	if (!player_initialized && graphics::getGlobalTime() > 1000)
	{
		player = new Player();
		player_initialized = true;
	}
	if (player->getLife() > 0 && numboss!=2)
	{
		if (player) 
		{
			player->update();
			graphics::MouseState mouse;
			graphics::getMouseState(mouse);
			checkbullet(); 
			if (mouse.button_left_pressed) // me aristero klik petaw sfaira
			{
				spawnbullet();
			}
			for (int i = 0; i < 4; i++) //kinhsh sfairas
			{
				if (bullet[i])
					bullet[i]->update();
			}
		}
		//spawn zwhs
		if (numofpreboss == 6)
		{
			numaddhp = 0;
			s = 100;
			spawnaddhp();
			numofpreboss++;
		}
		//KINISI TOU HP
		if (addhp)
		{
			addhp->update();
		}
		//spawn boss
		if (numofpreboss == 7 && !addhp)
		{
			spawnboss();
		}
		if (boss)
		{
			if (boss->get_enemylife() <= 0.9f)
			{
				boss->updateBoss();  // an h zwh toy einai mikroteri apo 0.99 jekinaei h kinhsh
			}
			if ((boss->get_enemylife() <= 0.9f&& boss->get_enemylife() >= 0.88f)
				|| (boss->get_enemylife() <= 0.7f && boss->get_enemylife() >= 0.68f)
				|| (boss->get_enemylife() <= 0.3f && boss->get_enemylife() >= 0.28f))
			{
				if (numenemies == 10)
				{
					numenemies = 0;
				}
				for (int i = 0; i < 5; i++)
				{
					if (i == 0)
					{
						t = 0.0f;
					}
					if (i == 1)
					{
						t = 200.0f;
					}
					if (i == 2)
					{
						t = 500.0f;
					}
					if (i == 3)
					{
						t = 800.0f;
					}
					if (i == 4)
					{
						t = 1000.0f;
					}
					checkenemy(i);
					spawnenemy(i);
				}
			}
			if (boss->get_enemylife() <= 0.5f && boss->get_enemylife() >= 0.48f)
			{
				numofpreboss = 0;
				offset = 250;
				for (int i = 0; i < 3; i++)
				{
					spawnPreBoss(i);
				}
			}
		}
		//to t einai offset enemy(mple)
		if ((score >= 1000&&score<=2500)||(score>=3500&&score<5000)||(score>=1500&&score<=1600))
		{
			for (int i = 0; i < 5; i++)
			{
				if (i == 0)
				{
					t = 0.0f;
				}
				if (i == 1)
				{
					t = 200.0f;
				}
				if (i == 2)
				{
					t = 500.0f;
				}
				if (i == 3)
				{
					t = 800.0f;
				}
				if (i == 4)
				{
					t = 1000.0f;
				}
				checkenemy(i);
				spawnenemy(i);
			}
		}
		//gia its kiniseis ton ble diagwnia,eutheia kai aditehta diagwnia
		for (int i = 0; i < 5; i++)
		{
			if (enemy[i])
			{
				if(i==0||i==1)
				{
					enemy[i]->update();
				}
				if (i == 4 || i == 3)
				{
					enemy[i]->update1();
				}
				if (i == 2)
				{
					enemy[i]->update2();
				}
			}
		}
		if (numenemies == 10)
		{
			numenemies = 0;
			posofboss = 0.0f;
		}	
		if (boss)
		{
			if (boss->get_enemylife() <= 0.75f)
			{
				// dhimioyrgei tis 2 extra bullet gia to boss
				for (int i = 0; i < 2; i++)
				{
					if (i == 0)
					{
						x1 = 40.0f;
					}
					if (i == 1)
					{
						x1 = -40.0f;
					}
					checkBossBulletAdv(i);
					spawnBossBulletAdv(i);
					if (bossBulletAdv[i])
					{
						// blepei gai collision an iparxei delete
						if (checkcollision_bossShotAdvToplayer(i))
						{
							delete bossBulletAdv[i];
							bossBulletAdv[i] = nullptr;
						}
					}
				}
			}
			checkBossbullet();
			spawnBossbullet();
			if (bossBullet)
			{
				bossBullet->update();
			}
			for (int i = 0; i < 2; i++)
			{
				if (bossBulletAdv[i])
				{
					bossBulletAdv[i]->update();
				}
			}
			// elenxei collision boss sfaira me player 
			if (checkcollision_bossShotToPlayer())
			{
				delete bossBullet;
				bossBullet = nullptr;
			}
		}
		if (player) {
			if (player->getLife() <= 0.5f)
			{
				// an h zwh toy paixth katv apo miso tote dhmioyrgeite diamond gia na parei full hp
				for (int i = 0; i < 8; i++)
				{
					if (i == 0)
					{
						offsetXc = 0;
						offsetYc = 0;
					}
					else if (i == 1)
					{
						offsetXc = -40;
						offsetYc = 40;
					}
					else if (i == 2)
					{
						offsetXc = -80;
						offsetYc = 80;
					}
					else if (i == 3)
					{
						offsetXc = 40;
						offsetYc = 40;
					}
					else if (i == 4)
					{
						offsetXc = 80;
						offsetYc = 80;
					}
					else if (i == 5)
					{
						offsetXc = -40;
						offsetYc = 120;
					}
					else if (i == 6)
					{
						offsetXc = 40;
						offsetYc = 120;
					}
					else if (i == 7)
					{
						offsetXc = 0;
						offsetYc = 160;
					}

					spawnCircle(i);
				}
				spawnaddhp();
			}
		}

		if (checkcollision_playeraddhp())
		{
			delete addhp;
			addhp = nullptr;
			numaddhp++;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++) {
				if (checkcollision_prebossshot(i, j))
				{
					if (preboss[i]->get_enemylife() == 0)
					{
						soundExplosion();
						delete preboss[i];
						preboss[i] = nullptr; // otan diagrafw ton pointer me delete prepei na balv kai to null 
						numofpreboss++;
						score += 300;
					}
					delete bullet[j];
					bullet[j] = nullptr;
				}
			}


		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
			{
				if (checkcollision_xshot(i, j))
				{
					if (x[i]->get_enemylife() == 0)
					{
						soundExplosion();
						delete x[i];
						x[i] = nullptr;
						score += 100;
						numx++;
					}
					delete bullet[j];
					bullet[j] = nullptr;
				}
			}
			if (checkcollision_xplayer(i))
			{
				player->drainLife(0.05f);
				delete x[i];
				x[i] = nullptr;
				numx++;
			}
		}
		
		for (int i = 0; i < 4; i++)
		{
			if (checkcollision_meteorBigshot(i))
			{
				if (meteorBig->getLife() == 0)
				{
					for (int i = 0; i < 5; i++)
					{
						if (i == 0)
						{
							offsetX = 0;
							offsetY = 0;
						}
						else if (i == 1)
						{
							offsetX = -40;
							offsetY = 40;
						}
						else if (i == 2)
						{
							offsetX = -80;
							offsetY = 80;
						}
						else if (i == 3)
						{
							offsetX = 40;
							offsetY = 40;
						}
						else if (i == 4)
						{
							offsetX = 80;
							offsetY = 80;
						}
						checkMeteorCircle(i);
						spawnMeteorCircle(i);
					}
					soundHitMeteor();
					delete meteorBig;
					meteorBig = nullptr;
					score += 20;
				}
				delete bullet[i];
				bullet[i] = nullptr;
			}
		}
		if (checkcollision_meteoriteplayer())
		{
			delete meteorite;
			meteorite = nullptr;
		}

		if (checkcollision_meteorBigplayer())
		{
			for (int i = 0; i < 5; i++)
			{
				if (i == 0)
				{
					offsetX = 0;
					offsetY = 0;
				}
				else if (i == 1)
				{
					offsetX = -40;
					offsetY = 40;
				}
				else if (i == 2)
				{
					offsetX = -80;
					offsetY = 80;
				}
				else if (i == 3)
				{
					offsetX = 40;
					offsetY = 40;
				}
				else if (i == 4)
				{
					offsetX = 80;
					offsetY = 80;
				}
				checkMeteorCircle(i);
				spawnMeteorCircle(i);

			}
			delete meteorBig;
			meteorBig = nullptr;
		}


		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 4; j++) {
				// elenxw to status  collison 
				if (checkcollision_enemyshot(i, j))
				{
					// dhmioyrgw ena game object px fwtia an  sigroustoyn 
					if (enemy[i]->get_enemylife() == 0) {
						soundExplosion();
						delete enemy[i];
						enemy[i] = nullptr; // otan diagrafw ton pointer me delete prepei na balv kai to null 
						numenemies++;
						score += 150;
					}
					delete bullet[j];
					bullet[j] = nullptr;
				}
				if (checkcollision_meteorCircleshot(i, j))
				{
					delete meteorCircle[i];
					meteorCircle[i] = nullptr;
					score += 20;
					delete bullet[j];
					bullet[j] = nullptr;
				}
			}
			if (checkcollision_meteorCircleplayer(i))
			{
				delete meteorCircle[i];
				meteorCircle[i] = nullptr;
			}

		}
		for (int i = 0; i < 4; i++)
		{
			if (checkcollision_meteoriteshot(i))
			{
				delete meteorite;
				meteorite = nullptr;
				delete bullet[i];
				bullet[i] = nullptr;
				score += 15;
			}
			if (checkcollision_bossShot(i))
			{
				if (boss->get_enemylife() == 0.0f)
				{
					soundBossDeath();
					delete boss;
					boss = nullptr;
					numboss++;
					boss_init = false;
				}
				score += 15;
				delete bullet[i];
				bullet[i] = nullptr;
			}
		}



		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 4; j++) {

				if (checkcollision_Circleshot(i, j))
				{
					delete Circle[i];
					Circle[i] = nullptr;
					score += 15;
					delete bullet[j];
					bullet[j] = nullptr;
				}

			}

		}
		for (int i = 0; i < 8; i++) {
			if (checkcollision_Circleplayer(i))
			{
				delete Circle[i];
				Circle[i] = nullptr;
			}
		}
		for (int i = 0; i < 5; i++)
		{
			if (enemy[i])
			{
				checkEnemybullet(i);
				spawnEnemybullet(i, i);
				if (enemyBullet[i])
				{
					enemyBullet[i]->update();
				}
				if (checkcollision_enemybulletplayer(i))
				{
					delete enemyBullet[i];
					enemyBullet[i] = nullptr;
				}
			}
		}
		 // me to f3 paw pause
		if (graphics::getKeyState(graphics::SCANCODE_F3)) {
			status = STATUS_PAUSE;
		}
		if (score >= 0)
		{
			checkmeteorite();
			spawnmeteorite();
		}
		if (meteorite)
		{
			meteorite->update();
		}
		if (score >= 50)
		{
			checkMeteorBig();
			spawnMeteorBig();
		}

		if (meteorBig)
		{
			meteorBig->update();
		}
		for (int i = 0; i < 5; i++)
		{
			if (meteorCircle[i])
			{
				meteorCircle[i]->update();
			}
		}

		if ((score >= 500 && score<=1000)||(score >= 1500 && score <= 2500)||(score >= 3000 &&score<5000)||boss)
		{
			for (int i = 0; i < 4; i++) 
			{
				if (i == 0) {
					posx_ = CANVAS_WIDTH;
					posy_ = 0;
				}
				if (i == 1) {
					posx_ = -50+ CANVAS_WIDTH;
					posy_ = 50;
				}
				if (i == 2)
				{
					posx_ = 0;
					posy_ = 0;
				}
				if (i == 3)
				{
					posx_ = 50;
					posy_ = 50;
				}
				checkenemyx(i);
				spawnenemyx(i);
			}
		}
		if (numx == 8)
		{
			numx = 0;
		}


		// oi diagvnioi enemy kanoyn kinhsh
		for (int i = 0; i < 4; i++) {
			if (x[i]) {
				if (i==0 || i == 1)
				{
					x[i]->updatex();
				}
				else if (i == 2 || i == 3)
				{
					x[i]->updatex1();
				}
				
			}
		}
		if (score > 5000 && score <= 5500)
		{
			for (int i = 0; i < 3; i++) {
				spawnPreBoss(i);
			}
		}
	}
	else if(player->getLife()>0 && numboss==2)
	{
		// screnn nikis
		if (sound1 == true)
		{
			soundwin();
			sound1 = false;
		}
		if (graphics::getKeyState(graphics::SCANCODE_RETURN)) 
		{
			score1 = score;
			status = STATUS_END; 
		}
	}
	else if (player->getLife() <= 0)
	{
	    // otan xanv me enter paw end screen
		if (sound1 == true)
		{
			soundDeath(); 
			sound1 = false;
		}
		
		if (graphics::getKeyState(graphics::SCANCODE_RETURN))
		{
			score1 = score;
			status = STATUS_END;
		}
	}

	

}

void SpaceWars::drawLevelScreen() // draw olo to paixnidi + paixtes + enemy etc.
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "Game Background.png";
	br.outline_opacity = 0.0f;

	//draw backround game
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	if (player)
	{
		player->drawlife(player);
		graphics::Brush bru;
		if (spacecraft == 1)
		{
			player->draw1();

		}
		else if (spacecraft == 2)
		{
			player->draw2();
		}
		else if (spacecraft == 3)
		{
			player->draw3();
		}

		for (int i = 0; i < 4; i++) {
			if (bullet[i])
				bullet[i]->draw();
		}

		// friz o8onis kai game over
		if (player->getLife() == 0)
		{
			graphics::Brush br;
			graphics::drawText(250, 250, 100, "Game Over", br);
			graphics::drawText(350, 400, 30, "Press ENTER to continue", br);
		}

	}
	for (int i = 0; i < 4; i++) {
		if (x[i]) {
			x[i]->drawx();
		}
	}
	for (int i = 0; i < 3; i++) 
	{
		if (preboss[i]) {
			preboss[i]->drawPreBoss();
		}
	}

	for (int i = 0; i < 8; i++)
	{
		if (Circle[i])
		{
			Circle[i]->draw();

		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (x[i]) {
			x[i]->drawx();
		}
	}

	if (addhp)
	{
		addhp->draw();
	}
	for (int i = 0; i < 5; i++)
	{
		if (enemy[i])
		{
			enemy[i]->draw();
			if (enemyBullet[i])
			{
				enemyBullet[i]->draw();
			}
		}

	}
	if (bossBullet)
	{
		bossBullet->drawBossShot();
	}
	for (int i = 0; i < 2; i++)
	{
		if (bossBulletAdv[i])
		{
			bossBulletAdv[i]->drawBossShot();
		}
	}

	if (meteorite)
		meteorite->draw();

	if (meteorBig)
	{
		meteorBig->draw();
	}
	for (int i = 0; i < 5; i++)
	{
		if (meteorCircle[i])
		{
			meteorCircle[i]->draw();

		}
	}
	//gia mpara zwhs boss
	if(boss)
	{
		boss->drawBoss();
		boss->drawbosslife(boss);
	}
	if (numboss == 2)
	{
		graphics::drawText(250.0f, 250.0f, 100.0f, "You Win", br);
		graphics::drawText(350.0f, 400.0f, 30.0f, "Press ENTER to continue", br);
	}

	//score
	graphics::Brush bru;
	char info[40];
	sprintf_s(info, "score: %d", score);
	graphics::drawText(30.0f, 30.0f, 25.0f, info, bru);

}

void SpaceWars::updatePauseScreen()// pause to game 
{	 
	//return to game f1
	if (graphics::getKeyState(graphics::SCANCODE_F1))
	{
		status = STATUS_PLAYING;
	}
	// replay the game
	else if (graphics::getKeyState(graphics::SCANCODE_F2)) 
	{
		GameDelete();
		status = STATUS_START;
	}
}

void SpaceWars::updateEndScreen()
{
	// otan xanv me enter janajekinaw
	GameDelete();
	if (graphics::getKeyState(graphics::SCANCODE_SPACE))
	{
		status = STATUS_CHOOSE;
	}

}

void SpaceWars::spawnBossbullet()
{
	if (!bossBullet)
	{
		bossBullet = new EnemyBullet(boss->getPosX(), boss->getPosY());
	}
}

void SpaceWars::drawPauseScreen()
{
	// o sxediasmos ths pause screen
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "space.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	char info[40];
	sprintf_s(info, "score: %d", score);
	graphics::drawText(30, 30, 25, info, br);
	graphics::drawText(720, 35, 25, "Health : ", br);

	// gia mpara zwhs 
	if(player)
	{
		player->drawlife(player);
	}
	graphics::Brush bru;
	bru.outline_opacity = 0.0f;
	if (spacecraft == 1)
	{
		bru.texture = std::string(ASSET_PATH) + "player_1.png";
		graphics::drawRect(200, 300, 250, 250, bru);
		graphics::drawText(150, 100, 20, "TITANIA : ", bru);
	}
	else if (spacecraft == 2)
	{
		bru.texture = std::string(ASSET_PATH) + "player_2.png";
		graphics::drawRect(200, 300, 250, 250, bru);
		graphics::drawText(150, 100, 20, "LUPUS : ", bru);
	}
	else if (spacecraft == 3)
	{
		bru.texture = std::string(ASSET_PATH) + "player_3.png";
		graphics::drawRect(200, 300, 250, 250, bru);
		graphics::drawText(150, 100, 20, "VALOR : ", bru);
	}

	graphics::drawText(500, 150, 20, "To resume the game press F1", bru);
	graphics::drawText(500, 250, 20, "To return to the main menu press F2", bru);
	graphics::drawText(500, 350, 20, "To exit the game press Esc", bru);
}

void SpaceWars::checkBossbullet()
{
	if (bossBullet)
	{
		if (!bossBullet->isActive())
		{
			delete bossBullet;
			bossBullet = nullptr;
		}
	}
}

void SpaceWars::spawnBossBulletAdv(int i)
{
	if (!bossBulletAdv[i])
	{
		bossBulletAdv[i] = new EnemyBullet(boss->getPosX()-x1,boss->getPosY());
	}
}

void SpaceWars::checkBossBulletAdv(int i)
{
	if (bossBulletAdv[i])
	{
		if (!bossBulletAdv[i]->isActive())
		{
			delete bossBulletAdv[i];
			bossBulletAdv[i] = nullptr;
		}
	}
}


void SpaceWars::drawEndScreen()
{ // ti 8a emfanizei h endscreen
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "space.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);


	br.texture = std::string(ASSET_PATH) + "preboss.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(875, 120, 200, 220, br);

	graphics::Brush bru;
	bru.outline_opacity = 0.0f;

	graphics::drawText(100, 40, 35, "THE CREATORS :", bru);
	graphics::drawText(100, 100, 25, "> Georgia Psycha (3190225)", bru);
	graphics::drawText(100, 150, 25, "> Alexios Filippakopoulos (3190212)", bru);
	graphics::drawText(100, 200, 25, "> Dimitrios Kavvadas (3190064)", bru);

	graphics::drawText(300, 400, 20, "To restart the game press SPACE", bru);
	graphics::drawText(300, 450, 20, "To EXIT the game press ESC", bru);

	graphics::Brush bru1;
	char info[40];
	sprintf_s(info, "score: %d", score1);
	graphics::drawText(300, 350, 50, info, bru1);


	br.outline_opacity = 1.0f;
	br.gradient = false;
	br.fill_opacity = 0.0f;
	graphics::drawRect(500, 420, 450, 80, br); // to perigramma
	
}

void SpaceWars::updateChooseScreen()
{ // to screen gia na epilexw  diasthmoploio
	if (graphics::getKeyState(graphics::SCANCODE_1))
	{
		status = STATUS_PLAYING;
		spacecraft = 1;
	}

	if (graphics::getKeyState(graphics::SCANCODE_2))
	{
		status = STATUS_PLAYING;
		spacecraft = 2;
	}

	if (graphics::getKeyState(graphics::SCANCODE_3))
	{
		status = STATUS_PLAYING;
		spacecraft = 3;
	}
}

void SpaceWars::drawChooseScreen()
{ 
	// o sxediasmos poy epilegw spacecraft player
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "space.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);



	br.texture = std::string(ASSET_PATH) + "player_1.png";
	graphics::drawRect(CANVAS_WIDTH / 4 - 50, CANVAS_HEIGHT - 125 + 50, 100, 100, br);


	br.texture = std::string(ASSET_PATH) + "player_2.png";
	graphics::drawRect(CANVAS_WIDTH / 2 - 20, CANVAS_HEIGHT - 125 + 50, 100, 100, br);


	br.texture = std::string(ASSET_PATH) + "player_3.png";
	graphics::drawRect(CANVAS_WIDTH - 250, CANVAS_HEIGHT - 125 + 50, 100, 100, br);
	// onomata paixtvn
	graphics::drawText(CANVAS_WIDTH - 750, 270, 20, "Press 1 ,2 or 3 to choose your SPACECRAFT!", br);

	graphics::drawText((CANVAS_WIDTH / 2) - 70, CANVAS_HEIGHT - 200 + 50, 20, "2:LUPUS", br);

	graphics::drawText((CANVAS_WIDTH / 4) - 60 - 50, CANVAS_HEIGHT - 200 + 50, 20, "1:TITANIA", br);

	graphics::drawText(CANVAS_WIDTH - 300, CANVAS_HEIGHT - 200 + 50, 20, "3:VALOR", br);
	// games rules
	br.outline_opacity = 1.0f;
	graphics::drawText(30, 30, 20, "Instructions: ", br);
	graphics::drawText(30, 60, 15, "Move Upwards : W", br);
	graphics::drawText(30, 90, 15, "Move Downwards : S ", br);
	graphics::drawText(30, 120, 15, "Move Rightwards : D", br);
	graphics::drawText(30, 150, 15, "Move Leftwards : A", br);
	graphics::drawText(30, 180, 15, "Fire Bullet : Left Click", br);
	graphics::drawText(30, 210, 15, "Pause : F3", br);
	graphics::drawText(750, 30, 20, "About the game :", br);
	graphics::drawText(750, 60, 15, "It's a survival game so", br);
	graphics::drawText(750, 90, 15, "shoot the meteors and the", br);
	graphics::drawText(750, 120, 15, "enemies while dodging w/e", br);
	graphics::drawText(750, 150, 15, "life throws at you so you", br);
	graphics::drawText(750, 180, 15, "can increase your score and", br);
	graphics::drawText(750, 210, 15, "advance to the next rounds.", br);
	graphics::drawText(300, 150, 30, "See you space-cowboy", br);

	br.outline_opacity = 1.0f;
	br.gradient = false;
	br.fill_opacity = 0.0f;
	graphics::drawRect(125, 120, 200, 220, br); // to perigramma  
	graphics::drawRect(750 + 120, 120, 250, 220, br); // to perigramma  





}

void SpaceWars::spawnmeteorite()
{
	if (!meteorite) {
		meteorite = new Meteorite(35.0f,1.0f,0.50f, CANVAS_WIDTH * rand0to1(), 0.0f);
	}
}

void SpaceWars::checkmeteorite()
{
	if (meteorite && !meteorite->isActive()) {
		delete meteorite;
		meteorite = nullptr;
	}
}
bool SpaceWars::checkcollision_xplayer(int i)// elenxei collision paixti me x enemy
{
	
	if (!player || !x[i])
	{  // an den iparxei kanena antikeimeno 
		return false;
	}

	Disk d1 = player->getCollisionHull();
	Disk d2 = x[i]->getCollisionHull();

	// elenxw an iparxei collision symfvna me 8ewria apo ekfvnisi 
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious)
	{
		soundSpacecraftHit();
		player->drainLife(0.1f); // an exei collision meivnv zvh paixti 
		return true;
	}
	else
	{
		return false;
	}
}

bool SpaceWars::checkcollision_xshot(int i, int j)
{
	if (!x[i]  || !bullet[j]) {
		// an den iparxei kanena antikeimeno 
		return false;
	}

	Disk d1 = bullet[j]->getCollisionHull();
	Disk d2 = x[i]->getCollisionHull();


	//elenxw an iparxei collision symfvna me 8ewria apo ekfvnisi 
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious)
	{
		soundHitEnemy();
		x[i]->drainEnemyLife(1.0f);
		return true;
	}
	else
	{
		return false;
	}
}


bool SpaceWars::checkcollision_prebossshot(int i, int j)
{
	if (!preboss[i] || !bullet[j]) {
		// an den iparxei kanena antikeimeno 
		return false;
	}

	Disk d1 = bullet[j]->getCollisionHull();
	Disk d2 = preboss[i]->getCollisionHull();

	//elenxw an iparxei collision symfvna me 8ewria apo ekfvnisi 
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;
	;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious) {
		soundHitEnemy();
		preboss[i]->drainEnemyLife(1);
		return true;
	}
	else {
		return false;
	}
}

bool SpaceWars::checkcollision_enemyshot(int i, int j)
{
	if (!enemy[i] || !bullet[j]) {
		// an den iparxei kanena antikeimeno 
		return false;
	}

	Disk d1 = bullet[j]->getCollisionHull();
	Disk d2 = enemy[i]->getCollisionHull();

	//elenxw an iparxei collision symfvna me 8ewria apo ekfvnisi 
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;
;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious) {
		soundHitEnemy();
		enemy[i]->drainEnemyLife(1);
		return true;
	}else {
		return false;
	}
}

bool SpaceWars::checkcollision_meteoriteshot(int i)
{
	if (!meteorite || !bullet[i]) {
		// an den iparxei kanena antikeimeno 
		return false;
	}

	Disk d1 = bullet[i]->getCollisionHull();
	Disk d2 = meteorite->getCollisionHull();


	//elenxw an iparxei collision symfvna me 8ewria apo ekfvnisi 
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious)
	{
		soundHitMeteor();
		return true;
	}
	else
	{
		return false;
	}
		
}

bool SpaceWars::checkcollision_meteoriteplayer()
{
	if (!player || !meteorite)
	{  // an den iparxei kanena antikeimeno 
		return false;
	}

	Disk d1 = player->getCollisionHull();
	Disk d2 = meteorite->getCollisionHull();

	// elenxw an iparxei collision symfvna me 8ewria apo ekfvnisi 
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious)
	{
		soundSpacecraftHit();
		player->drainLife(0.1f);
		return true;
	}
	else
	{
		return false;
	}
		
}

bool SpaceWars::checkcollision_enemybulletplayer(int i)
{
	if (!player)
	{
		return false;
	}
	Disk d1 = enemyBullet[i]->getCollisionHull();
	Disk d2 = player->getCollisionHull();
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious)
	{
		soundSpacecraftHit();
		player->drainLife(0.1f);
		return true;
	}
	else
		return false;
}

bool SpaceWars::checkcollision_meteorBigshot(int i)
{
	if (!meteorBig || !bullet[i]) {
		// an den iparxei kanena antikeimeno 
		return false;
	}

	Disk d1 = bullet[i]->getCollisionHull();
	Disk d2 = meteorBig->getCollisionHull();


	//elenxw an iparxei collision symfvna me 8ewria apo ekfvnisi 
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious)
	{
		soundHitEnemy();
		meteorBig->drainLife(1);
		return true;
	}
	else
	{
		return false;
	}
}

bool SpaceWars::checkcollision_meteorBigplayer()
{
	if (!player || !meteorBig)
	{  // an den iparxei kanena antikeimeno 
		return false;
	}

	Disk d1 = player->getCollisionHull();
	Disk d2 = meteorBig->getCollisionHull();

	// elenxw an iparxei collision symfvna me 8ewria apo ekfvnisi 
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious)
	{
		soundSpacecraftHit();
		meteorBig->drainLife(1);
		player->drainLife(0.1f);
		return true;
	}
	else
	{
		return false;
	}
}

bool SpaceWars::checkcollision_meteorCircleshot(int i,int j)
{
	if (!meteorCircle[i] || !bullet[j]) {
		// an den iparxei kanena antikeimeno 
		return false;
	}

	Disk d1 = bullet[j]->getCollisionHull();
	Disk d2 = meteorCircle[i]->getCollisionHull();


	//elenxw an iparxei collision symfvna me 8ewria apo ekfvnisi 
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious)
	{
		soundHitMeteor();
		return true;
	}
	else
	{
		return false;
	}
}

bool SpaceWars::checkcollision_Circleshot(int i, int j)
{
	if (!Circle[i] || !bullet[j]) {
		// an den iparxei kanena antikeimeno 
		return false;
	}

	Disk d1 = bullet[j]->getCollisionHull();
	Disk d2 =Circle[i]->getCollisionHull();
	 

	//elenxw an iparxei collision symfvna me 8ewria apo ekfvnisi 
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious)
	{
		soundHitMeteor();
		return true;
	}
	else
	{
		return false;
	}
}
bool SpaceWars::checkcollision_meteorCircleplayer(int i)
{
	if (!player || !meteorCircle[i])
	{  // an den iparxei kanena antikeimeno 
		return false;
	}

	Disk d1 = player->getCollisionHull();
	Disk d2 = meteorCircle[i]->getCollisionHull();

	// elenxw an iparxei collision symfvna me 8ewria apo ekfvnisi 
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious)
	{
		soundSpacecraftHit();
		player->drainLife(0.1f);
		return true;
	}
	else
	{
		return false;
	}
}

bool SpaceWars::checkcollision_playeraddhp()
{
	if (!player || !addhp)
	{  // an den iparxei kanena antikeimeno 
		return false;
	}

	Disk d1 = player->getCollisionHull();
	Disk d2 = addhp->getCollisionHull();

	// elenxw an iparxei collision symfvna me 8ewria apo ekfvnisi 
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious)
	{
		soundHpadd();
		player->drainLife(-1 + player->getLife());
		return true;
	}
	else
	{
		return false;
	}
}

bool SpaceWars::checkcollision_Circleplayer(int i)
{
	if (!player || !Circle[i])
	{  // an den iparxei kanena antikeimeno 
		return false;
	}

	Disk d1 = player->getCollisionHull();
	Disk d2 = Circle[i]->getCollisionHull();

	// elenxw an iparxei collision symfvna me 8ewria apo ekfvnisi 
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious)
	{
		soundSpacecraftHit();
		player->drainLife(0.1f);
		return true;
	}
	else
	{
		return false;
	}
}


bool SpaceWars::checkcollision_bossShotAdvToplayer(int i)
{
	if (!player || !bossBulletAdv[i])
	{  // an den iparxei kanena antikeimeno 
		return false;
	}

	Disk d1 = player->getCollisionHull();
	Disk d2 = bossBulletAdv[i]->getCollisionHull();

	// elenxw an iparxei collision symfvna me 8ewria apo ekfvnisi 
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious)
	{
		soundSpacecraftHit();
		player->drainLife(0.1f);
		return true;
	}
	else
	{
		return false;
	}
}

// ta sound effect 

void SpaceWars::soundShot()
{
	graphics::playSound(std::string(ASSET_PATH) + "pitsiou.mp3", 0.25f, false);
}

void SpaceWars::soundExplosion()
{
	graphics::playSound(std::string(ASSET_PATH) + "explosion.wav", 0.25f, false);
}


void SpaceWars::soundHitMeteor()
{
	graphics::playSound(std::string(ASSET_PATH) + "slam.mp3", 0.25f, false);
}

void SpaceWars::soundMaintheme()
{
	graphics::playMusic(std::string(ASSET_PATH) + "ragingDemon.mp3", 0.4f, true, 0);
}

void SpaceWars::soundSpacecraftHit()
{
	graphics::playSound(std::string(ASSET_PATH) + "gethit.wav", 0.25f, false);
}

void SpaceWars::soundDeath()
{
	graphics::playSound(std::string(ASSET_PATH) + "death.wav", 0.5f, false);
}

void SpaceWars::soundHpadd()
{
	graphics::playSound(std::string(ASSET_PATH) + "fullhp.wav", 0.25f, false);
}

void SpaceWars::soundwin()
{
	graphics::playSound(std::string(ASSET_PATH) + "win.mp3", 0.5f, false);
}

void SpaceWars::soundBossEnter()
{
	graphics::playSound(std::string(ASSET_PATH) + "bossSound.mp3", 0.25f, false);
}

void SpaceWars::soundBossDeath()
{
	graphics::playSound(std::string(ASSET_PATH) + "bossdeath.mp3", 0.25f, false);
}

void SpaceWars::soundHitEnemy()
{
	graphics::playSound(std::string(ASSET_PATH) + "hitmarker.mp3", 0.25f, false);
}

// an xasw diafrafi tou game olou
void SpaceWars::GameDelete()
{
	if (player)
	{
		delete player;
		player = nullptr;
		player_initialized = false;
		for (int i = 0; i < 4; i++)
		{
			if (bullet[i])
			{
				delete bullet[i];
				bullet[i] = nullptr;
			}
		}
	}

	if (meteorite) {
		delete meteorite;
		meteorite = nullptr;

	}
	if(boss)
	{
		delete boss;
		boss = nullptr;
	}
	for (int i = 0; i < 2; i++)
	{
		if (bossBulletAdv[i])
		{
			delete bossBulletAdv[i];
			bossBulletAdv[i] = nullptr;
		}
	}
	if (bossBullet)
	{
		delete bossBullet;
		bossBullet = nullptr;
	}
	for (int i = 0; i < 5; i++)
	{
		if (enemy[i])
		{
			delete enemy[i];
			enemy[i] = nullptr;


			if (enemyBullet[i])
			{
				delete enemyBullet[i];
				enemyBullet[i] = nullptr;
			}
		}

		if (meteorCircle[i])
		{
			delete meteorCircle[i];
			meteorCircle[i] = nullptr;
		}
	}

	if (meteorBig)
	{
		delete meteorBig;
		meteorBig = nullptr;
	}

	for (int i = 0; i < 8; i++)
	{
		if (Circle[i])
		{
			delete Circle[i];
			Circle[i] = nullptr;
		}
	}

	if (addhp)
	{
		delete addhp;
		addhp = nullptr;
	}
	for (int i = 0; i < 4; i++)
	{
		if (x[i])
		{
			delete x[i];
			x[i] = nullptr;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (preboss[i])
		{
			delete preboss[i];
			preboss[i] = nullptr;
		}
	}
	numboss = 0;
	numenemies = 0;
	posofboss = 0.0f;
	offset = 250;
	numofpreboss = 0;
	numx = 0;
	numaddhp = 0;
	numc = 0;
	score = 0;
}


bool SpaceWars::checkcollision_bossShot(int i)
{
	if (!boss || !bullet[i]) {
		// an den iparxei kanena antikeimeno 
		return false;
	}

	Disk d1 = bullet[i]->getCollisionHull();
	Disk d2 = boss->getCollisionHull();


	//elenxw an iparxei collision symfvna me 8ewria apo ekfvnisi 
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious)
	{
		soundHitEnemy();
		boss->drainEnemyLife(0.01f);
		return true;
	}
	else
	{
		return false;
	}
}


void SpaceWars::draw()
{
	// analoga me to status to analoga screen paw
	if (status == STATUS_START)
	{
		drawStartScreen();
	}
	if (status == STATUS_PLAYING)
	{
		drawLevelScreen();
	}
	if (status == STATUS_CHOOSE)
	{
		drawChooseScreen();
	}
	if (status == STATUS_PAUSE)
	{
		drawPauseScreen();
	}
	if (status == STATUS_END)
	{
		drawEndScreen();
	}

}

void SpaceWars::spawnboss()
{

	if (!boss&&numboss<1) 
	{
		soundBossEnter();
		boss = new Enemy(1.0f,500,60,150,0);
		numboss++;
	}
}

void SpaceWars::spawnCircle(int i)
{
	if (!Circle[i] && numc<8)
	{
		Circle[i] = new Meteorite(35.0f, 1.0f, 0.30f, CANVAS_WIDTH / 2 + offsetXc, CANVAS_HEIGHT / 3 + offsetYc);
		numc++;
	}
}

void SpaceWars::update()
{
	// analoga me to status to analoga screen
	if (status == STATUS_START)
	{
		updateStartScreen();
	}
	if (status == STATUS_PLAYING)
	{
		updateLevelScreen();
	}
	if (status == STATUS_CHOOSE)
	{
		updateChooseScreen();
	}
	if (status == STATUS_PAUSE) {
		updatePauseScreen();
	}
	if (status == STATUS_END)
	{
		updateEndScreen();
	}
}

void SpaceWars::checkCircle(int i)
{
	if (Circle[i] && !Circle[i]->isActive()) {
		delete Circle[i];
		Circle[i] = nullptr;
	}
}

void SpaceWars::spawnEnemybullet(int i, int j)
{
	if (!enemyBullet[i])
	{
		enemyBullet[i] = new EnemyBullet(enemy[j]->getPosX(), enemy[j]->getPosY());
	}
}

void SpaceWars::init()
{

	soundMaintheme();

	graphics::setFont(std::string(ASSET_PATH) + "NAME.TTF");

}

bool SpaceWars::checkcollision_bossShotToPlayer()
{
	if (!player)
	{
		return false;
	}
	Disk d1 = bossBullet->getCollisionHull();
	Disk d2 = player->getCollisionHull();
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;

	if (sqrt(dx * dx + dy * dy) < d1.radious + d2.radious)
	{
		soundSpacecraftHit();
		player->drainLife(0.1f);
		return true;
	}
	else
		return false;
}


void SpaceWars::checkEnemybullet(int i)
{
	if (enemyBullet[i])
	{
		if (!enemyBullet[i]->isActive())
		{
			delete enemyBullet[i];
			enemyBullet[i] = nullptr;
		}
	}
}

void SpaceWars::spawnaddhp()
{
	// gia to hp na ginei full ston paixti
	if (!addhp&&numaddhp<1)
	{
		addhp = new AddHp(30.0f+s, CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2);
		numaddhp++;
	}
}
SpaceWars::SpaceWars()
{
}

SpaceWars::~SpaceWars()
{
}
