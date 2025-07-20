// player.cpp

#include <player.h>

namespace GameEngine {

	template<typename T>
	std::string LogVector(sf::Vector2<T> vector2) {
		return "X: " + std::to_string(vector2.x) + ", Y: " + std::to_string(vector2.y);
	}


	void Player::Start() {
		// do rendering by default
	}

	void Player::HandleInput(float deltatime) {
		sf::Vector2f moveDirection(0,0);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) moveDirection.y = -1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) moveDirection.y = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) moveDirection.x = -1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) moveDirection.x = 1;



		if (moveDirection.x != 0 || moveDirection.y != 0)
		{
			//moveDirection = moveDirection.normalized();
			//float length = moveDirection.length();
			moveDirection /= moveDirection.length();
		}

		sf::Vector2f deltaMove = moveDirection * m_speed * deltatime;
		//if (bKeyboardControl)

		SetPosition(GetPosition() + deltaMove);
		//else
		//	SetPosition(static_cast<sf::Vector2f>(m_mousePos));
		
	}

	void Player::Update(float deltatime) {
		HandleInput(deltatime);

		if (GetPosition().x > 512) {
			m_color = sf::Color::Red;
		}
		else m_color = sf::Color::White;

		//std::cout << "Position : " << LogVector({1,2}) << std::endl;
		//std::cout << "Mouse position: " << LogVector(m_mousePos) << std::endl;
	}



	void Player::Render(sf::RenderWindow& window) {
		//m_mousePos = sf::Mouse::getPosition(window);
		//m_mousePos.x -= m_radius;
		//m_mousePos.y -= m_radius;


		// it offsets the sprite to positive X and Y to the radius
		sf::Vector2f position = GetPosition();
		position.x -= m_radius;
		position.y -= m_radius;

		sf::CircleShape circle(m_radius);
		circle.setPointCount(4);
		circle.setFillColor(m_color);
		circle.setPosition(position);
		window.draw(circle);
	}
}