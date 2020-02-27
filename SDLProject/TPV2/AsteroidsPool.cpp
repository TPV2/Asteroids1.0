#include "AsteroidsPool.h"
#include "SRandBasedGenerator.h"
#include "BulletsPool.h"


AsteroidsPool::AsteroidsPool() :
	Component(ecs::AsteroidsPool),
	astPool([](Asteroid* a) {return a->isUsed(); }) {};

//A todos los objectos del pool los desactiva
void AsteroidsPool::disablAll() {
	if (astPool.isEmphy()) {
		for (int i = 0; i < astPool.getPool().size(); i++) {
			astPool.getPool()[i]->setObject(false);
		}
	}
	asteroidsActive = 0;
}

//destruye un asteroide y lo divide entre dos si el nivel del asteroide es >= 1
void AsteroidsPool::onCollision( Asteroid* a) {
	a->setLevel(a->getLevel() - 1);
	if (a->getLevel() >= 1) {
		SRandBasedGenerator* rnd = new SRandBasedGenerator();
		//Primer asteroide
		Asteroid* ast1 = astPool.getObj();
		Vector2D dir1 = { (double)rnd->nextInt(-100, 101) / 100.0, (double)rnd->nextInt(-100, 101) / 100.0 };
		double vel1 = rnd->nextInt(ASTEROID_MIN_VEL * 100, ASTEROID_MAX_VEL * 100) / 100.0;
		double angle1 = rnd->nextInt(0, 360);
		ast1->startAsteroid( *a->getPos(), dir1, vel1, angle1, a->getLevel());
		//Segundo asteroide
		Asteroid* ast2 = astPool.getObj();
		Vector2D dir2 = { (double)rnd->nextInt(-100, 101) / 100.0, (double)rnd->nextInt(-100, 101) / 100.0 };
		double vel2 = rnd->nextInt(ASTEROID_MIN_VEL * 100, ASTEROID_MAX_VEL * 100) / 100.0;
		double angle2 = rnd->nextInt(0, 360);
		ast2->startAsteroid(*a->getPos(), dir2, vel2, angle2, a->getLevel());
		asteroidsActive += 2;
	}
	a->setObject(false);
	asteroidsActive--;
}

//Genera asteroides en función de un entero al inicio del juego
void AsteroidsPool::generateAsteroids(int n) {
	SRandBasedGenerator* rnd = new SRandBasedGenerator();
	for (int i = 0; i < n; i++) {
		Asteroid* currAsteroid = astPool.getPool()[i];
		Vector2D pos = { (double)rnd->nextInt(0, game_->getWindowWidth()), (double)rnd->nextInt(0, game_->getWindowHeight()) };
		//Genera una posición que este fuera del rango del figher
		while (!validPosition(pos)) pos = { (double)rnd->nextInt(0, game_->getWindowWidth()), (double)rnd->nextInt(0, game_->getWindowHeight()) };
		Vector2D dir = { (double)rnd->nextInt(-100, 101) / 100.0, (double)rnd->nextInt(-100, 101) / 100.0 };
		double vel = rnd->nextInt(ASTEROID_MIN_VEL * 100, ASTEROID_MAX_VEL * 100) / 100.0;
		double level = rnd->nextInt(1, 4);
		double angle = rnd->nextInt(0, 360);
		//currAsteroid->startAsteroid(pos, dir, vel, angle, level);
		currAsteroid->startAsteroid({ 780, 580 }, dir, vel, angle, level); //EFECTO CURIOSO
		asteroidsActive++;
	}
}

//Devuelve true si la posición de un asteroide esta fuera del rango de creación del fighter
bool AsteroidsPool::validPosition(const Vector2D& astPos) {
	if (astPos.getX() > (game_->getWindowWidth()/2) + SAFE_ZONE_W && astPos.getX() < (game_->getWindowWidth()/2) - SAFE_ZONE_W &&
		astPos.getY() > (game_->getWindowHeight()/2) + SAFE_ZONE_H && astPos.getY() < (game_->getWindowHeight()/2) - SAFE_ZONE_H){
		return false;
	}
	else return true;
}