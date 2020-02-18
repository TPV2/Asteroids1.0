#pragma once
#include "Component.h"

#pragma region consts
const int INITIAL_LIVES = 3;
const uint HEART_X = 0;
const uint HEART_Y = 0;
const uint HEART_W = 25;
const uint HEART_H = 25;
const uint HEART_GAP = 30;
#pragma endregion

class Health :
	public Component
{
private:
	Texture* texture_ = nullptr;
	SDL_Rect* destRect_ = nullptr;
	int lives_ = INITIAL_LIVES;
public:
	Health(Texture* texture);
	~Health();
	virtual void draw() override;
	virtual void init() override;

	void restartLives() { lives_ = INITIAL_LIVES; };
	void removeLives(int amount);
	void addLives(int amount) { lives_ += amount; };
};

