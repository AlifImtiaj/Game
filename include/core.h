// core.h

#pragma once
#include <iostream>
#include <optional>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>


namespace GameEngine {
	class GameObject;

	class Engine {
	private:
		sf::Clock m_gameClock;
		sf::RenderWindow *m_window = nullptr;

		bool bRunning = true; // for game loop
		bool bPaused = false;

		sf::Vector2u m_resolution[2] = { {640,480}, {1280,720} };

		std::vector<std::shared_ptr<GameObject>> m_objects;

	public:
		void Init(sf::RenderWindow& window);
		void AddObject(std::shared_ptr<GameObject> obj);

		float deltatime;

	private:
		void Update();
		void HandleEvents();
		void Render();
	};
}

