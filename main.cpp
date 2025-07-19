// main.cpp

#include <core.h>
#include <gameObject.h>
#include <player.h>

#include <SFML/Graphics.hpp>

const int WIDTH = 1024;
const int HEIGHT = 576;

using namespace GameEngine;


int main() {
	
	sf::RenderWindow renderWindow(sf::VideoMode({ WIDTH, HEIGHT }),
		"Game", sf::Style::Close);
	//renderWindow.setFramerateLimit(60);
	renderWindow.setVerticalSyncEnabled(true);
	int* choice = new int;
	
	std::cout << "Press 1 for mouse control\n"
		"Press 2 for keyboard control (Preferred)\n"
		"Enter: ";
	std::cin >> *choice;
	// create the engine first
	Engine e;


	// add all the fucking objects
	
	auto g1 = std::make_shared<GameObject>("Player", sf::Vector2f({200,200}));
	e.AddObject(g1);

	auto player = std::make_shared<Player>("My Player", sf::Vector2f({ 250,250 }));
	switch (*choice) {
	case 1:
		player->bKeyboardControl = false;
		break;
	case 2:
		player->bKeyboardControl = true;
		break;
	default:
		player->bKeyboardControl = true;
		break;
	}
	delete choice;
	e.AddObject(player);

	// then initialize or initialise the engine FUCK FINALLY
	e.Init(renderWindow);

}