#pragma once

#include <vector>

#include "Manager.h"
#include "SDLGame.h"

class PingPong {

public:
	PingPong();
	virtual ~PingPong();

	// from SDLGame
	void start();
	void stop();

private:
	void initGame();
	void closeGame();
	void handleInput();
	void update();
	void render();

#pragma region implementación
	void createEntities();
#pragma endregion


	SDLGame* game_;
	EntityManager* entityManager_;
	bool exit_;

	const static int _WINDOW_WIDTH_ = 1280 / 1.5; //640;
	const static int _WINDOW_HEIGHT_ = 1024 / 1.5;// 480;

};
