#pragma once
#include "Component.h"
#include "Transform.h"

class FighterCtrl :
	public Component
{
private:
	Transform* tr_;

public:
	FighterCtrl();
	~FighterCtrl();
	void init() override;
	void update() override;
};

