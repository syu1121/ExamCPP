#pragma once
#include <vector>


class GameObject
{
protected:
	bool isAlive_; //�e�������Ă���
public:
	GameObject();
	virtual ~GameObject();
	virtual void Update() = 0;
	virtual void Draw() = 0;
	bool IsAlive() { return isAlive_; }
	void SetAlive(bool alive) { isAlive_ = alive; }; //�Q�[���I�u�W�F�N�g�̐�������
};

extern std::vector<GameObject*> gameObjects; //�Q�[���I�u�W�F�N�g�̃x�N�^�[
extern std::vector<GameObject*> newObjects;

inline void  AddGameObject(GameObject* obj)
{
	newObjects.push_back(obj); //�Q�[���I�u�W�F�N�g���x�N�^�[�ɒǉ�
}