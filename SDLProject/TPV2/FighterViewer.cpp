#include "FighterViewer.h"
#include "Texture.h"
#include "Resources.h"
#include "Entity.h"
#include "SDL_macros.h"




FighterViewer::FighterViewer(Texture* texture) :
	Component(ecs::FighterViewer),
	tr_(nullptr), texture_(texture) {
}

FighterViewer::~FighterViewer() {
	delete texture_;
}

//Inicializa el render del avión con los datos dados por el enunciado
void FighterViewer::init() {
	tr_ = GETCMP1_(Transform); 	// => tr_ = entity_->getComponent<Transform>(ecs::Transform)
	tr_->setWH(PLANE_W, PLANE_H);
	tr_->setPos({ double((game_->getWindowWidth() / 2) - PLANE_W/2),double((game_->getWindowHeight() / 2)- PLANE_H / 2) });
}

//Renderiza el avión en función del rect inicializado en init();
void FighterViewer::draw() {
	SDL_Rect destRect = RECT(tr_->getPos().getX(), tr_->getPos().getY(), tr_->getW(), tr_->getH());
	SDL_Rect clipRect = RECT(PLANE_X, PLANE_Y, PLANE_W, PLANE_H);
	texture_->render(destRect,tr_->getRot(), clipRect);
}
