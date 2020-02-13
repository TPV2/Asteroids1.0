#include "FighterCtrl.h"
#include "Entity.h"


FighterCtrl::FighterCtrl() :
	Component(ecs::FighterCtrl), tr_(nullptr){}

FighterCtrl::~FighterCtrl() {}

void FighterCtrl::init() {
	tr_ = GETCMP2_(ecs::Transform, Transform);
}


void FighterCtrl::update() {

}
