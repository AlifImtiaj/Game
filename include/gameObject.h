// gameObject.h

#pragma once

#include <iostream>
#include <vector>

#include <core.h>
#include <SFML/Graphics.hpp>

namespace GameEngine {
	class Engine;
	class GameObject {
	private:
		friend class Engine;
		std::string m_name;
		sf::Vector2f m_position;
		sf::Vector2f m_rotation;
		sf::Vector2f m_moveDirection = {0,0};
		
	public:
		static int gameObjCount;
		
		GameObject();
		GameObject(std::string name, sf::Vector2f position = { 0,0 }, sf::Vector2f rotation = { 0,0 });
		virtual ~GameObject();

	public:
		int objId = 0; // debug purpose
		// getter setter
		void SetName(std::string name) { m_name = name; }
		void SetPosition(sf::Vector2f position) { m_position = position; }
		void SetRotation(sf::Vector2f rotation) { m_rotation = rotation; }
		void SetMoveDirection(sf::Vector2f moveDirection) { m_moveDirection = moveDirection; }

		sf::Vector2f GetPosition() const { return m_position; }
		sf::Vector2f GetRotation() const { return m_rotation; }
		std::string GetName() const { return m_name; }
		sf::Vector2f GetMoveDirection() const { return m_moveDirection; }

	protected:
		virtual void Start() = 0;
		virtual void Update(float& deltatime) = 0;
		virtual void Render(sf::RenderWindow& window) = 0;
	};
}