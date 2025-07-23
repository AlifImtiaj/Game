// main.cpp

#include <core.h>
#include <gameObject.h>
#include <player.h>

#include <SFML/Graphics.hpp>

const int WIDTH = 1280;
const int HEIGHT = 720;
const std::string TITLE = "Game";

using namespace GameEngine;


int main() {
	
	sf::RenderWindow renderWindow(sf::VideoMode({ WIDTH, HEIGHT }),
		TITLE, sf::Style::Close);
	//renderWindow.setFramerateLimit(60);
	renderWindow.setVerticalSyncEnabled(true);
	

	// create the engine first
	Engine e;


	// add all the fucking objects
	
	/*auto g1 = std::make_shared<GameObject>("Player", sf::Vector2f({200,200}));
	e.AddObject(g1);*/

	auto player = std::make_shared<Player>("Player", 100.f, sf::Vector2f{100,200});
	e.AddObject(player);

	// then initialize the engine
	// FUCK ALL BROKE Again
	// FIXED LOL
	e.Init(renderWindow);

}