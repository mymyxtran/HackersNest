#include "PlayerMovementComponent.h"

//#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/GameBoard.h"

//#include <SFML/System/Vector2.hpp>

using namespace GameEngine;

PlayerMovementComponent::PlayerMovementComponent()
{
	speed = 30; 
}


PlayerMovementComponent::~PlayerMovementComponent()
{

}


void PlayerMovementComponent::Update()
{
	Component::Update();
	float dt = GameEngineMain::GetTimeDelta();
	sf::Vector2f velocity(0.0f, 0.0f);
	sf::Vector2f displacement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		velocity.x -= speed * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		velocity.x += speed * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		velocity.y += speed * dt;
		displacement.y += speed * dt; 
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		velocity.y -= speed * dt;
		displacement.y -= speed * dt; 
	}
	GetEntity()->SetVel(GetEntity()->GetVel() + sf::Vector2f(velocity.x, velocity.y));
	sf::Vector2f position = GetEntity()->GetPos(); 
	velocity = GetEntity()->GetVel();
	velocity.y += std::sqrt(std::abs(position.x - 250.0f)) / 3000;
	velocity.x -= std::sqrt(std::abs(position.x - 250.0f)) / 3000;
	displacement.y += velocity.y * dt;
	displacement.x += velocity.x * dt; 
	GetEntity()->SetPos(GetEntity()->GetPos() + displacement); 
}
