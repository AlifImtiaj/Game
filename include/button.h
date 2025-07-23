#pragma once
#include <iostream>

#include <gameObject.h>
#include <core.h>

namespace GameEngine {
	class Engine;
	class Button: public GameObject {
		friend class Engine;
	public:


	public:
		void OnHover();
		void OnClick();
		void OnExit();

	public:
		// override functions;

		void Start();
		void Update();
		void Render();

	};
}