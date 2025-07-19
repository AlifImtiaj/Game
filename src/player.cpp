// player.cpp

#include <player.h>

namespace GameEngine {
	Player::Player() {
		
	}

	void Player::Start() {
		// do rendering by default
	}

	void Player::Update(float deltatime) {

	}

	void Player::Render(sf::RenderWindow& window) {
		sf::CircleShape circle(25);
		circle.setFillColor(sf::Color::Red);
		circle.setPosition(GetPosition());
		window.draw(circle);
	}
}