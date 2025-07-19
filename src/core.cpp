// core.cpp

#include <core.h>
#include <gameObject.h>

namespace GameEngine {
	template<typename T>
	std::string LogVector(sf::Vector2<T> vector2) {
		return "X: " + std::to_string(vector2.x) + ", Y: " + std::to_string(vector2.y);
	}

	void Engine::Init(sf::RenderWindow& window) {
		m_window = &window;
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

	

	void Engine::Render() {
		for (auto& objects : m_objects) {
			objects->Render(*m_window);
		}
	}


}
