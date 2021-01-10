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
	float velocityLossX = 0.0f;
	float velocityLossY = 0.0f; 
	if (velocity.x < 0) {
		velocityLossX = -5.0f;
	}else {
		velocityLossX = 5.0f;
	}
	if (velocity.y < 0) {
		velocityLossY = -5.0f;
	}
	else {
		velocityLossY = 5.0f;
	}
	SetVel(sf::Vector2f(-velocity.x+velocityLossX, -velocity.y+velocityLossY));
	m_movement->setSpeed(std::max((int)m_movement->getSpeed() - 5, 0)); 
}

int PlayerEntity::removeLife() {
	if (life == 0) {
		printf("You hit too many rocks"); 
		m_movement->setSpeed(0); 
		SetVel(sf::Vector2f(0, 0)); 
		// GAME OVER IMAGE
	}
	life--;
	return life; 
}

void PlayerEntity::Update()
{
	if (life == 0) {
		float dt = GameEngineMain::GetTimeDelta();
		SetPos(GetPos() + sf::Vector2f(0, 50*dt));
	}
	Entity::Update();
	float dt = GameEngineMain::GetTimeDelta();
}
