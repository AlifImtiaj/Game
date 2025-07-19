#pragma once
#include <iostream>
#include <memory>
#include <optional>
#include <thread>

#include <SFML/Graphics.hpp>

namespace GameEngine {
	class Engine {
	private:
		sf::Clock m_gameClock;
		sf::RenderWindow *m_window = nullptr;

		bool bRunning = true; // for game loop
		bool bPaused = false;

		sf::Vector2u m_resolution[2] = { {640,480}, {1280,720} };


	public:
		void Init(sf::RenderWindow& window);
		float deltatime;

	private:
		void Update();
		void HandleEvents();
		void Render();

	};
}

