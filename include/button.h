// button.h

#pragma once
#include <iostream>

#include <gameObject.h>
#include <core.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace GameEngine {
	class Button: public GameObject {

	public:
		Button(std::string text, sf::Vector2f position = { 0,0 }, sf::Vector2f size = { 0,0 });
		virtual ~Button();

	private:
		sf::Vector2f m_position;
		sf::Vector2f m_size;

		sf::Font m_font = sf::Font("resources/fonts/PixeloidMono.ttf");
		sf::Text m_text = sf::Text(m_font, "TEST", 20);

		sf::Color m_normalColor = sf::Color(100, 100, 100, 255);
		sf::Color m_hoverColor = sf::Color(125, 125, 125, 255);
		sf::Color m_onClickColor = sf::Color(80, 80, 80, 255);

	public:

		void SetFont(const std::filesystem::path& filename);
		void SetText(const std::string& text);

	public:
		// override functions;

		void Start() override;
		void Update(float& deltatime) override;
		void Render(sf::RenderWindow& window) override;


	public:
		virtual bool OnHover(sf::Vector2i& mousePositionRelativeToWindow);
		virtual bool OnClick();
		virtual bool OnExit();

	};
}