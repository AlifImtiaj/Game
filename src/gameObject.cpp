#include <gameObject.h>

namespace GameEngine {
	//static int GameObject::gameObjCount = 0;
	GameObject::GameObject() {
		m_name = "GameObject ";
		m_position = { 0,0 };
		m_rotation = { 0,0 };
		
		m_gameObjs.push_back(*this);
	}
	GameObject::GameObject(std::string name, sf::Vector2f position, sf::Vector2f rotation) {
		m_name = name;
		m_position = position;
		m_rotation = rotation;
	}

	void GameObject::Start() {
		
	}
	void GameObject::Update(float deltatime) {
	}

	void GameObject::Destroy()
	{
	}

	void GameObject::Render() {
		sf::CircleShape circle(50.0f);
		circle.setFillColor(sf::Color::Red);
		circle.setPosition({ 50,100 });
	}
}