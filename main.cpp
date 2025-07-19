#include <core.h>
#include <gameObject.h>

const int WIDTH = 640;
const int HEIGHT = 480;

using namespace GameEngine;



int main() {
	GameObject g1("Name");
	{
		GameObject g2;
		GameObject g3;
		GameObject g43("123123");
	}
	GameObject g5;

	std::cout << g5.GetName() << std::endl;

	sf::RenderWindow renderWindow(sf::VideoMode({ WIDTH, HEIGHT }),
		"Game", sf::Style::Close);
	renderWindow.setFramerateLimit(60);

	Engine e;
	e.Init(renderWindow);
}