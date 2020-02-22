#include "GameCtrl.h"
#include "Entity.h"
#include "InputHandler.h"

GameCtrl::~GameCtrl() {
}

void GameCtrl::init() {
	scoreManager_ = GETCMP1_(ScoreManager);
}


void GameCtrl::update() {

	if (!scoreManager_->isRunning()) {
		if (InputHandler::instance()->keyDownEvent()) {
			astPool_->generateAsteroids(ASTEROIDS_NUM);
			scoreManager_->setRunning(true);
		}
	}
	if (health_->getLives() < 0) {
		scoreManager_->setScore(0);
		health_->resetLives();
		scoreManager_->gameOver();
		scoreManager_->setRunning(false);
	}

}

void GameCtrl::draw() {

	if (!scoreManager_->isRunning()) {
		Texture *hitanykey = game_->getTextureMngr()->getTexture(
				Resources::PressAnyKey);
		hitanykey->render(
				game_->getWindowWidth() / 2 - hitanykey->getWidth() / 2,
				game_->getWindowHeight() - hitanykey->getHeight() - 50);
	}

	// game over message when game is over
	if (scoreManager_->isGameOver()) {
		Texture *gameOver = game_->getTextureMngr()->getTexture(
				Resources::GameOver);
		gameOver->render(game_->getWindowWidth() / 2 - gameOver->getWidth() / 2,
				game_->getWindowHeight() - gameOver->getHeight() - 150);
	}
}
