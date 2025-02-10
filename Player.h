#pragma once
#include "Bullet.h"
class Player {
public:
	Transform player_;
	int speed_;
	Bullet* bullet_;
	int isAlive_;
public:
	Player();
	~Player();
	void Update(char* keys);
	void Draw();
};
