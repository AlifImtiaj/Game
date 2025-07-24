// button.h

#pragma once
#include <iostream>

#include <gameObject.h>
#include <core.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace GameEngine {
	class Engine;
	class Button: public GameObject {
		friend class Engine;

	public:
		Button(std::string text, sf::Vector2f position = { 0,0 }, sf::Vector2f size = { 0,0 });
		virtual ~Button();

	private:
		sf::Vector2f m_position;
		sf::Vector2f m_size;

		sf::Font m_font = sf::Font("resources/fonts/PixeloidMono.ttf");
		sf::Text m_text = sf::Text(m_font, "", 20);

	public:

	public:
		// override functions;

		void Start() override;
		void Update(float& deltatime) override;
		void Render(sf::RenderWindow& window) override;


	public:
		void OnHover();
		void OnClick();
		void OnExit();

	};
}