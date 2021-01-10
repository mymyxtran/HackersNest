#include "PlayerEntity.h"

#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/GameBoard.h"

//#include <SFML/System/Vector2.hpp>


using namespace GameEngine;

PlayerEntity::PlayerEntity()
{
	m_render = AddComponent<GameEngine::RenderComponent>();
	m_movement = AddComponent<GameEngine::PlayerMovementComponent>();
	m_physicsCollider = AddComponent<GameEngine::CollidablePhysicsComponent>();
	life = 3; 
	speed = 80;
}


PlayerEntity::~PlayerEntity()
{

}

void PlayerEntity::OnCollide()
{
	removeLife(); 
	printf("LIFE"); 
	sf::Vector2f velocity = GetVel();
	SetVel(sf::Vector2f(-velocity.x+5.0f, -velocity.y+5.0f));
	m_movement->setSpeed(std::max((int)m_movement->getSpeed() - 10, 0)); 
}

int PlayerEntity::removeLife() {
	//life--; 
	if (life == 0) {
		printf("Game"); 
	}
	return life; 
}

void PlayerEntity::Update()
{
	Entity::Update();
	float dt = GameEngineMain::GetTimeDelta();
}
