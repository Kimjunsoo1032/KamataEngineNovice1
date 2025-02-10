#include "EnemyA.h"
#include <Novice.h>

EnemyA::EnemyA(){
	posX_ = 300;
	posY_ = 100;
	speedX_ = 20;
	speedY_ = 0;
	radius_ = 20;
	isAlive = true;
	respwanTimer = 0;
}

void EnemyA::Update() {
	if (posX_ >= 1280 - radius_) {
		speedX_ = -20;
	}

	if (posX_ <= 0 + radius_) {
		speedX_ = 20;
	}
	posX_ += speedX_;
}

void EnemyA::Draw() {
	if (isAlive) {
		Novice::DrawEllipse((int)posX_, (int)posY_, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
	}
}