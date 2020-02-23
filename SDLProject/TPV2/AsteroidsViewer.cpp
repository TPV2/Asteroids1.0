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
				pool_->getPool()[i]->getW(), pool_->getPool()[i]->getH());	
			texture_->render(rect);

			//HAY QUE RENDERIZAR UNA COPIAS SI:
			//SE SALE POR EL LADO IZQUIERDO
			if (pool_->getPool()[i]->getPos()->getX() < 0) {
				SDL_Rect copyRect = RECT(pool_->getPool()[i]->getPos()->getX() + game_->getWindowWidth(), pool_->getPool()[i]->getPos()->getY(),
					pool_->getPool()[i]->getW(), pool_->getPool()[i]->getH());
				texture_->render(copyRect);
			}
			//SE SALE POR EL LADO DERECHO
			if (pool_->getPool()[i]->getPos()->getX() > game_->getWindowWidth()) {
				SDL_Rect copyRect = RECT(pool_->getPool()[i]->getPos()->getX() - game_->getWindowWidth(), pool_->getPool()[i]->getPos()->getY(),
					pool_->getPool()[i]->getW(), pool_->getPool()[i]->getH());
				texture_->render(copyRect);
			}
			//SE SALE ARRIBA
			if (pool_->getPool()[i]->getPos()->getY() < 0) {
				SDL_Rect copyRect = RECT(pool_->getPool()[i]->getPos()->getX(), pool_->getPool()[i]->getPos()->getY() + game_->getWindowHeight(),
					pool_->getPool()[i]->getW(), pool_->getPool()[i]->getH());
				texture_->render(copyRect);
			}
			//SE SALE ABAJO
			if (pool_->getPool()[i]->getPos()->getY() > game_->getWindowHeight()) {
				SDL_Rect copyRect = RECT(pool_->getPool()[i]->getPos()->getX(), pool_->getPool()[i]->getPos()->getY() - game_->getWindowHeight(),
					pool_->getPool()[i]->getW(), pool_->getPool()[i]->getH());
				texture_->render(copyRect);
			}
			//SE SALE POR UNA ESQUINA (FALTA Y ES IMPORTANTE)
		}
	}
}