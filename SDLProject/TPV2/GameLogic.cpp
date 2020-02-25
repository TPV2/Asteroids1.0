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

void GameLogic::update() {
	if (scoreManager_->isRunning()) {
		for (int i = 0; i < astPool_->getPool().size(); i++) {
			Asteroid* currAst = astPool_->getPool()[i];
			if (currAst->isUsed()) {
				//Comprobación con el avión
				if (Collisions::collidesWithRotation(*currAst->getPos(), currAst->getW(), currAst->getH(), currAst->getAngle(),
					fighterTR_->getPos(), fighterTR_->getW(), fighterTR_->getH(), fighterTR_->getRot())) {

					fighterTR_->setPos(game_->getWindowWidth() / 2, game_->getWindowHeight() / 2);
					scoreManager_->setRunning(false);
					health_->removeLives(1);
				}
				else
				{
					//Comprobación con las balas
					for (int j = 0; j < bullerPool_->getPool().size(); j++) {
						Bullet* currBullet = bullerPool_->getPool()[j];

						if (Collisions::collidesWithRotation(*currAst->getPos(), currAst->getW(), currAst->getH(), currAst->getAngle(),
							*currBullet->getPos(), currBullet->getScale()->getX(), currBullet->getScale()->getY(), currBullet->getAngle())) {
							bullerPool_->onCollision(currBullet);
							astPool_->onCollision(currBullet, currAst);
							scoreManager_->addScore(10);//es prueba
						}
					}
				}
			}
		}
	}
}

