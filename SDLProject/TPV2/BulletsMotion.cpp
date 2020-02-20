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
			Vector2D bulletPos = fighterTr_->getPos() + Vector2D(fighterTr_->getW() / 2,
				fighterTr_->getH() / 2) + Vector2D(0, -(fighterTr_->getH() / 2 + 5.0)).rotate(fighterTr_->getRot());
			Vector2D bulletVel = Vector2D(0, -1).rotate(fighterTr_->getRot()) * 2;
			pool_->getPool()[i]->setPos(bulletPos);
			pool_->getPool()[i]->setVel(bulletVel);
			if (pool_->getPool()[i]->getPos()->getX() > game_->getWindowWidth() ||
				pool_->getPool()[i]->getPos()->getX() <= 0 &&
				pool_->getPool()[i]->getPos()->getY() > game_->getWindowHeight() ||
				pool_->getPool()[i]->getPos()->getY() <= 0) {
				pool_->getPool()[i]->setObject(false);
				cout << "Bala salio de la pantalla \n";
			}
		}
	}
}