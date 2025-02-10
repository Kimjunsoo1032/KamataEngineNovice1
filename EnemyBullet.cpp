#include "Novice.h"
#include "EnemyBullet.h"
EnemyBullet::EnemyBullet() {
	bullet_.x = -50;
	bullet_.y = -50;
	bullet_.radius = 10;
	speed_ = 15;
	isShot_ = false;
}
void EnemyBullet::Update() {
	if (isShot_ == true) {
		bullet_.y -= 10;
	}
	if (bullet_.y <= 0) {
		isShot_ = false;
	}
}
void EnemyBullet::Draw() {
	if (isShot_) {
		Novice::DrawEllipse(bullet_.x, bullet_.y, bullet_.radius, bullet_.radius, 0.0f, RED, kFillModeSolid);
	}
}