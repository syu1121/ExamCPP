#pragma once
#include "GameObject.h"
#include<vector>
#include "EnemyBeam.h"

class Player;//前方宣言
class Enemy;//前方宣言

class Stage :
    public GameObject
{
private:
    Player* player_;//プレイヤーオブジェクト
    std::vector<Enemy *> enemy_;//敵のオブジェクト
    std::vector<EnemyBeam*> beam_;
    
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
    void PlayerVSEnemyBeam();
    int hBackground;
};

