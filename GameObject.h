#pragma once
#include <string>
#include <vector>

class Collider;

class GameObject
{
public:
	std::string name;
	bool dontDestroyOnLoad = false;
	Collider* collider;
	static int id;
	int thisid;
	bool isActive = true;
	GameObject* father;
	std::vector<GameObject*> children;

	bool GetActive();
	void SetActive(bool state);
	virtual void Start();
	virtual void UpdatePhysics();
	virtual void UpdateLogic();
	virtual void Render();
	virtual void OnCollision(Collider *other);
	virtual ~GameObject() = default;
};

