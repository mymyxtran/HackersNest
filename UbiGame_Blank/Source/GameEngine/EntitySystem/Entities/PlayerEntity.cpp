#include "PlayerEntity.h"

#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/GameBoard.h"

//#include <SFML/System/Vector2.hpp>


using namespace GameEngine;

PlayerEntity::PlayerEntity()
{
	m_render = AddComponent<GameEngine::SpriteRenderComponent>();
	m_movement = AddComponent<GameEngine::PlayerMovementComponent>();
	m_physicsCollider = AddComponent<GameEngine::CollidablePhysicsComponent>();
	m_render->SetFillColor(sf::Color::Transparent);
	m_render->SetTexture(GameEngine::eTexture::Fish);
	SetPos(sf::Vector2f(250.0f, 250.0f));
	SetSize(sf::Vector2f(50.0f, 150.0f));
	life = 3; 
	speed = 80;
}


PlayerEntity::~PlayerEntity()
{

}

void PlayerEntity::OnCollide()
{
	removeLife(); 
	printf("Lost a life"); 
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
		CreateGameOver(); 
	}
	life--;
	return life; 
}

bool PlayerEntity::isAlive() {
	return !(life <= -1); 
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


void PlayerEntity::CreateGameOver()
{
	GameEngine::Entity* gameOverEntity = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(gameOverEntity);

	gameOverEntity->SetPos(sf::Vector2f(300.f, 300.f));
	gameOverEntity->SetSize(sf::Vector2f(600.f, 600.f));

	GameEngine::SpriteRenderComponent* render = (gameOverEntity->AddComponent<GameEngine::SpriteRenderComponent>());
	render->SetFillColor(sf::Color::Transparent);

	render->SetTexture(GameEngine::eTexture::GameOver);

}