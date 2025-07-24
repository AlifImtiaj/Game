// button.cpp

#include <button.h>

namespace GameEngine {
	template<typename T>
	static std::string LogVector(sf::Vector2<T> vector2) {
		return "X: " + std::to_string(vector2.x) + ", Y: " + std::to_string(vector2.y);
	}



	Button::Button(std::string message, sf::Vector2f position, sf::Vector2f size) : GameObject(message, position) {
		//sf::Font font("resources/fonts/PixeloidMono.ttf";
		m_position = position;
		m_size = size;

		m_text.setFont(m_font);
		m_text.setString(message);
		m_text.setPosition(m_position);
		m_text.setCharacterSize(30);
		m_text.setFillColor(sf::Color::Black);


	}
	Button::~Button() {
	}
	void Button::SetFont(const std::filesystem::path& filename) {
		if (!m_font.openFromFile(filename)) {
			std::cout << "Error loading font...\n";
		}
	}
	void Button::SetText(const std::string& text) {
		m_text.setString(text);
	}
	// derived functions
	void Button::Start() {
	}
	void Button::Update(float& deltatime) {
	}

	void Button::Render(sf::RenderWindow& window) {
		sf::FloatRect fr(m_position, m_size);

		sf::RectangleShape rect(m_size);
		rect.setFillColor(m_normalColor);
		rect.setOutlineColor(sf::Color::Red);
		rect.setOutlineThickness(5.0f);
		rect.setPosition(m_position);
		
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);


		if (OnHover(mousePosition)) {
			if (OnClick()) {
				rect.setFillColor(m_onClickColor);
			}
			else rect.setFillColor(m_hoverColor);
		}


		window.draw(rect);
		window.draw(m_text);
	}

	// Button functionality
	bool Button::OnHover(sf::Vector2i& mousePositionRelativeToWindow) {
		float upperXLimit = m_position.x + m_size.x;
		float lowerXLimit = m_position.x;

		float upperYLimit = m_position.y + m_size.y;
		float lowerYLimit = m_position.y;

		if (mousePositionRelativeToWindow.x > lowerXLimit && 
			mousePositionRelativeToWindow.x < upperXLimit) {
			if (mousePositionRelativeToWindow.y > lowerYLimit &&
				mousePositionRelativeToWindow.y < upperYLimit) {
				return true;
			}
		}
		// calls on exit when mouse leave the area
		// idk what to do, just created
		return false;
	}

	bool Button::OnClick() {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			std::cout << "Button pressed " << this->objId << std::endl;
			return true;
		}
		return false;
	}

	bool Button::OnExit() {
		return false;
	}



}