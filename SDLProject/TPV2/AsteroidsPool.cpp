#include "AsteroidsPool.h"
#include "SRandBasedGenerator.h"
#include "BulletsPool.h"

const double ASTEROID_MIN_VEL = 2.0;
const double ASTEROID_MAX_VEL = 4.0;
const int ASTEROIDS_NUM = 10;

AsteroidsPool::AsteroidsPool() :
	Component(ecs::AsteroidsPool),
	astPool(nullptr) {}			//Asteroid::isUsed?

void AsteroidsPool::init() {
	//generateAsteroids(ASTEROIDS_NUM);
}

void AsteroidsPool::disablAll() {
	if (astPool.isEmphy()) {
		for (int i = 0; i < astPool.getPool().size(); i++) {
			astPool.getPool()[i]->setObject(false);
		}
	}
}

//TODO:: A falta de la implementación de los asteroides
/*se llama a este método cuando un asteroide
choca con una bala. Lo que tiene que hacer es dividir el asteroide a en 2 (ver el apéndice
para más detalles).*/
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

//Busca un bullet no usado en el pool, si lo encuentra lo activa
void AsteroidsPool::generateAsteroids(int n) {
	SRandBasedGenerator* rnd = new SRandBasedGenerator();
	for (int i = 0; i < astPool.getPool().size(); i++) {
		astPool.getPool()[i]->isUsed();
		astPool.getPool()[i]->setObject(true);
		astPool.getPool()[i]->setAngle(rnd->nextInt(0, 360));
		astPool.getPool()[i]->setVel(rnd->nextInt(ASTEROID_MIN_VEL, ASTEROID_MAX_VEL));
		astPool.getPool()[i]->setPos({ (double)rnd->nextInt(0, 1280), (double)rnd->nextInt(0, 720) });
		astPool.getPool()[i]->setLevel(rnd->nextInt(1, 4));
	}
}
