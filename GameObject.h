#pragma once
#include <vector>


class GameObject
{
protected:
	bool isAlive_; //弾が生きている
public:
	GameObject();
	virtual ~GameObject();
	virtual void Update() = 0;
	virtual void Draw() = 0;
	bool IsAlive() { return isAlive_; }
	void SetAlive(bool alive) { isAlive_ = alive; }; //ゲームオブジェクトの生き死に
};

extern std::vector<GameObject*> gameObjects; //ゲームオブジェクトのベクター
extern std::vector<GameObject*> newObjects;

inline void  AddGameObject(GameObject* obj)
{
	newObjects.push_back(obj); //ゲームオブジェクトをベクターに追加
}