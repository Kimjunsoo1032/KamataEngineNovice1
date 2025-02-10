#pragma once
#include "Bullet.h"
class Player {
public:
	Player(float posX, float posY, int speed, bool isAlive, int radius);

	void Update(char* keys);
	void Draw();

	float GetPosX() const { return posX_; };
	float GetPosY() const { return posY_; };
	int GetSpeed() const { return speed_; };
	int GetIsAlive() const { return isAlive_; };
	int GetRadius() const { return radius_; };

	void SetPosX(float posX) { posX_ = posX; }
	void SetPosY(float posY) { posY_ = posY; }
	void SetSpeed(int speed) { speed_ = speed; }
    void SetIsAlive(bool isAlive) { isAlive_ = isAlive; }
	void SetRadius(int radius) { radius_ = radius; }

public:
private:
	float posX_;
	float posY_;
	int speed_;
	bool isAlive_;
	int radius_;
};
