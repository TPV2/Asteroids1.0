#include "SDL_macros.h"
#include "PingPong.h"
#include <assert.h>

#include "BallMoveBehaviour.h"
#include "GameCtrl.h"
#include "GameLogic.h"
#include "InputHandler.h"
#include "PaddleKBCtrl.h"
#include "PaddleMouseCtrl.h"
#include "PaddleMoveBehaviour.h"
#include "Rectangle.h"
#include "ScoreManager.h"
#include "ScoreViewer.h"
#include "SimpleMoveBahviour.h"
#include "Transform.h"
#include "SDLGame.h"

#include "SDL_macros.h"

#pragma region includesImplementación
#include "FighterViewer.h"
#include "FighterCtrl.h"
#include "Health.h"
#include "BulletsPool.h"
#include "BulletsMotion.h"
#include "BulletsViewer.h"
#include "Gun.h"
#include "AsteroidsPool.h"
#include "AsteroidsViewer.h"
#include "AsteroidsMotion.h"
#pragma endregion



using namespace std;

PingPong::PingPong() :
		game_(nullptr), //
		entityManager_(nullptr), //
		exit_(false) {
	initGame();
}

PingPong::~PingPong() {
	closeGame();
}

void PingPong::initGame() {

	game_ = SDLGame::init("Ping Pong", _WINDOW_WIDTH_, _WINDOW_HEIGHT_);
	entityManager_ = new EntityManager(game_);

	createEntities();
}

void PingPong::closeGame() {
	delete entityManager_;
}

void PingPong::start() {
	exit_ = false;

	while (!exit_) {
		Uint32 startTime = game_->getTime();

		handleInput();
		update();
		render();

		Uint32 frameTime = game_->getTime() - startTime;
		if (frameTime < 10)
			SDL_Delay(10 - frameTime);
	}
}

void PingPong::stop() {
	exit_ = true;
}

void PingPong::handleInput() {

	InputHandler *ih = InputHandler::instance();

	ih->update();

	if (ih->keyDownEvent()) {
		if (ih->isKeyDown(SDLK_ESCAPE)) {
			exit_ = true;
		}

		if (ih->isKeyDown(SDLK_f)) {
			int flags = SDL_GetWindowFlags(game_->getWindow());
			if (flags & SDL_WINDOW_FULLSCREEN) {
				SDL_SetWindowFullscreen(game_->getWindow(), 0);
			} else {
				SDL_SetWindowFullscreen(game_->getWindow(),
						SDL_WINDOW_FULLSCREEN);
			}
		}
	}

}

void PingPong::update() {
	entityManager_->update();
}

void PingPong::render() {
	SDL_SetRenderDrawColor(game_->getRenderer(), COLOR(0x00AAAAFF));
	SDL_RenderClear(game_->getRenderer());

	entityManager_->draw();

	SDL_RenderPresent(game_->getRenderer());
}

#pragma region implementación
void PingPong::createEntities() {
#pragma region creación del avión
	Entity* fighter = entityManager_->addEntity();
	Transform* fighterTR = fighter->addComponent<Transform>();
	fighter->addComponent<FighterViewer>(game_->getTextureMngr()->getTexture(Resources::Airplanes));
	fighter->addComponent<Health>(game_->getTextureMngr()->getTexture(Resources::Heart));
	fighter->addComponent<FighterCtrl>();
#pragma endregion

#pragma region creación del bullet pool
	Entity* bulletsPool = entityManager_->addEntity();
	BulletsPool* pool = bulletsPool->addComponent<BulletsPool>();
	bulletsPool->addComponent<BulletsViewer>(game_->getTextureMngr()->getTexture(Resources::Bullet));
	bulletsPool->addComponent<BulletsMotion>(fighterTR);
	fighter->addComponent<Gun>(pool);
#pragma endregion

#pragma region creación del asteroid pool
	Entity* asteroidsPool = entityManager_->addEntity();
	AsteroidsPool* astPool = asteroidsPool->addComponent<AsteroidsPool>();
	astPool->generateAsteroids(10);	//GENERA 10 ASTEROIDES PRUEBA
	asteroidsPool->addComponent<AsteroidsViewer>(game_->getTextureMngr()->getTexture(Resources::Asteroid));
	asteroidsPool->addComponent<AsteroidsMotion>();
#pragma endregion

	game_->getAudioMngr()->playMusic(Resources::March, 1);
}

#pragma endregion


