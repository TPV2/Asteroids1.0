#pragma once
#include "Vector2D.h"
#include "Texture.h"
#include "Resources.h"
#include "SDLGame.h"

#pragma region constantes
const double ASTEROID_W = 50;
const double ASTEROID_H = 50;
const double ASTEROID_VEL = 2;
#pragma endregion

struct Asteroid
{
private:
	Vector2D pos_;
	Vector2D scale_;	//20,40,60
	double vel_;
	Vector2D dir_;
	double angle_;
	int level_;		// 1-3 (pequeño-grande)
	bool used_ = false;
	//Texture* texture_ = nullptr; //No sé como poner la textura desde aquí
public:
	Asteroid(Vector2D pos, Vector2D scale, double angle, int level) :
		pos_(pos), scale_(scale), vel_(ASTEROID_VEL), angle_(angle), level_(level) {}
	Asteroid() :
		pos_({ 0.0,0.0 }), scale_({ ASTEROID_W, ASTEROID_H }), vel_(ASTEROID_VEL), angle_(0), level_(3) {};
	//Para saber si un objeto está en uso
	bool isUsed() { return used_; };
	//Para "setear" un objeto
	void setObject(bool status) { used_ = status; };
	void startAsteroid(Vector2D pos, Vector2D dir) {
		vel_ = ASTEROID_VEL;
		pos_ = pos;
		dir_ = dir;
		used_ = true;
	}

#pragma region getters
	const Vector2D* getPos() { return &pos_; };
	const double getVel() { return vel_; };
	const Vector2D* getScale() { return &scale_; };
	const double getAngle() { return angle_; };
	const Vector2D* getDir() { return &dir_; };
	const int getLevel() { return level_; };
#pragma endregion
#pragma region setters
	void setPos(Vector2D pos) { pos_ = pos; };
	void setVel(double vel) { vel_ = vel; };
	void setScale(Vector2D scale) { scale_ = scale; };
	void setAngle(double angle) { angle_ = angle; };
	void setDir(Vector2D dir) { dir_ = dir; };
	void setLevel(int level) { level_ = level; };
#pragma endregion

};

