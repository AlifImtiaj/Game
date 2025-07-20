// player.h

#pragma once

#include <iostream>

#include <gameObject.h>
#include <SFML/Graphics.hpp>

namespace GameEngine {
	class Player : public GameObject {
	private:
		void HandleInput(float deltatime);
		//sf::Vector2i m_mousePos;
		float m_radius = 25;
		float m_speed;
		sf::Color m_color;

	public:
		Player(std::string name, float speed = 0.0f, sf::Vector2f position = { 0,0 }, sf::Vector2f rotation = { 0,0 })
			: GameObject(name, position, rotation), m_speed(speed) {}

		Player() : GameObject(), m_speed(0), m_radius(0) {}


	public:
		float GetRadius() const { return m_radius; }
		void SetRadius(float radius) { m_radius = radius; }
		void SetColor(sf::Color color) { m_color = color; }
		sf::Color GetColor() { return m_color; }

	public:
		void Start() override;
		void Update(float deltatime) override;
		void Render(sf::RenderWindow& window) override;

		//bool bKeyboardControl = true;
	};
}