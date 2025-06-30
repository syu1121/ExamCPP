#pragma once
#include "GameObject.h"
#include<vector>
#include "EnemyBeam.h"

class Player;//�O���錾
class Enemy;//�O���錾

class Stage :
    public GameObject
{
private:
    Player* player_;//�v���C���[�I�u�W�F�N�g
    std::vector<Enemy *> enemy_;//�G�̃I�u�W�F�N�g
    std::vector<EnemyBeam*> beam_;
    
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
    void PlayerVSEnemyBeam();
    int hBackground;
};

