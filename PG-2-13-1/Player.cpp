#include "Novice.h"
#include "Player.h"

Player::Player() {
	player_.x = 0;
	player_.y = 0;
	player_.radius = 0;
	speed_ = 0;
	bullet_ = new Bullet;
}
Player::~Player() {
	delete bullet_;
}
void Player::Update(char* keys) {
	if (keys[DIK_UP]) {
		player_.y -= speed_;
	}

	if (keys[DIK_DOWN]) {
		player_.y += speed_;
	}

	if (keys[DIK_RIGHT]) {
		player_.x += speed_;
	}

	if (keys[DIK_LEFT]) {
		player_.x -= speed_;
	}

	bullet_->Update();
	if (keys[DIK_SPACE]) {
		if (!bullet_->isShot_) {
			bullet_->isShot_ = true;
			bullet_->bullet_.x = player_.x;
			bullet_->bullet_.y = player_.y;
		}

	}
}
//for (int i = 0; i < bulletCount_; i++) {
//	float a = static_cast<float>(bullets_[i].transform_.x - enemy.pos_.x);
//	float b = static_cast<float>(bullets_[i].transform_.y - enemy.pos_.y);
//	float distance = sqrtf(a * a + b * b);
//}
void Player::Draw() {

	bullet_->Draw();

	Novice::DrawEllipse(player_.x, player_.y, player_.radius, player_.radius, 0.0f, WHITE, kFillModeSolid);
}