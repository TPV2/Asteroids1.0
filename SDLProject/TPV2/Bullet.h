#pragma once
#include "Vector2D.h"
#include "Texture.h"
#include "Resources.h"
#include "SDLGame.h"

struct Bullet
{
private:
	Vector2D pos_;
	Vector2D scale_;
	Vector2D vel_;
	double angle_;
	bool used_ = false;
	//Texture* texture_ = nullptr; //No sé como poner la textura desde aquí
public:
	Bullet(Vector2D pos, Vector2D scale, Vector2D vel, double angle) :
		pos_(pos), scale_(scale), vel_(vel), angle_(angle) {}
	Bullet() :
		pos_({ 0.0,0.0 }), scale_({ 0.0,0.0 }), vel_({ 0.0,0.0 }), angle_(0) {}
	//Para saber si un objeto está en uso
	bool isUsed() { return used_; };
	//Para "setear" un objeto
	void setObject(bool status) { used_ = status; };
	void startBullet(Vector2D pos, Vector2D vel) {
		pos_ = pos;
		vel_ = vel;
		used_ = true;
	}


#pragma region getters
	const Vector2D* getPos() { return &pos_; };
	const Vector2D* getVel() { return &vel_; };
	const Vector2D* getScale() { return &scale_; };
	const double* getAngle() { return &angle_; };
#pragma endregion
#pragma region setters
	void setPos(Vector2D pos) { pos_ = pos; };
	void setVel(Vector2D vel) { vel_ = vel; };
	void setScale(Vector2D scale) { scale_ = scale; };
	void setAngle(double angle) { angle_ = angle; };
#pragma endregion

};




