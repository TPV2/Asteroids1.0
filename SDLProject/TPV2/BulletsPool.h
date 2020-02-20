#pragma once
#include "Component.h"
#include "ObjectPool.h"
#include "Bullet.h"
//#include <vector>

#pragma region Constantes
const uint BULLET_NUM = 10;
#pragma endregion


class BulletsPool :
	public Component
{
private:
	ObjectPool<Bullet, BULLET_NUM> obPool;
public:
	BulletsPool();
	void init() override;
	void shoot(Vector2D pos, Vector2D vel, double w, double h);
	void disablAll();
	void onCollision();
	vector<Bullet*> getPool() { return obPool.getPool(); };
};

