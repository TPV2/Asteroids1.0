#pragma once
#include "Component.h"


const uint PLANE_H = 100;
const uint PLANE_W = 100;

class Transform;
class Texture;

class FighterViewer :
	public Component
{
private:
	Transform* tr_ = nullptr;
	Texture* texture_ = nullptr;
public:
	FighterViewer(Texture* texture);//TODO: supongo que así se construye 
	~FighterViewer();
	void init() override;
	void draw() override;
};

