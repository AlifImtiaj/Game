// gameObject.cpp

#include <gameObject.h>


namespace GameEngine {
	template<typename T>
	static std::string LogVector(sf::Vector2<T> vector2) {
		return "X: " + std::to_string(vector2.x) + ", Y: " + std::to_string(vector2.y);
	}

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
	}
	void GameObject::Update(float& deltatime) {
	}
	void GameObject::Render(sf::RenderWindow& window) {
	}
}