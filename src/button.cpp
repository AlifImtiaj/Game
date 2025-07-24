// button.cpp

#include <button.h>

namespace GameEngine {


	Button::Button(std::string message, sf::Vector2f position, sf::Vector2f size) {
		//sf::Font font("resources/fonts/PixeloidMono.ttf");
		m_text.setString(message);
		m_text.setPosition(position);

		m_position = position;
		m_size = size;

	}
	Button::~Button() {
	}
	// derived functions
	void Button::Start() {
	}
	void Button::Update(float& deltatime) {
	}
	void Button::Render(sf::RenderWindow& window) {
		sf::RectangleShape rect(m_size);
		rect.setFillColor(sf::Color::Yellow);
		rect.setOutlineColor(sf::Color::Red);
		rect.setOutlineThickness(5.0f);
		rect.setPosition(m_position);

		window.draw(m_text);
		window.draw(rect);
	}

	void Button::OnHover() {
		
	}

	void Button::OnClick() {
	}

	void Button::OnExit() {
	}



}