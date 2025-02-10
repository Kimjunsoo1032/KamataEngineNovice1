#pragma once

typedef struct Transform {
	int x;
	int y;
	int radius;
}Transform;

class EnemyBullet
{
public:
	Transform bullet_;
	int speed_;
	bool isShot_;
	EnemyBullet();
	void Update();
	void Draw();
};

