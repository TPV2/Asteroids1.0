#pragma once
#include "Component.h"
#include "Transform.h"
#include <SDL_rect.h>

#pragma region const
const uint PLANE_X = 47;
const uint PLANE_Y = 90;
const int PLANE_W = 207;
const int PLANE_H = 250;
#pragma endregion


//class Transform;
class Texture;

class FighterViewer :
	public Component
{
private:
	Texture* texture_ = nullptr;		//Textura con todos los aviones
	Transform* tr_ = nullptr;			//puntero al transform del objeto
public:
	FighterViewer(Texture* texture_);
	~FighterViewer();
	void init() override;
	void draw() override;
};

