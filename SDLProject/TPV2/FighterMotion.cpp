#include "FighterMotion.h"
#include "SDL_macros.h"
#include "Entity.h"


//Comprueba si un bullet está siendo usado, si es así, modifica la velocidad y posición
void FighterMotion::update() {
	//Sale por los lados
	if (fighterTr_->getPos().getX() < 0.0 || fighterTr_->getPos().getX() + fighterTr_->getW() > game_->getWindowWidth()) {
		fighterTr_->setVel(-fighterTr_->getVel().getX(), fighterTr_->getVel().getY());
		cout << "Rotacion antes del choque: " << fighterTr_->getRot() << endl;
		fighterTr_->setRot(-fighterTr_->getRot());
		cout << "Rotacion despues del choque: " << fighterTr_->getRot() << endl;
	} 

	//Sale por extremos
	if (fighterTr_->getPos().getY() < 0.0 || fighterTr_->getPos().getY() + fighterTr_->getH() > game_->getWindowHeight()) {
		fighterTr_->setVel(fighterTr_->getVel().getX(), -fighterTr_->getVel().getY());
		cout << "Rotacion antes del choque: " << fighterTr_->getRot() << endl;
		fighterTr_->setRot(180 - fighterTr_->getRot());
		cout << "Rotacion despues del choque: " << fighterTr_->getRot() << endl;
	}

	//BUG (No lo borres Amaro, preguntame :D )
	if (fighterTr_->getPos().getX() < 0.0) fighterTr_->setPos(0.0, fighterTr_->getPos().getY());
	else if (fighterTr_->getPos().getX() > game_->getWindowWidth()) fighterTr_->setPos(game_->getWindowWidth(), fighterTr_->getPos().getY());
	if (fighterTr_->getPos().getY() < 0.0) fighterTr_->setPos(fighterTr_->getPos().getX(), 0.0);
	else if (fighterTr_->getPos().getY() > game_->getWindowHeight()) fighterTr_->setPos(fighterTr_->getPos().getX(), game_->getWindowHeight());

	fighterTr_->setPosX(fighterTr_->getPos().getX() + fighterTr_->getVel().getX());
	fighterTr_->setPosY(fighterTr_->getPos().getY() + fighterTr_->getVel().getY());
}