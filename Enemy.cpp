#include "Enemy.h"
#include "Novice.h"
Enemy::Enemy(float posX, float posY, int speed, int radius, int respwanTimer, bool isAlive) {
	posX_ = posX;
	posY_ = posY;
	speed_ = speed;
	radius_ = radius;
	respwanTimer_ = respwanTimer;
	isAlive_ = isAlive;
}
void Enemy::Update(){
	if (posY_ > 720) {
		isAlive_ = false;
	}
	if (isAlive_) {
		posY_ += speed_;
	}
}
void Enemy::Draw(){
	if (isAlive_) {
		Novice::DrawEllipse((int)posX_, (int)posY_, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
	}
}