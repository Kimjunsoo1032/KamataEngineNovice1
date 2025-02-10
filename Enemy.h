#pragma once

class Enemy
{
public:
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;
	int respwanTimer;
	int isAlive;
	virtual void Update();
	virtual void Draw();
};

