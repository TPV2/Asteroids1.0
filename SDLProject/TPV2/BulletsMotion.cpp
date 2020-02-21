#include "BulletsMotion.h"
#include "SDL_macros.h"
#include "Entity.h"


void BulletsMotion::init() {
	pool_ = GETCMP1_(BulletsPool);
}

//Comprueba si un bullet está siendo usado, si es así, modifica la velocidad y posición
void BulletsMotion::update() {

	for (int i = 0; i < pool_->getPool().size(); i++) {
		if (pool_->getPool()[i]->isUsed()) {
			Bullet* currBullet = pool_->getPool()[i];
			if (currBullet->getPos()->getX() > game_->getWindowWidth() ||
				currBullet->getPos()->getX() < 0.0 &&
				currBullet->getPos()->getY() > game_->getWindowHeight() ||
				currBullet->getPos()->getY() < 0.0) {
				cout << " La bala " << i << " salio de la pantalla \n";
				currBullet->setObject(false);
				currBullet->setVel(0);
			}
			else
			{
				Vector2D currSpeed = { currBullet->getPos()->getX() + currBullet->getDir()->getX() * currBullet->getVel() ,
				currBullet->getPos()->getY() + currBullet->getDir()->getY() * currBullet->getVel() };
				cout << currSpeed << endl;
				currBullet->setPos(currSpeed);
			}
			currBullet = nullptr;
		}
	}
}