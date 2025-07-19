#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

namespace GameEngine {
	class GameObject {
	private:
		std::string m_name;
		sf::Vector2f m_position;
		sf::Vector2f m_rotation;

		static int gameObjCount;
		
	public:
		GameObject();
		GameObject(std::string name, sf::Vector2f position = { 0,0 }, sf::Vector2f rotation = { 0,0 });

		virtual void Start();
		virtual void Update(float deltatime);
		virtual void Render();

		void Destroy();

	};
}