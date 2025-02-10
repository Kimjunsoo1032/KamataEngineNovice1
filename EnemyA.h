#pragma once
#include "Enemy.h"

class EnemyA : public Enemy {
public:
    EnemyA();
    void Update() override;
    void Draw() override;
};
