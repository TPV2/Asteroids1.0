#include "AsteroidsMotion.h"
#include "SDL_macros.h"
#include "Entity.h"


void AsteroidsMotion::init() {
	pool_ = GETCMP1_(AsteroidsPool);
}

//Comprueba si un asteroide est� siendo usado, si es as�, modifica la velocidad y posici�n
void AsteroidsMotion::update() {
	for (int i = 0; i < pool_->getPool().size(); i++) {
		if (pool_->getPool()[i]->isUsed()) {
			pool_->getPool()[i]->setAngle(pool_->getPool()[i]->getAngle() + 15);
			pool_->getPool()[i]->setPos(
				{ pool_->getPool()[i]->getPos()->getX() + pool_->getPool()[i]->getDir()->getX() * pool_->getPool()[i]->getVel(),
				pool_->getPool()[i]->getPos()->getY() + pool_->getPool()[i]->getDir()->getY() * pool_->getPool()[i]->getVel() }
			);
		}
		//Si sale de la pantalla
		if (pool_->getPool()[i]->getPos()->getX() < -pool_->getPool()[i]->getW()) pool_->getPool()[i]->setPos({ (double)game_->getWindowWidth(), pool_->getPool()[i]->getPos()->getY() });			//Izquierda
		else if (pool_->getPool()[i]->getPos()->getX() > game_->getWindowWidth()) pool_->getPool()[i]->setPos({ 0, pool_->getPool()[i]->getPos()->getY() });	//Derecha

		if (pool_->getPool()[i]->getPos()->getY() < -pool_->getPool()[i]->getH()) pool_->getPool()[i]->setPos({ pool_->getPool()[i]->getPos()->getX(), (double)game_->getWindowHeight() });		//Arriba
		else if (pool_->getPool()[i]->getPos()->getX() > game_->getWindowHeight()) pool_->getPool()[i]->setPos({ pool_->getPool()[i]->getPos()->getX(), 0 });	//Abajo
	}
}