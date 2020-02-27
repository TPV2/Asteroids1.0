#include "GameCtrl.h"
#include "Entity.h"
#include "InputHandler.h"
#include "SDL_macros.h"

GameCtrl::~GameCtrl() {
}

void GameCtrl::init() {
	scoreManager_ = GETCMP1_(ScoreManager);
}

//Comprueba el estado del juego 
void GameCtrl::update() {
	//Genera los asteroides y cambia el estado del juego para que empiece
	if (!scoreManager_->isGameOver() && !scoreManager_->isRunning()) {
		if (InputHandler::instance()->keyDownEvent()) {
			astPool_->generateAsteroids(ASTEROIDS_NUM);
			scoreManager_->setRunning(true);
		}
	}
	//Cuando el jugador se queda sin vidas
	if (health_->getLives() < 0) {

		scoreManager_->resetScore();
		health_->resetLives();
		scoreManager_->gameOver();
		scoreManager_->setRunning(false);
	}
	//Cuando el jugador a ganado
	if (scoreManager_->isRunning() && astPool_->getNumOfAsteroids() == 0) {
		scoreManager_->setRunning(false);
		scoreManager_->gameOver();
		scoreManager_->setWin(true);
	}
}

//Renderiza el mensaje de press any key
void GameCtrl::draw() {

	if (!scoreManager_->isRunning()) {
		Texture *hitanykey = game_->getTextureMngr()->getTexture(
				Resources::PressAnyKey);
		hitanykey->render(
				game_->getWindowWidth() / 2 - hitanykey->getWidth() / 2,
				game_->getWindowHeight() - hitanykey->getHeight() - 50);
	}
}
