#include "TestScene.h"
#include "TestScene2.h"
#include "Button.h"
#include "SceneManager.h"
#include <iostream>

TestScene::TestScene()
{
	std::cout << "Loading test scene 1" << std::endl;
	objects.push_back(new Button(
		{ 800, 350 },
		{ 400, 200 },
		2,
		[]() {
			std::cout << "Clicking button 2" << std::endl;
			SceneManager::LoadScene(new TestScene2());
		}
	));
	objects.push_back(new Text({ 400,250 }, "Hello world", sf::Color(0, 0, 0), "Arial.ttf", 24));
}
