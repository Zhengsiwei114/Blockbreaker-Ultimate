#include "Engine.h"
#include "GameObject.h"
#include "Camera.h"
#include "Input.h"
#include "SFML/Graphics.hpp"
#include "UI.h"
#include "SceneManager.h"
#include <vector>
#include <iostream>

namespace Engine
{
    void Initialize()
    {
        SceneManager::LoadScene(dynamic_cast<Scene*>(new TestScene()));
        window = new sf::RenderWindow(sf::VideoMode({ 1920, 1080 }), "Blockbreaker!");
        window->setFramerateLimit(120);
        Input::ResetKeyMap();
    }

    void Update()
    {
        UpdatePhysics();
        UpdateGameLogic();
        Render();
    }

    void UpdatePhysics()
    {
        for (auto &[key, obj] : objects) {
            if (obj->GetActive()) {
                obj->UpdatePhysics();
            }
        }
    }

    void UpdateGameLogic()
    {
        for (auto &[key, obj] : objects) {
            if (obj->GetActive()) {
                obj->UpdateLogic();
            }
        }
    }

    void Render()
    {
        for (auto &[key, obj] : objects) {
            if (obj->GetActive()) {
                obj->Render();
            }
        }
    }

    void Run()
    {
        while (window->isOpen())
        {
            window->clear();
            static bool isFocused = true;
            while (const std::optional<sf::Event> event = window->pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    window->close();
                }
                if (event->is<sf::Event::FocusGained>())
                {
                    isFocused = true;
                }
                if (event->is<sf::Event::FocusLost>())
                {
                    isFocused = false;
                }
                if (const auto mouse = event->getIf<sf::Event::MouseButtonPressed>())
                {
                    if (mouse->button == sf::Mouse::Button::Left) {
                        std::vector<UI*> uis;
                        int topLayer = INT32_MIN;
                        for (auto &[key, obj] : objects)
                        {
                            UI* ui = dynamic_cast<UI*>(obj);
                            if (ui && ui->GetActive() && ui->Enclose(mouse->position.x, mouse->position.y))
                            {
                                uis.push_back(ui);
                                topLayer = ui->layer > topLayer ? ui->layer : topLayer;
                            }
                        }
                        for (auto ui : uis)
                        {
                            if (ui->layer == topLayer)
                            {
                                ui->OnClick();
                            }
                        }
                    }
                }
            }
            if (isFocused) Update();

            //std::cout << "Display." << std::endl;
            window->display();
        }
    }

    void Destroy(GameObject* obj)
    {
        for (auto child : obj->children) {
            Destroy(child);
        }
        objects.erase(obj->name);
        delete obj;
    }

    GameObject* CreateObject(std::string name, GameObject* obj, GameObject* father)
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

    sf::RenderWindow* window;

    std::unordered_map<std::string, GameObject*> objects;
    std::vector<Camera*> cameras;
}