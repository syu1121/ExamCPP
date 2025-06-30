#include "DxLib.h"
#include "Player.h"
#include "globals.h"
#include "Input.h"
#include "Enemy.h"
#include "Stage.h"
#include<vector>


enum GAMESTATE
{
	TITLE,
	PLAY,
	GAMEOVER,
	MAXSTATE
};

namespace
{
	const int BGCOLOR[3] = { 0,0,0 };//背景色
	int crrTime;
	int prevTime;
}

std::vector<GameObject*> gameObjects; //ゲームオブジェクトのベクター
std::vector<GameObject*> newObjects; //ゲームオブジェクトのベクター

GAMESTATE state;

float gDeltaTime = 0.0f; //フレームの時間差

void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BGCOLOR[0], BGCOLOR[1], BGCOLOR[2]);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}

void MyGame()
{

	DrawFormatString(100, 100, GetColor(0, 0, 0), "ウィンドウのテスト");
	static int timer = 0;
	timer++;
	DrawFormatString(100, 150, GetColor(0, 0, 0), "%010d", timer);
}

void TitleUpdate()
{

}

void TitleDraw()
{
	DrawString(100, 100, "TITLE", GetColor(0, 0, 0));
}
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxInit();
	crrTime = GetNowCount();
	prevTime = GetNowCount();


	state = GAMESTATE::TITLE;

	Stage::Instance();

	while (true)
	{
		
		ClearDrawScreen();
		Input::KeyStateUpdate();//キー入力の状態を更新

		crrTime = GetNowCount();// 現在の時間を取得
		float deltaTime = (crrTime - prevTime) / 1000.0f; //秒単位に変換
		gDeltaTime = deltaTime; //グローバル変数に保存
		
		//ここにやりたい処理を書く(ここから)
		// ゲームオブジェクトの追加
		if (newObjects.size() > 0)
		{
			for (auto& obj : newObjects)
			{
				gameObjects.push_back(obj);
			}
			newObjects.clear();
		}
		//gameObjectsの更新
		for (auto& obj : gameObjects)
		{
			obj->Update();//ゲームオブジェクトの更新
		}
		//gameObjectsの描画
		for (auto& obj : gameObjects)
		{
			obj->Draw();//ゲームオブジェクトの描画
		}

		for (auto it = gameObjects.begin();it != gameObjects.end();)
		{
			if (!(*it)->IsAlive())
			{
				delete* it;
				it = gameObjects.erase(it);
			}
			else
			{
				++it;
			}
		}
		//ここにやりたい処理を描く(ここまで)

		switch (state)
		{
		case TITLE:
			TitleUpdate();
			TitleDraw();
			break;
		case PLAY:
			break;
		case GAMEOVER:
			break;
		default:
			break;
		}
		ScreenFlip();
		WaitTimer(16);

		prevTime = crrTime; // 現在の時間を前回の時間として保存

		if (ProcessMessage() == -1)
			break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	Stage::Release();
	DxLib_End();
	return 0;
}