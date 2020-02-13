#include "FighterViewer.h"
#include "Entity.h"
#include "Texture.h"
#include "Resources.h"
#include "SDL_macros.h"
#include "Transform.h"


FighterViewer::FighterViewer(Texture* texture) :
	Component(ecs::FighterViewer), tr_(nullptr) ,texture_(texture) {}

FighterViewer::~FighterViewer() {}

void FighterViewer::init() {
	tr_ = GETCMP2_(ecs::Transform, Transform);
}

void FighterViewer::draw() {
	SDL_Rect rect = { tr_->getPos().getX(), tr_->getPos().getY(), tr_->getW(), tr_->getH() };
	texture_->render(game_->getRenderer(), rect);
}
