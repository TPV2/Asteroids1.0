#pragma once
#include "Component.h"
#include "BulletsPool.h"
#include "Transform.h"

class Gun :
	public Component
{
private:
	BulletsPool* pool_ = nullptr;
	SDL_Keycode space_;
	Transform* fighterTr_ = nullptr;
public:
	Gun(SDL_Keycode space, BulletsPool* pool) :
		Component(ecs::Gun), space_(space), pool_(pool), fighterTr_(nullptr) {};
	Gun(BulletsPool* pool) :
		Component(ecs::Gun), space_(SDLK_SPACE), pool_(pool), fighterTr_(nullptr) {};
	~Gun() { pool_ = nullptr; };
	virtual void update() override;
	virtual void init() override;
};

