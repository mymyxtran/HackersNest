#pragma once

#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h"

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
	private:

		//GameEngine::RenderComponent* m_render = AddComponent<GameEngine::RenderComponent>();
		//GameEngine::PlayerMovementComponent* m_movement = AddComponent<GameEngine::PlayerMovementComponent>();
		//GameEngine::CollidableComponent* m_physicsCollider = AddComponent<GameEngine::CollidablePhysicsComponent>();

		GameEngine::RenderComponent* m_render; 
		GameEngine::PlayerMovementComponent* m_movement;
		GameEngine::CollidableComponent* m_physicsCollider;
		int speed; 
		int life; 

	};
}

