// gameObject.cpp

#include <gameObject.h>

namespace GameEngine {
	int GameObject::gameObjCount = 0;
	// constructors and destructors
	GameObject::GameObject() {
		m_name = "GameObject " + std::to_string(++gameObjCount);
		m_position = { 0,0 };
		m_rotation = { 0,0 };
	}
	GameObject::GameObject(std::string name, sf::Vector2f position, sf::Vector2f rotation) {
		++gameObjCount;
		m_name = name;
		m_position = position;
		m_rotation = rotation;
	}

	GameObject::~GameObject() {
		gameObjCount--;
	}

	void GameObject::Start() {
		m_id = gameObjCount;
		std::cout << "Im created. ID: " << m_id << std::endl;
	}
	void GameObject::Update(float deltatime) {
		std::cout << "Hello, from gameobject# " << m_id << " update\n";
	}
	void GameObject::Render(sf::RenderWindow& window) {

		//sf::CircleShape circle(25);
		//circle.setFillColor(sf::Color::Red);
		//circle.setPosition(m_position);
		//window.draw(circle);
	}
}