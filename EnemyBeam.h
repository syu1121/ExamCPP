#pragma once
#include "GameObject.h"
#include "globals.h"

class EnemyBeam :
    public GameObject
{
public:

	EnemyBeam();
	EnemyBeam(float x, float y);
	EnemyBeam(Point pos_);
	~EnemyBeam();
	void Update() override;
	void Draw() override;

	void SetPos(float x, float y) { pos_.x = x; pos_.y = y; }
	void SetPos(const Point& pos) { pos_ = pos; }
	void SetFired(bool fired) { isFired_ = fired; } // ���ˏ�Ԃ�ݒ�
	bool IsFired() const { return isFired_; } // ���ˏ�Ԃ��擾
	Rect GetRect() const { return { pos_.x, pos_.y, imageSize_.x,imageSize_.y }; } // �e�̋�`���擾
protected:
private:
	int hImage_;  //�e�̉摜�n���h��
	Point pos_;
	float speed_;
	Point imageSize_;
	//int isize_x, isize_y; //�e�̕\���T�C�Y
	bool isFired_;  //���˂���Ă��邩�ǂ��� true: ���˂���Ă���, false: ���˂���Ă��Ȃ�
};

