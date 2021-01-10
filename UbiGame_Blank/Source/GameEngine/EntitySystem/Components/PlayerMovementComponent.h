#pragma once

#include "GameEngine/EntitySystem/Component.h"

#include <SFML/System/Vector2.hpp>
namespace GameEngine
{
	// class CollidableComponent;

	class PlayerMovementComponent : public Component
	{
	public:
		PlayerMovementComponent();
		virtual ~PlayerMovementComponent();

		virtual void Update() override;


		int getSpeed() { return speed; };
		void setSpeed(int newSpeed) { speed = newSpeed; };

	private:
		float timer; 
		int speed = 50; 
		sf::Vector2f acceleration = sf::Vector2f(0.0f, 0.0f); 
		sf::Vector2f origin = sf::Vector2f(250.0f, 250.0f); 
		const int maxSpeed = 500; 
		bool isJumping = false; 
	};
}


