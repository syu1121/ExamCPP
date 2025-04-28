#pragma once
#include "GameObject.h"
class Enemy :
    public GameObject
{
    int hImage;
    float x_, y_;
    float speed_;
public:
    Enemy();
    ~Enemy();
    void Update() override;
    void Draw() override;
};

