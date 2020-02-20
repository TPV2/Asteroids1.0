#include "Gun.h"
#include "Entity.h"

void Gun::init() {
	fighterTr_ = GETCMP1_(Transform);
}

void Gun::update() {
	InputHandler* ih = InputHandler::instance();
	if (ih->keyDownEvent()) {
		if (ih->isKeyDown(space_)) {
			pool_->shoot(fighterTr_->getPos(), fighterTr_->getVel(), fighterTr_->getW(), fighterTr_->getH());
		}
	}
}