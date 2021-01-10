#include "PlayerMovementComponent.h"

//#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/GameBoard.h"

//#include <SFML/System/Vector2.hpp>

using namespace GameEngine;

PlayerMovementComponent::PlayerMovementComponent()
{
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
		if (velocity.x - speed * dt > -maxSpeed) {
			velocity.x -= speed * dt;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (velocity.x + speed * dt < maxSpeed) {
			velocity.x += speed * dt;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		//if (velocity.y + speed * dt < maxSpeed) {
			displacement.y += speed * dt ;
		//}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		//if (velocity.y - speed * dt > -maxSpeed) {
			displacement.y -= speed * dt;
		//}
	}
	sf::Vector2f position = GetEntity()->GetPos();
	velocity.y = std::sqrt(std::abs(position.x - 250.0f)) / 3000;
	velocity.x -= std::sqrt(std::abs(position.x - 250.0f))/3000; 
	GetEntity()->SetVel(sf::Vector2f(GetEntity()->GetVel().x + velocity.x, velocity.y));
	velocity = GetEntity()->GetVel();
	displacement.y += velocity.y;
	displacement.x = velocity.x * dt; 
	GetEntity()->SetPos(GetEntity()->GetPos() + displacement); 
}
