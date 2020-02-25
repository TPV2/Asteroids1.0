#include "GameCtrl.h"
#include "Entity.h"
#include "InputHandler.h"
#include "SDL_macros.h"

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

		scoreManager_->resetScore();
		health_->resetLives();
		scoreManager_->gameOver();
		scoreManager_->setRunning(false);
	}
	//TODO
	/*if (astPool_->getNumOfAsteroids() == 0) {
		scoreManager_->setRunning(false);
		scoreManager_->gameOver();
	}*/

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
	else if(scoreManager_->isGameOver()) {
		Texture *gameOver = game_->getTextureMngr()->getTexture(
				Resources::GameOver);
		gameOver->render(game_->getWindowWidth() / 2 - gameOver->getWidth() / 2,
				game_->getWindowHeight() - gameOver->getHeight() - 150);
	}
}
