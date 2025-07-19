#pragma once

#include <iostream>


#include <gameObject.h>
#include <SFML/Graphics.hpp>

namespace GameEngine {
	class Player : public GameObject {
	private:
		bool bIsActive = true;


	public:
		Player(std::string name, sf::Vector2f position, sf::Vector2f rotation)
			: GameObject(name, position, rotation) {}
		Player();


	public:
		void Start();
		void Update(float deltatime);
		void Render();
	};
}