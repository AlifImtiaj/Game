// player.cpp

#include <player.h>

namespace GameEngine {

	template<typename T>
	std::string LogVector(sf::Vector2<T> vector2) {
		return "X: " + std::to_string(vector2.x) + ", Y: " + std::to_string(vector2.y);
	}


	void Player::Start() {
		// something to do in the start
	}


	void Player::HandleInput(float& deltatime) {
		if (!bIsActive) return;
		sf::Vector2f moveDirection(0, 0);

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
	}

	void Player::Update(float& deltatime) {
		HandleInput(deltatime);

	}

	void Player::Render(sf::RenderWindow& window) {

		if (!bIsActive) return;

		// it offsets the sprite to positive X and Y to the radius
		sf::Vector2f position = GetPosition();
		position.x -= m_radius;
		position.y -= m_radius;

		sf::CircleShape circle(m_radius);
		circle.setFillColor(m_color);
		circle.setPosition(position);
		window.draw(circle);
	}
}