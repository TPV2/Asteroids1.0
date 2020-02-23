#include "AsteroidsPool.h"
#include "SRandBasedGenerator.h"
#include "BulletsPool.h"


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
	while (asteroidsActive < n) {
		if (!(*it)->isUsed()) {		//Si el asteroide al que apunta it esta desactivado
			//POS, DIR, VEL, ANGLE, LEVEL
			Vector2D pos = { (double)rnd->nextInt(0, game_->getWindowWidth()), (double)rnd->nextInt(0, game_->getWindowHeight()) };
			Vector2D dir = { (double)rnd->nextInt(-101, 101) / 100.0, (double)rnd->nextInt(-101, 101) / 100.0 };
			cout << "LA POSICION DEL METEORITO " << asteroidsActive + 1 << " ES {" << pos.getX() << ", " << pos.getY() << "}" << endl;
			cout << "LA DIRECCION DEL METEORITO " << asteroidsActive + 1 << " ES {" << dir.getX() << ", " << dir.getY() << "}" << endl;
			(*it)->startAsteroid(
				pos,	//POS
				dir,													//DIR
				(rnd->nextInt(ASTEROID_MIN_VEL * 100, ASTEROID_MAX_VEL * 100)) / 100.0,										//VEL (Solucion guarra a que no se generen double aleatorios)
				rnd->nextInt(0, 360),																						//ANGLE
				rnd->nextInt(1, 4));																						//LEVEL
			asteroidsActive++;			//Aumenta el contador de generados
		}
		++it;	//El iterador aumenta siempre
	}
}
