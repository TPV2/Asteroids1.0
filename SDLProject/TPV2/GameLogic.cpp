#include "GameLogic.h"
#include "Collisions.h"
#include "Resources.h"
#include "Entity.h"
#include "Collisions.h"

GameLogic::GameLogic(Transform* fighterTR, BulletsPool* bulletPool,
	AsteroidsPool* astPool, Health* health) :
	Component(ecs::GameLogic), 
	fighterTR_(fighterTR),
	bullerPool_(bulletPool),
	astPool_(astPool),
	health_(health),
	scoreManager_(nullptr) {};


GameLogic::~GameLogic() {
}

void GameLogic::init() {
	scoreManager_ = GETCMP1_(ScoreManager);
}
//Comprueba las colisiones entre las (balas / asteroides) y (asteroides/player)
void GameLogic::update() {
	if (scoreManager_->isRunning()) {
		for (int i = 0; i < astPool_->getPool().size(); i++) {
			Asteroid* currAst = astPool_->getPool()[i];
			if (currAst->isUsed()) {
				//Comprobaci�n con el avi�n
				if (Collisions::collidesWithRotation(*currAst->getPos(), currAst->getW(), currAst->getH(), currAst->getAngle(),
					fighterTR_->getPos(), fighterTR_->getW(), fighterTR_->getH(), fighterTR_->getRot())) {
					astPool_->disablAll();
					fighterTR_->setPos((game_->getWindowWidth() - fighterTR_->getW()) / 2, (game_->getWindowHeight() - fighterTR_->getH()) / 2);
					fighterTR_->setVel({ 0.0,0.0 });
					fighterTR_->setRot(0);
					scoreManager_->setRunning(false);
					health_->removeLives(1);
				}
				else
				{
					//Comprobaci�n con las balas
					for (int j = 0; j < bullerPool_->getPool().size(); j++) {
						Bullet* currBullet = bullerPool_->getPool()[j];
						if (currBullet->isUsed() && Collisions::collidesWithRotation(*currAst->getPos(), currAst->getW(), currAst->getH(), currAst->getAngle(),
							*currBullet->getPos(), currBullet->getScale()->getX(), currBullet->getScale()->getY(), currBullet->getAngle())) {
							bullerPool_->onCollision(currBullet);
							astPool_->onCollision(currAst);
							scoreManager_->addScore(currAst->getPoints());
						}
					}
				}
			}
		}
	}
}

