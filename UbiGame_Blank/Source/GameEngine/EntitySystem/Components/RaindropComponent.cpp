#include "RaindropComponent.h"

//#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/GameBoard.h"

//#include <SFML/System/Vector2.hpp>

using namespace GameEngine;

RaindropComponent::RaindropComponent()
{

}


RaindropComponent::~RaindropComponent()
{

}


void RaindropComponent::Update()
{
	Component::Update();
	float dt = GameEngineMain::GetTimeDelta();
	int amount = 10; 
	sf::Vector2f displacement(0.0f, 0.0f); 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		displacement.x -= amount * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		displacement.x += amount * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		displacement.y -= amount * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		displacement.y += amount * dt;
	}
	GetEntity()->SetPos(GetEntity()->GetPos() + displacement); 
}
