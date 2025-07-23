// core.cpp

#include <core.h>
#include <gameObject.h>

namespace GameEngine {

	sf::Vector2f screenSize;
	void Engine::Init(sf::RenderWindow& window) {
		m_window = &window;
		screenSize = static_cast<sf::Vector2f>(m_window->getSize());
		//std::cout << LogVector(m_window->getPosition()) << std::endl;
		Update();
		m_window->close();
	}

	void Engine::AddObject(std::shared_ptr<GameObject> obj) {
		obj->Start();
		m_objects.push_back(std::move(obj));
	}


	void Engine::Update() {

		while (bRunning) {
			// handle event first, then game logic, then render everything
			HandleEvents();
			if (!bRunning) return;

			// do anything you want here
			deltatime = m_gameClock.restart().asSeconds();

			for (auto& objects : m_objects) {
				objects->Update(deltatime);
			}

			m_window->clear();
			Render();
			m_window->display();
		}
	}

	// unoptimized Event handling
	void Engine::HandleEvents() {
		while (const std::optional event = m_window->pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				bRunning = false;
				std::cout << "closed " << bRunning;
			}
			else if (const auto* keycode = event->getIf<sf::Event::KeyPressed>()) {
				if (keycode->scancode == sf::Keyboard::Scancode::Escape) {
					bRunning = false;
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


	void Engine::Render() {
		for (auto& objects : m_objects) {
			objects->Render(*m_window);
		}
	}
}
