#pragma once

class Enemy
{
public:
	Enemy(float posX, float posY, int speed, int radius, int respwanTimer, bool isAlive);

	float GetPosX() const { return posX_; };
	float GetPosY() const { return posY_; };
	int GetSpeed() const { return speed_; };
	int GetRadius() const { return radius_; };
	int GetRespwanTimer() const { return respwanTimer_; };
	int GetIsAlive() const { return isAlive_; };


	void SetPosX(float posX) { posX_ = posX; }
	void SetPosY(float posY) { posY_ = posY; }
	void SetSpeed(int speed) { speed_ = speed; }
	void SetRadius(int radius) { radius_ = radius; }
	void SetRespwanTimer(int respwanTimer) { respwanTimer_ = respwanTimer; };
	void SetIsAlive(bool isAlive) { isAlive_ = isAlive; }
	virtual void Update();
	virtual void Draw();
private:
	float posX_;
	float posY_;
	int speed_;
	int radius_;
	int respwanTimer_;
	bool isAlive_;
	
};

