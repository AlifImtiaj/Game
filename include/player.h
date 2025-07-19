// player.h

#pragma once

#include <iostream>

#include <gameObject.h>
#include <SFML/Graphics.hpp>

namespace GameEngine {
	class Player : public GameObject {
	private:
		void HandleInput(float deltatime);
		sf::Vector2i m_mousePos;
		float m_radius = 25;

	public:
		Player(std::string name, sf::Vector2f position, sf::Vector2f rotation = {0,0})
			: GameObject(name, position, rotation) {}
		Player() : GameObject() {}


	public:
		void Start() override;
		void Update(float deltatime) override;
		void Render(sf::RenderWindow& window) override;

		bool bKeyboardControl = true;
	};
}