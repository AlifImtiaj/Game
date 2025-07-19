#include <gameObject.h>

namespace GameEngine {
	GameObject::GameObject() {
		m_name = "GameObject " + std::to_string(++gameObjCount);
		m_position = { 0,0 };
		m_rotation = { 0,0 };
	}
	GameObject::GameObject(std::string name, sf::Vector2f position, sf::Vector2f rotation) {
		m_name = name;
		m_position = position;
		m_rotation = rotation;
	}
}