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
    static Stage* pStage_;

public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
    void PlayerVSEnemyBeam();
    int hBackground;
    void Shoot(Point pos);
    static Stage* Instance();
    static void Release();
    EnemyBeam* GetActiveBullet();

    bool IsPlayerDead() const;

};

