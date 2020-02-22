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
#include "FighterMotion.h"
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

	createFighter();
	//createAsteroids();


	//Pendiente gameLogic
#pragma region Creación del game manager
	//Entity* gameManager = entityManager_->addEntity();
	//gameManager->addComponent<ScoreManager>();
	//gameManager->addComponent<GameCtrl>(GETCMP2(asteroidsPool,AsteroidsPool),GETCMP2(fighter,Health));
	//gameManager->addComponent<ScoreViewer>();
	//gameManager->addComponent<GameLogic>(GETCMP2(asteroidsPool, AsteroidsPool),
		//GETCMP2(bulletsPool, BulletsPool), GETCMP2(fighter, Health), GETCMP2(fighter, Transform));
#pragma endregion

	game_->getAudioMngr()->playMusic(Resources::March, 1);
}

void PingPong::createFighter()
{
	//Creación del avión
	Entity* fighter = entityManager_->addEntity();
	Transform* fighterTr = fighter->addComponent<Transform>();
	fighter->addComponent<FighterViewer>(game_->getTextureMngr()->getTexture(Resources::Airplanes));
	fighter->addComponent<Health>(game_->getTextureMngr()->getTexture(Resources::Heart));
	fighter->addComponent<FighterCtrl>();
	fighter->addComponent<FighterMotion>(fighterTr);
	//LINEA PARA DEBUG
	//cout << "DATOS DEL FIGHTER" << endl; cout << "POS X: " << fighterTr->getPos().getX() << endl; cout << "POS Y: " << fighterTr->getPos().getY() << endl; cout << "VEL X: " << fighterTr->getVel().getX() << endl; cout << "VEL Y: " << fighterTr->getVel().getY() << endl; cout << "WIDTH: " << fighterTr->getW() << endl; cout << "HEIGHT: " << fighterTr->getH() << endl;

	Entity* bulletsPool = entityManager_->addEntity();
	BulletsPool* pool = bulletsPool->addComponent<BulletsPool>();
	bulletsPool->addComponent<BulletsViewer>(game_->getTextureMngr()->getTexture(Resources::Bullet));
	bulletsPool->addComponent<BulletsMotion>(GETCMP2(fighter, Transform));
	fighter->addComponent<Gun>(pool);
}

void PingPong::createAsteroids()
{
	Entity* asteroidsPool = entityManager_->addEntity();
	AsteroidsPool* astPool = asteroidsPool->addComponent<AsteroidsPool>();
	astPool->generateAsteroids(10);	//10 por probar
	asteroidsPool->addComponent<AsteroidsViewer>(game_->getTextureMngr()->getTexture(Resources::Asteroid));
	asteroidsPool->addComponent<AsteroidsMotion>();
}

#pragma endregion


