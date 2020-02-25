#include "AsteroidsPool.h"
#include "SRandBasedGenerator.h"
#include "BulletsPool.h"



AsteroidsPool::AsteroidsPool() :
	Component(ecs::AsteroidsPool),
	astPool(nullptr) {}			//Asteroid::isUsed?


void AsteroidsPool::disablAll() {
	if (astPool.isEmphy()) {
		for (int i = 0; i < astPool.getPool().size(); i++) {
			astPool.getPool()[i]->setObject(false);
		}
	}
}

//TODO:: A falta de la implementaci�n de los asteroides
/*se llama a este m�todo cuando un asteroide
choca con una bala. Lo que tiene que hacer es dividir el asteroide a en 2 (ver el ap�ndice
para m�s detalles).*/
void AsteroidsPool::onCollision(Bullet* b, Asteroid* a) {
	auto vec = getPool();
	if (a->getLevel() > 0) {
		a->setObject(false);
		//Vector2D v = vel.rotate(i * 45);
		//Vector2D p = p.pos + v.normalize()
	}
	else
	{
		delete a;
	}
}

//FUNCION DE PRUEBA
void AsteroidsPool::generateAsteroids(int n) {
	SRandBasedGenerator* rnd = new SRandBasedGenerator();
	astPool.getPool()[1]->isUsed();
	astPool.getPool()[1]->setObject(true);
	astPool.getPool()[1]->setAngle(rnd->nextInt(0, 360));
	astPool.getPool()[1]->setVel(rnd->nextInt(ASTEROID_MIN_VEL, ASTEROID_MAX_VEL));
	astPool.getPool()[1]->setPos({ 400, 0 });
	astPool.getPool()[1]->setLevel(rnd->nextInt(1, 4));
	astPool.getPool()[1]->startAsteroid({ 400, -50 }, { 0,0 }, 0, 0, 3);
}
//FUNCION BUENA
/*
//Busca un bullet no usado en el pool, si lo encuentra lo activa
void AsteroidsPool::generateAsteroids(int n) {
	SRandBasedGenerator* rnd = new SRandBasedGenerator();
	for (int i = 0; i < n; i++) {
		astPool.getPool()[i]->isUsed();
		astPool.getPool()[i]->setObject(true);
		astPool.getPool()[i]->setAngle(rnd->nextInt(0, 360));
		astPool.getPool()[i]->setVel(rnd->nextInt(ASTEROID_MIN_VEL, ASTEROID_MAX_VEL));
		astPool.getPool()[i]->setDir({ (double)rnd->nextInt(-100, 101) / 100, (double)rnd->nextInt(-100, 101) / 100 });
		astPool.getPool()[i]->setPos({ (double)rnd->nextInt(0, game_->getWindowWidth()), (double)rnd->nextInt(0, game_->getWindowHeight()) });
		astPool.getPool()[i]->setLevel(rnd->nextInt(1, 4));
	}
}
*/