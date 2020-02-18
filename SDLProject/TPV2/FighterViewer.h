#pragma once
#include "Component.h"

#pragma region const
const uint PLANE_H = 47;
const uint PLANE_W = 90;
const int PLANE_X = 207;
const int PLANE_Y = 250;
#pragma endregion


//class Transform;
class Texture;

class FighterViewer :
	public Component
{
private:
	Texture* texture_ = nullptr;		//Textura con todos los aviones
	SDL_Rect* destRect = nullptr;		//Rect del destino 
	SDL_Rect* clipRect = nullptr;		//Rect del clip a renderizar
public:
	FighterViewer(Texture* texture_);
	~FighterViewer();
	void init() override;
	void draw() override;
};

