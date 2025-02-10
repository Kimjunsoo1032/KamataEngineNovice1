#include "EnemyB.h"
#include <Novice.h>

EnemyB::EnemyB(){
	posX_ = 1000;
	posY_ = 150;
	speedX_ = 0;
	speedY_ = 10;
	radius_ = 20;
	isAlive = true;
	respwanTimer = 0;
}

void EnemyB::Update() {
	if (posY_ > 720) {
		isAlive=false;
	}
	if (isAlive) {
		posY_ += speedY_;
	}
}

void EnemyB::Draw() {
	if (isAlive) {
		Novice::DrawEllipse((int)posX_, (int)posY_, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
	}
}