#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "EnemyA.h"
#include "EnemyB.h"
const char kWindowTitle[] = "GC1C_02_キム_ジュンス";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;


bool Enemy::isAlive;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };


	Player* player = new Player();
	player->player_.x = kWindowWidth / 2;
	player->player_.y = 650;
	player->player_.radius = 15;
	player->speed_ = 5;

	//int bulletCount_ = 8;
	//Bullet bullets_;

	Enemy* enemy[2];
	enemy[0] = new EnemyA;
	enemy[1] = new EnemyB;

	Enemy::isAlive = true;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Update(keys);

		if (Enemy::isAlive == true) {
			for (int i = 0; i < 2; i++) {
				enemy[i]->Update();
				float distX = (float)enemy[i]->posX_ - (float)player->bullet_->bullet_.x;
				float distY = (float)enemy[i]->posY_ - (float)player->bullet_->bullet_.y;
				float dist = (distX * distX) + (distY * distY);
				float radius = ((float)enemy[i]->radius_ + (float)player->bullet_->bullet_.radius);
				if (dist <= radius * radius) {
					Enemy::isAlive = false;
				}
			}
		}
		else if (keys[DIK_R] && !preKeys[DIK_R]) {
			Enemy::isAlive = true;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->Draw();

		for (int i = 0; i < 2; i++) {
			enemy[i]->Draw();
		}
		if (enemy[1]->isAlive) {
			Novice::ScreenPrintf(0, 0, "enemyA isAlive : 1");
		}
		if (!enemy[1]->isAlive) {
			Novice::ScreenPrintf(0, 0, "enemyA isAlive : 0");
		}
		if (enemy[2]->isAlive) {
			Novice::ScreenPrintf(0, 20, "enemyA isAlive : 1");
		}
		if (!enemy[2]->isAlive) {
			Novice::ScreenPrintf(0, 20, "enemyA isAlive : 0");
		}
		Novice::ScreenPrintf(0, 40, "UP DOWN LEFT RIGHT : player Move");
		Novice::ScreenPrintf(0, 60, "shot : SPACE");
		Novice::ScreenPrintf(0, 80, "enemy respawn : R");
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
