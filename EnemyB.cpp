#include "EnemyB.h"
#include <Novice.h>

EnemyB::EnemyB(){
	posX_ = 1000;
	posY_ = 150;
	speedX_ = 20;
	speedY_ = 0;
	radius_ = 20;
	isAlive = true;
	respwanTimer = 0;
}

void EnemyB::Update() {
	if (posX_ >= 1280 - radius_) {
		speedX_ = -20;
	}
	if (posX_ <= 0 + radius_) {
		speedX_ = 20;
	}
	posX_ += speedX_;
}

void EnemyB::Draw() {
	if (isAlive) {
		Novice::DrawEllipse((int)posX_, (int)posY_, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
	}
}