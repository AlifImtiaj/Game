// core.h

#pragma once
#include <iostream>
#include <optional>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


namespace GameEngine {
	class GameObject;

	class Engine {
	private:
		sf::Clock m_gameClock;
		sf::RenderWindow *m_window = nullptr;

		bool bRunning = true; // for game loop
		bool bPaused = false;

		std::vector<GameObject*> m_objects;

	public:
		void Init(sf::RenderWindow& window);
		//void AddObject(std::shared_ptr<GameObject> obj);
		void AddObject(GameObject* obj);



	private:
		void Update();
		void HandleEvents();
		void Render();
		float deltatime = 0.0f;
	};
}

