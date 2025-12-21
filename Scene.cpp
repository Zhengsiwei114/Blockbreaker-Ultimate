#include "Scene.h"
#include "GameObject.h"
#include <iostream>

GameObject* Scene::CreateObject(std::string name, GameObject* obj, GameObject* father)
{
    obj->name = name;
    obj->father = father;
    if (father) {
        father->children.push_back(obj);
    }
    if (objects.find(name) == objects.end()) {
        objects[name] = obj;
    }
    else {
        std::cerr << "Error: GameObject with name \"" << name << "\" has already been created" << std::endl;
        delete obj;
        obj = nullptr;
    }
    return obj;
}

Scene::Scene()
{
}
