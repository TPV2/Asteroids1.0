#include "FighterViewer.h"
#include "Entity.h"
#include "Texture.h"
#include "Resources.h"
#include "SDL_macros.h"


FighterViewer::FighterViewer(Texture* texture) :
	Component(ecs::FighterViewer), texture_(texture) {
}

FighterViewer::~FighterViewer() {
	delete texture_, destRect;
}

//Inicializa el render del avión con los datos dados por el enunciado
void FighterViewer::init() {
	destRect = new SDL_Rect({ PLANE_X,PLANE_Y,50,50 });
	clipRect = new SDL_Rect({ PLANE_H,PLANE_W,PLANE_X,PLANE_Y });
}

//Renderiza el avión en función del rect inicializado en init();
void FighterViewer::draw() {
	texture_->render(*destRect, *clipRect);
}
