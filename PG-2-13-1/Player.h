#pragma once
#include "Bullet.h"
class Player {
public:
	Transform player_;
	int speed_;
	Bullet* bullet_;
public:
	Player();
	~Player();
	void Update(char* keys);
	void Draw();
};
