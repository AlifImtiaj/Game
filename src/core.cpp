#include <core.h>
#include "gameObject.h"

namespace GameEngine {
	template<typename T>
	std::string LogVector(sf::Vector2<T> vector2) {
		return "X: " + std::to_string(vector2.x) + ", Y: " + std::to_string(vector2.y);
	}

	void Engine::Init(sf::RenderWindow& window) {
		m_window = &window;
		std::cout << LogVector(m_window->getPosition()) << std::endl;
		Update();
		m_window->close();
	}


	void Engine::Update() {

		while (bRunning) { 
			// handle event first, then game logic, then render everything
			HandleEvents();

			// do anything you want here
			//if (!bPaused) {


			deltatime = m_gameClock.restart().asSeconds();

			//}
			//else {
			//	m_gameClock.restart();
			//}

			// We want to render everything after whole game logic is finished
			m_window->clear();
			Render();
			m_window->display();
			
		}
	}

	bool highRes = false;
	void Engine::HandleEvents() {
		while (const std::optional event = m_window->pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				bRunning = false;
				std::cout << "closed " << bRunning;
			}

			else if (const auto* keycode = event->getIf<sf::Event::KeyPressed>()) {

				if (keycode->scancode == sf::Keyboard::Scancode::Escape) {
					bRunning = false;
					m_window->close();
				}

				if (keycode->scancode == sf::Keyboard::Scancode::F11) {
					highRes = !highRes;
					m_window->close();
					m_window->create(sf::VideoMode(m_resolution[highRes]), "Game", sf::Style::Close);
					m_window->setFramerateLimit(60);
				}

			}

			else if (event->is<sf::Event::FocusLost>()) {
				bPaused = true;  // Pause game when window loses focus
				std::cout << "Paused (Lost Focus)\n";
			}

			else if (event->is<sf::Event::FocusGained>()) {
				bPaused = false; // Unpause when window gains focus
				std::cout << "Unpaused (Gained Focus)\n";
			}
		}
	}

	//float pos = 0;
	void Engine::Render() {
		/*float speed = 200;
		float radius = 25;
		sf::Vector2 windowSize = m_window->getSize();

		pos += deltaTime * speed;


		if (pos >= windowSize.x - radius * 2)
			pos = 0;

		sf::CircleShape cs;
		cs.setRadius(radius);
		cs.setFillColor(sf::Color::White);

		std::cout << "Position: " << LogVector(sf::Vector2f({pos, 0})) << std::endl;
		cs.setPosition(sf::Vector2f({ pos, 0 }));
		m_window->draw(cs);*/
	}


}
