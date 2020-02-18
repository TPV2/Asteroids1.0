#include "FighterCtrl.h"
#include "Entity.h"

FighterCtrl::FighterCtrl(): 
	FighterCtrl(SDLK_RIGHT, SDLK_LEFT){}

FighterCtrl::FighterCtrl(SDL_Keycode right, SDL_Keycode left) :
	Component(ecs::FighterCtrl), tr_(nullptr),right_(right),left_(left){}

FighterCtrl::~FighterCtrl() {}

void FighterCtrl::init() {
	tr_ = GETCMP2_(ecs::Transform, Transform);
}


void FighterCtrl::update() {
	InputHandler* ih = InputHandler::instance();
	if (ih->keyDownEvent()) {
		if (ih->isKeyDown(right_)) {
			tr_->setVelY(tr_->getVel().getY() - 2);
		}
		else if (ih->isKeyDown(left_)) {
			tr_->setVelY(tr_->getVel().getY() + 2);
		}
	}
}
