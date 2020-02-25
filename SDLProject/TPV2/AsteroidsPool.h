#pragma once
#include "Component.h"
#include "ObjectPool.h"
#include "Asteroid.h"

#pragma region Constantes
const uint ASTEROID_NUM = 30;
#pragma endregion

class Bullet;

class AsteroidsPool : public Component
{
private:
	ObjectPool<Asteroid, ASTEROID_NUM> astPool;
public:
	AsteroidsPool();
	void init() override;
	void generateAsteroids(int n);
	void disablAll();
	void onCollision(Bullet* b, Asteroid* a);
	vector<Asteroid*> getPool() { return astPool.getPool(); };
};

