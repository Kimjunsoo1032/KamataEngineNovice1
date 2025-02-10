#pragma once
#include "Enemy.h"
class EnemyB : public Enemy {
public:
    EnemyB();
    void Update() override;
    void Draw() override;
};

