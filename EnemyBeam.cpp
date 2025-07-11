#include "EnemyBeam.h"
#include <DxLib.h>
#include "Player.h"

namespace
{

	const int ENEMY_BEAM_IMAGE_WIDTH = 11;
	const int ENEMY_BEAM_IMAGE_HEIGHT = 21;
	const float ENEMY_BEAM_INIT_SPEED = 250.0f;
	
	
}

EnemyBeam::EnemyBeam()
	:EnemyBeam(0, 0)
{
	
}

EnemyBeam::EnemyBeam(float x, float y)
	:GameObject(), hImage_(-1), pos_({ x, y }), speed_(ENEMY_BEAM_INIT_SPEED), isFired_(true), imageSize_({ ENEMY_BEAM_IMAGE_WIDTH, ENEMY_BEAM_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Assets\\ebeams.png");
	SetFired(false);
	AddGameObject(this);
}

EnemyBeam::EnemyBeam(Point pos_)
	:EnemyBeam(pos_.x, pos_.y)
{
	
}

EnemyBeam::~EnemyBeam()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);
	}
	hImage_ = -1;
}

void EnemyBeam::Update()
{
	float dt = GetDeltaTime();
	pos_.y = pos_.y + speed_ * dt;
	if (pos_.y > WIN_HEIGHT)
	{
		isFired_ = false;
		SetAlive(false);
	}
}

void EnemyBeam::Draw()
{
	if (isFired_)
	{
		DrawExtendGraph(pos_.x, pos_.y, pos_.x + imageSize_.x, pos_.y + imageSize_.y, hImage_, TRUE);
	}
}


