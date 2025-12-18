#include "TestScene2.h"
#include "TestScene.h"
#include "Button.h"
#include <iostream>
#include "SceneManager.h"

TestScene2::TestScene2()
{
	std::cout << "Loading test scene 2" << std::endl;
	objects.push_back(new Button(
		sf::Vector2u(400, 250),
		sf::Vector2u(300, 200),
		1,
		[]() {
			std::cout << "Clicking button 1" << std::endl;
			SceneManager::LoadScene(new TestScene());
		}
	));
}
