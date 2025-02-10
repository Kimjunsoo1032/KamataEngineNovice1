#pragma once

typedef struct Transform {
	int x;
	int y;
	int radius;
}Transform;

class Bullet
{
public:
	Transform bullet_;
	int speed_;
	bool isShot_;
	Bullet();
	void Update();
	void Draw();
};

