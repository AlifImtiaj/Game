#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

namespace GameEngine {
	class GameObject : private Engine {
	private:
		std::string m_name;
		sf::Vector2f m_position;
		sf::Vector2f m_rotation;
		
		
		
	public:
		//static int gameObjCount;
		
		GameObject();
		GameObject(std::string name, sf::Vector2f position = { 0,0 }, sf::Vector2f rotation = { 0,0 });

	public:
		void Destroy();
		virtual void Render();

	public:
		// getter setter
		void SetName(std::string name) { m_name = name; }
		void SetPosition(sf::Vector2f position) { m_position = position; }
		void SetRotation(sf::Vector2f rotation) { m_rotation = rotation; }

		sf::Vector2f GetPosition() const { return m_position; }
		sf::Vector2f GetRotation() const { return m_rotation; }
		std::string GetName() const { return m_name; }

	public:
		virtual void Start();
		virtual void Update(float deltatime);


	};
}