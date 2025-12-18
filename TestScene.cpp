#include "TestScene.h"
#include "Button.h"
#include <iostream>

TestScene::TestScene()
{
	objects.push_back(new Button(
		sf::Vector2u(400, 250),
		sf::Vector2u(300, 200),
		1,
		[]() {std::cout << "Clicking button 1" << std::endl;}
	));
	objects.push_back(new Button(
		{ 800, 350 },
		{ 400, 200 },
		2,
		[]() {std::cout << "Clicking button 2" << std::endl; }
	));
	objects.push_back(new Button(
		{ 600, 300 },
		{ 400, 200 },
		3,
		[]() {std::cout << "Clicking button 3" << std::endl; }
	));
	objects.push_back(new UI(
		{ 600, 300 },
		{ 400, 200 },
		4
	));
}
