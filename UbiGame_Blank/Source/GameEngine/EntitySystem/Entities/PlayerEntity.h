#pragma once

#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

#include <SFML/System/Vector2.hpp>
namespace GameEngine {
	class PlayerEntity : public Entity
	{
	public:
		PlayerEntity();
		virtual ~PlayerEntity();

		virtual void Update() override;

		virtual void OnCollide() override; 


		int removeLife(); 
		bool isAlive(); 
	private:

		GameEngine::SpriteRenderComponent * m_render; 
		GameEngine::PlayerMovementComponent* m_movement;
		GameEngine::CollidableComponent* m_physicsCollider;
		void CreateGameOver(); 
		int speed; 
		int life; 

	};
}

