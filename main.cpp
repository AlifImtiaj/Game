#include <core.h>


const int WIDTH = 640;
const int HEIGHT = 480;

using namespace GameEngine;

int main() {
	sf::RenderWindow renderWindow(sf::VideoMode({ WIDTH, HEIGHT }), "Game", sf::Style::Close);
	renderWindow.setFramerateLimit(60);

	Engine e;
	e.Init(renderWindow);
}