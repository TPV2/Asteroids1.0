#pragma once
#include "Vector2D.h"
//quitar clase y poner struct
struct Bullet
{
	Vector2D pos;
	Vector2D escale; //{w,h}
	Vector2D vel;
	double angle;
};


