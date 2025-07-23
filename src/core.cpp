// core.cpp

#include <core.h>
#include <gameObject.h>

namespace GameEngine {

	void Engine::Init(sf::RenderWindow& window) {
		m_window = &window;
		//std::cout << LogVector(m_window->getPosition()) << std::endl;
		Update();
		m_window->close();
	}

	//void Engine::AddObject(GameObject* obj) {
		//obj->Start();
		//m_objects.push_back(std::move(obj));
	//}

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
		}
	}


	void Engine::Render() {
		for (auto& objects : m_objects) {
			objects->Render(*m_window);
		}
	}
}
