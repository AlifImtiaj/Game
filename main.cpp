// main.cpp

#include <core.h>
#include <gameObject.h>
#include <player.h>

#include <SFML/Graphics.hpp>

const int WIDTH = 1280;
const int HEIGHT = 720;

using namespace GameEngine;


int main() {
	
	sf::RenderWindow renderWindow(sf::VideoMode({ WIDTH, HEIGHT }),
		"Game", sf::Style::Close);
	//renderWindow.setFramerateLimit(60);
	renderWindow.setVerticalSyncEnabled(true);
	

	// create the engine first
	Engine e;


	// add all the fucking objects
	
	auto g1 = std::make_shared<GameObject>("Player", sf::Vector2f({200,200}));
	e.AddObject(g1);

	auto player = std::make_shared<Player>("My Player", 200.f);
	e.AddObject(player);

	// then initialize the engine
	// FUCK ALL BROKE Again
	// FIXED LOL
	e.Init(renderWindow);

}