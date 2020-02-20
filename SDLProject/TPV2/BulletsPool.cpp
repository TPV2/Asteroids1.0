#include "BulletsPool.h"

BulletsPool::BulletsPool() :
	Component(ecs::BulletsPool),
	obPool(nullptr){}//Bullet::isUsed?

void BulletsPool::init() {
}

void BulletsPool::disablAll() {
	for (auto it = obPool.getPool().begin(); it != obPool.getPool().end(); ++it) {
		(*it)->setObject(false);
	}
}

//TODO:: A falta de la implementación de los asteroides
void BulletsPool::onCollision(/*Bullet* b, Asteroid* a*/) {

}

//Busca un bullet no usado en el pool, si lo encuentra lo activa
void BulletsPool::shoot(Vector2D pos, Vector2D vel, double w, double h) {
	bool founded = false;
	int count = 0;

	while (!founded && count < obPool.getPool().size())
	{
		if (!obPool.getPool()[count]->isUsed()) {
			obPool.getPool()[count]->startBullet(pos, vel);
			founded = true;
		}
		else
		{
			count++;
		}
	}
	system("cls");
	for (int i = 0; i < obPool.getPool().size(); i++) {
		cout << "Bala " << i << " " << obPool.getPool()[i]->isUsed() << endl;
	}
}