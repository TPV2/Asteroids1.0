#pragma once
#include "Component.h"
#include "Transform.h"

class FighterCtrl :
	public Component
{
private:
	Transform* tr_;
	SDL_Keycode right_;
	SDL_Keycode left_;

public:
	FighterCtrl();
	FighterCtrl(SDL_Keycode right, SDL_Keycode left);
	~FighterCtrl();
	void init() override;
	void update() override;
};

