#include "EnemyA.h"
#include <Novice.h>

EnemyA::EnemyA(){
	posX_ = 300;
	posY_ = 200;
	speedX_ = 25;
	speedY_ = 0;
	radius_ = 15;
}

void EnemyA::Update() {
	if (posX_ >= 1280 - radius_) {
		speedX_ = -25;
	}

	if (posX_ <= 0 + radius_) {
		speedX_ = 25;
	}
	posX_ += speedX_;
}

void EnemyA::Draw() {
	if (isAlive) {
		Novice::DrawEllipse((int)posX_, (int)posY_, radius_, radius_, 0.0f, BLACK, kFillModeSolid);
	}
}