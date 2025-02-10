#include "Novice.h"
#include "Player.h"
Player::Player(float posX, float posY, int speed, bool isAlive, int radius) {
	posX_ = posX;
	posY_ = posY;
	speed_ = speed;
	radius_ = radius;
	isAlive_ = isAlive;
}
void Player::Update(char* keys) {
	if (keys[DIK_UP]) {
		posY_ -= speed_;
	}

	if (keys[DIK_DOWN]) {
		posY_ += speed_;
	}

	if (keys[DIK_RIGHT]) {
		posX_ += speed_;
	}

	if (keys[DIK_LEFT]) {
		posX_ -= speed_;
	}
}
void Player::Draw() {
	Novice::DrawEllipse((int)posX_, (int)posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
}