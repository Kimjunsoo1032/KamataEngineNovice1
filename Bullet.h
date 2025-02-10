#pragma once
typedef struct Transform {
	int x;
	int y;
	int radius;
}Transform;

class Bullet
{
public:
	Bullet(float posX, float posY, int speed, int radius, bool isShot);
	void Update(char *keys,int x, int y);
	void Draw();
	float GetPosX() const { return posX_; };
	float GetPosY() const { return posY_; };
	int GetSpeed() const { return speed_; };
	int GetRadius() const { return radius_; };
	int GetIsShot() const { return isShot_; };

	void SetPosX(float posX) { posX_ = posX; }
	void SetPosY(float posY) { posY_ = posY; }
	void SetSpeed(int speed) { speed_ = speed; }
	void SetRadius(int radius) { radius_ = radius; }
	void SetIsAlive(bool isAlive) { isShot_ = isAlive; }
private:
	float posX_;
	float posY_;
	int speed_;
	int radius_;
	int isShot_;

};

