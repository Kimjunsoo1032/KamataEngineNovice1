#include "Novice.h"
#include "Bullet.h"
Bullet::Bullet(float posX, float posY, int radius, int speed, bool isShot) {
	posX_ = posX;
	posY_ = posY;
	speed_ = speed;
	radius_ = radius;
	isShot_ = isShot;
}
void Bullet::Update(char* keys,int x, int y) {
	if (isShot_) {
		posY_ -= speed_;
	}
	if (posY_ <= 0) {
		isShot_ = false;
	}
	if (keys[DIK_SPACE]) {
		if (!isShot_) {
			isShot_ = true;
			posX_ = float(x);
			posY_ = float(y);
		}

	}
}
void Bullet::Draw() {
	if (isShot_) {
		Novice::DrawEllipse((int)posX_, (int)posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}
