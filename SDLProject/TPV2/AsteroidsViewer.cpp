#include "AsteroidsViewer.h"
#include "AsteroidsPool.h"
#include "SDL_macros.h"
#include <SDL_rect.h>
#include "Entity.h"

void AsteroidsViewer::init() {
	pool_ = GETCMP1_(AsteroidsPool);
}

//Si un bullet está siendo usado, se renderiza
void AsteroidsViewer::draw() {
	for (int i = 0; i < pool_->getPool().size(); i++) {
		if (pool_->getPool()[i]->isUsed()) {
			SDL_Rect rect = RECT(pool_->getPool()[i]->getPos()->getX(), pool_->getPool()[i]->getPos()->getY(),
				pool_->getPool()[i]->getScale()->getX() * pool_->getPool()[i]->getLevel(),							//De momento para cambiar los tamaños, multiplico el nivel por la escala,
				pool_->getPool()[i]->getScale()->getY() * pool_->getPool()[i]->getLevel());							//Hay que preguntar al profe si se hace así
			texture_->render(rect);
			/*system("cls");
			cout << "Bala " << i << " " << pool_->getPool()[i]->isUsed() <<
				" pos " << *pool_->getPool()[i]->getPos() <<
				" vel " << *pool_->getPool()[i]->getVel() <<
				endl;*/
		}
	}
}