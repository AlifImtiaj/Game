// main.cpp

#include <core.h>
#include <gameObject.h>
#include <player.h>
#include "button.h"

#include <SFML/Graphics.hpp>

const int WIDTH = 1280;
const int HEIGHT = 720;
const std::string TITLE = "Game";

using namespace GameEngine;

int main() {
	sf::ContextSettings context;
	context.antiAliasingLevel = 0; // anti aliasing 
	
	sf::RenderWindow renderWindow(sf::VideoMode({ WIDTH, HEIGHT }),
		TITLE, sf::Style::Close);
	renderWindow.setVerticalSyncEnabled(true);

	// create the engine first
	Engine e;


	// add all the fucking objects
	
	auto player = std::make_shared<Player>("Player", 350.f, sf::Vector2f{100,200});
	player->SetSpeed(250.f);
	player->SetRadius(50.f);
	e.AddObject(player);


	//auto b3 = std::make_shared<Button>("Hello", sf::Vector2f{ 200,0 }, sf::Vector2f{ 290,100 });
	//e.AddObject(b3);
	// then initialize the engine
	// FUCK ALL BROKE Again
	// FIXED LOL
	e.Init(renderWindow);

}