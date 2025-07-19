// main.cpp

#include <core.h>
#include <gameObject.h>
#include <player.h>

#include <SFML/Graphics.hpp>

const int WIDTH = 640;
const int HEIGHT = 480;

using namespace GameEngine;


int main() {

	
	sf::RenderWindow renderWindow(sf::VideoMode({ WIDTH, HEIGHT }),
		"Game", sf::Style::Close);
	renderWindow.setFramerateLimit(60);


	// create the engine first
	Engine e;


	// add all the fucking objects
	auto g1 = std::make_shared<GameObject>("Player", sf::Vector2f({200,200}));
	e.AddObject(g1);

	auto player = std::make_shared<Player>("My Player", sf::Vector2f({ 250,250 }));
	e.AddObject(player);

	// then initialize or initialise the engine FUCK FINALLY
	e.Init(renderWindow);

}