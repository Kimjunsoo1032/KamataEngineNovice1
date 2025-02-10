#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "Bullet.h"
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

	Player* player = new Player(kWindowWidth / 2, 650, 15, true, 10);


	Enemy* enemy[2];
	enemy[0] = new Enemy(200, 0, 15, 20, 0, true);
	enemy[1] = new Enemy(800, 0, 15, 20, 0, true);

	Bullet* bullet_ = new Bullet(0, 0, 5, 20, false);

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
			player->SetPosX(kWindowWidth / 2);
			player->SetPosX(650);
			player->SetIsAlive(true);

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				currentScene = GAME;
			}
			break;
		case GAME:
			player->Update(keys);
			bullet_->Update(keys, (int)player->GetPosX(), (int)player->GetPosY());
			for (int i = 0; i < 2; i++) {
				if (enemy[i]->GetIsAlive()) {
					enemy[i]->Update();
					float distX = (float)enemy[i]->GetPosX() - (float)bullet_->GetPosX();
					float distY = (float)enemy[i]->GetPosY() - (float)bullet_->GetPosY();
					float dist = (distX * distX) + (distY * distY);
					float radius = ((float)enemy[i]->GetRadius() + (float)bullet_->GetRadius());
					if (dist <= radius * radius && bullet_->GetIsShot()) {
						enemy[i]->SetIsAlive(false);
						score += 1;
					}

				}
				if (enemy[i]->GetIsAlive()==false && enemy[i]->GetRespwanTimer() < 100) {
					enemy[i]->SetRespwanTimer(enemy[i]->GetRespwanTimer()+1);
					if (enemy[i]->GetRespwanTimer() >= 100) {
						enemy[i]->SetIsAlive(true);
						enemy[i]->SetRespwanTimer(0);
						enemy[i]->SetPosY((float)-enemy[i]->GetRadius());
					}
				}
				float distanceX = (float)enemy[i]->GetPosX() - (float)player->GetPosX();
				float distanceY = (float)enemy[i]->GetPosY() - (float)player->GetPosY();
				float distance = (distanceX * distanceX) + (distanceY * distanceY);
				float disRadius = (float)player->GetRadius() + (float)enemy[i]->GetRadius();
				if (distance <= disRadius * disRadius) {
					player->SetIsAlive(false);
				}
				if (!player->GetIsAlive()) {
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

			bullet_->Draw();

			for (int i = 0; i < 2; i++) {
				enemy[i]->Draw();
			}
			Novice::ScreenPrintf(0, 20, "UP DOWN LEFT RIGHT : player Move");
			Novice::ScreenPrintf(0, 40, "shot : SPACE");
			Novice::ScreenPrintf(0, 60, "score : %d ( GOAL SCORE = 10 )", score);
			for (int i = 0; i < 2; i++) {
				Novice::ScreenPrintf(0, 80 + i * 20, "enemy respwanTimer: %d", enemy[i]->GetRespwanTimer());
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
