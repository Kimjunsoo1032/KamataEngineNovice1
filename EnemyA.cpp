#include "EnemyA.h"
#include <Novice.h>

EnemyA::EnemyA(){
	posX_ = 300;
	posY_ = 100;
	speedX_ = 0;
	speedY_ = 10;
	radius_ = 20;
	isAlive = true;
	respwanTimer = 0;
}

void EnemyA::Update() {
	if (posY_ > 720) {
		isAlive = false;
	}
	if (isAlive) {
		posY_ += speedY_;
	}
}

void EnemyA::Draw() {
	if (isAlive) {
		Novice::DrawEllipse((int)posX_, (int)posY_, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
	}
}