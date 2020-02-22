#pragma once

#include "Component.h"

class ScoreManager: public Component {
private:
	bool running_;
	bool gameOver_;
	int score_;

public:
	ScoreManager() : Component(ecs::ScoreManager), running_(false), score_(0),gameOver_(false) {}
	~ScoreManager() {};
#pragma region getters
	const int getScore() { return score_; };
	bool isRunning() const { return running_; };
	bool isGameOver() const { return gameOver_; };
#pragma endregion
#pragma region setters
	void setScore(int value) { score_ = value; };
	void setRunning(bool running) { running_ = running; };
	void gameOver() { gameOver_ = false; };
#pragma endregion
};
