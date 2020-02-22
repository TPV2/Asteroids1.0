#include "BulletsViewer.h"
#include "BulletsPool.h"
#include "SDL_macros.h"
#include <SDL_rect.h>
#include "Entity.h"

void BulletsViewer::init() {
	pool_ = GETCMP1_(BulletsPool);
}

//Si un bullet está siendo usado, se renderiza
void BulletsViewer::draw() {
	for (int i = 0; i < pool_->getPool().size(); i++) {
		if (pool_->getPool()[i]->isUsed()) {
			SDL_Rect rect = RECT(pool_->getPool()[i]->getPos()->getX(), pool_->getPool()[i]->getPos()->getY(),
				pool_->getPool()[i]->getScale()->getX(), pool_->getPool()[i]->getScale()->getY());
			texture_->render(rect);
			/*system("cls");
			cout << "Bala " << i << " " << pool_->getPool()[i]->isUsed() <<
				" pos " << *pool_->getPool()[i]->getPos() <<
				" vel " << *pool_->getPool()[i]->getVel() <<
				endl;*/
		}
	}
}