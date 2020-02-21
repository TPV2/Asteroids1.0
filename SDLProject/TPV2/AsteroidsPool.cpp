#include "AsteroidsPool.h"
#include "SRandBasedGenerator.h"
#include "BulletsPool.h"

const double ASTEROID_MIN_VEL = 2.0;
const double ASTEROID_MAX_VEL = 4.0;

AsteroidsPool::AsteroidsPool() :
	Component(ecs::AsteroidsPool),
	astPool(nullptr) {}			//Asteroid::isUsed?

void AsteroidsPool::init() {
}

void AsteroidsPool::disablAll() {
	for (auto it = astPool.getPool().begin(); it != astPool.getPool().end(); ++it) {
		(*it)->setObject(false);
	}
}

//TODO:: A falta de la implementación de los asteroides
void AsteroidsPool::onCollision(/*Bullet* b, Asteroid* a*/) {

}

//Busca un bullet no usado en el pool, si lo encuentra lo activa
void AsteroidsPool::generateAsteroids(int n) {
	SRandBasedGenerator* rnd = new SRandBasedGenerator();
	auto it = astPool.getPool().begin();
	int generados = 0;
	while (generados < n) {
		if (!(*it)->isUsed()) {		//Si el asteroide al que apunta it esta desactivado
			(*it)->setObject(true);	//Lo activa
			(*it)->setAngle(rnd->nextInt(0, 360));
			(*it)->setVel(rnd->nextInt(ASTEROID_MIN_VEL, ASTEROID_MAX_VEL));
			(*it)->setPos({ (double)rnd->nextInt(0, 1920), (double)rnd->nextInt(0, 1080) });
			(*it)->setLevel(rnd->nextInt(1, 4));
			generados++;			//Aumenta el contador de generados
		}
		++it;	//El iterador aumenta siempre
	}
}
