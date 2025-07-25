// player.h

#pragma once

#include <iostream>

#include <gameObject.h>
#include <SFML/Graphics.hpp>

namespace GameEngine {
	class Player : public GameObject {
	private:
		float m_radius = 100;
		float m_speed;
		sf::Color m_color;
		bool bIsActive = true;
		

	public:
		Player(const std::string& name, float speed = 0.0f, sf::Vector2f position = { 0,0 }, sf::Vector2f rotation = { 0,0 })
			: GameObject(name, position, rotation), m_speed(speed) {}

		Player(const std::string& name, sf::Vector2f position = { 0,0 }, sf::Vector2f rotation = { 0,0 }, 
			float speed = 0.0f,
			sf::Color color = sf::Color::Red)
			: GameObject(name, position, rotation), m_speed(speed), m_color(color) {
		}


		Player() : GameObject(), m_speed(0), m_radius(0) {}


	public:
		// setters
		void SetRadius(float radius) { m_radius = radius; }
		void SetSpeed(float speed) { m_speed = speed; }
		void SetColor(sf::Color color) { m_color = color; }
		void SetActive(bool isActive) { bIsActive = isActive; }


		// Getters
		float GetRadius() const { return m_radius; }
		float GetSpeed() const { return m_speed; }
		sf::Color GetColor() const { return m_color; }
		bool GetActive() const { return bIsActive; }


	
	// user defined
	private:
		void HandleInput(float& deltatime);


	// inherited functions
	protected:
		void Start() override;
		void Update(float& deltatime) override;
		void Render(sf::RenderWindow& window) override;
	};
}