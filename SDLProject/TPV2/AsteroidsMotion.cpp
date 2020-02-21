#include "AsteroidsMotion.h"
#include "SDL_macros.h"
#include "Entity.h"


void AsteroidsMotion::init() {
	pool_ = GETCMP1_(AsteroidsPool);
}

//Comprueba si un bullet está siendo usado, si es así, modifica la velocidad y posición
void AsteroidsMotion::update() {

	for (int i = 0; i < pool_->getPool().size(); i++) {
		if (pool_->getPool()[i]->isUsed()) {
			Asteroid* currAsteroid = pool_->getPool()[i];
			if (currAsteroid->getPos()->getX() > game_->getWindowWidth() ||
				currAsteroid->getPos()->getX() < 0.0 &&
				currAsteroid->getPos()->getY() > game_->getWindowHeight() ||
				currAsteroid->getPos()->getY() < 0.0) {
				cout << " El Asteroide " << i << " salio de la pantalla \n";
				currAsteroid->setObject(false);
				currAsteroid->setVel(0);
			}
			else
			{
				Vector2D currSpeed = { currAsteroid->getPos()->getX() + currAsteroid->getDir()->getX() * currAsteroid->getVel() ,
				currAsteroid->getPos()->getY() + currAsteroid->getDir()->getY() * currAsteroid->getVel() };
				cout << currSpeed << endl;
				currAsteroid->setPos(currSpeed);
			}
			currAsteroid = nullptr;
		}
	}
}