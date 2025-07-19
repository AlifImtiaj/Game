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

		float speed = 100;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) moveDirection.y = -1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) moveDirection.y = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) moveDirection.x = -1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) moveDirection.x = 1;

		if (moveDirection.x != 0 || moveDirection.y != 0)
		{
			//float length = moveDirection.length();
			moveDirection /= moveDirection.length();
		}

		sf::Vector2f deltaMove = moveDirection * speed * deltatime;
		SetPosition(GetPosition() + deltaMove);
		
	}

	void Player::Update(float deltatime) {
		HandleInput(deltatime);
		std::cout << "Position : " << LogVector(GetPosition()) << std::endl;
	}



	void Player::Render(sf::RenderWindow& window) {
		sf::CircleShape circle(25);
		circle.setFillColor(sf::Color::Red);
		circle.setPosition(GetPosition());
		window.draw(circle);
	}
}