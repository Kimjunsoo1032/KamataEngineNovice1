#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "EnemyA.h"
#include "EnemyB.h"
const char kWindowTitle[] = "GC1C_02_キム_ジュンス";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;
enum SCENE {
	TITLE,
	GAME,
	CLEAR,
	FAIL,
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//Scene
	int currentScene = TITLE; //現在のシーン

	//ハンドル
	int titleHandle = Novice::LoadTexture("./NoviceResources/title.png");
	int inGameHandle = Novice::LoadTexture("./NoviceResources/inGame.png");
	int gameClearHandle = Novice::LoadTexture("./NoviceResources/gameClear.png");
	int gameFailHandle = Novice::LoadTexture("./NoviceResources/gameFail.png");

	Player* player = new Player();
	player->player_.x = kWindowWidth / 2;
	player->player_.y = 650;
	player->player_.radius = 15;
	player->speed_ = 10;
	player->isAlive_ = true;


	Enemy* enemy[2];
	enemy[0] = new EnemyA;
	enemy[1] = new EnemyB;


	int score = 0;

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

		switch (currentScene) {

		case TITLE:
			//初期化
			score = 0;
			player->player_.x = kWindowWidth / 2;
			player->player_.y = 650;
			player->isAlive_ = true;

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				currentScene = GAME;
			}
			break;
		case GAME:
			player->Update(keys);

			for (int i = 0; i < 2; i++) {
				if (enemy[i]->isAlive) {
					enemy[i]->Update();
					float distX = (float)enemy[i]->posX_ - (float)player->bullet_->bullet_.x;
					float distY = (float)enemy[i]->posY_ - (float)player->bullet_->bullet_.y;
					float dist = (distX * distX) + (distY * distY);
					float radius = ((float)enemy[i]->radius_ + (float)player->bullet_->bullet_.radius);
					if (dist <= radius * radius && player->bullet_->isShot_) {
						enemy[i]->isAlive = false;
						score += 1;
					}

				}
				if (enemy[i]->isAlive == false && enemy[i]->respwanTimer < 100) {
					enemy[i]->respwanTimer += 1;
					if (enemy[i]->respwanTimer >= 100) {
						enemy[i]->isAlive = true;
						enemy[i]->respwanTimer = 0;
						enemy[i]->posY_ = -enemy[i]->radius_;
					}
				}
				float distanceX = (float)enemy[i]->posX_ - (float)player->player_.x;
				float distanceY = (float)enemy[i]->posY_ - (float)player->player_.y;
				float distance = (distanceX * distanceX) + (distanceY * distanceY);
				float disRadius = (float)player->player_.radius + (float)enemy[i]->radius_;
				if (distance <= disRadius*disRadius) {
					player->isAlive_ = false;
				}
				if (!player->isAlive_) {
					currentScene = FAIL;
				}
			}
			if (score >= 10) {
				currentScene = CLEAR;
			}
			break;
		case CLEAR:
			if (keys[DIK_R] && !preKeys[DIK_R]) {
				currentScene = TITLE;
			}
			break;
		case FAIL:
			if (keys[DIK_R] && !preKeys[DIK_R]) {
				currentScene = TITLE;
			}
			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		/// 

		switch (currentScene) {

		case TITLE:
			Novice::DrawSprite(0, 0, titleHandle, 1, 1, 0, WHITE);
			break;
		case GAME:
			Novice::DrawSprite(0, 0, inGameHandle, 1, 1, 0, WHITE);
			player->Draw();

			for (int i = 0; i < 2; i++) {
				enemy[i]->Draw();
			}
			Novice::ScreenPrintf(0, 20, "UP DOWN LEFT RIGHT : player Move");
			Novice::ScreenPrintf(0, 40, "shot : SPACE");
			Novice::ScreenPrintf(0, 60, "score : %d ( GOAL SCORE = 10 )", score);
			for (int i = 0; i < 2; i++) {
				Novice::ScreenPrintf(0, 80 + i * 20, "enemy respwanTimer: %d", enemy[i]->respwanTimer);
			}break;
		case CLEAR:
			Novice::DrawSprite(0, 0, gameClearHandle, 1, 1, 0, WHITE);
			break;
		case FAIL:
			Novice::DrawSprite(0, 0, gameFailHandle, 1, 1, 0, WHITE);
			break;
		}
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
