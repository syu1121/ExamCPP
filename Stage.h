#pragma once
#include "GameObject.h"
#include<vector>

class Player;//�O���錾
class Enemy;//�O���錾

class Stage :
    public GameObject
{
private:
    Player* player_;//�v���C���[�I�u�W�F�N�g
    Enemy* cenemy_;
    std::vector<Enemy *> enemy_;//�G�̃I�u�W�F�N�g
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
    int hBackground;
};

