#include "TestScene.h"
#include "TestScene2.h"
#include "Button.h"
#include "SceneManager.h"
#include "Text.h"
#include "SFML/System.hpp"
#include <iostream>

TestScene::TestScene()
{
	std::cout << "Loading test scene 1" << std::endl;
	objects.push_back(new Button(
		{ 300, 300 },
		{ 240, 200 },
		2,
		[]() {
			std::cout << "Clicking button 1" << std::endl;
			SceneManager::LoadScene(new TestScene2());
		}
	));
	objects.push_back(new Text({ 300,300 }, L"ÈË£¬¹ýÀ´", sf::Color(255, 127, 63), "Deng.ttf", 32));
}
