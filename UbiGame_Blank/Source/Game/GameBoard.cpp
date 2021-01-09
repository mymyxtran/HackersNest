#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"


using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity(); 
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	m_player->SetPos(sf::Vector2f(100.0f, 100.0f));
	m_player->SetSize(sf::Vector2f(10.0f, 10.0f));

	GameEngine::RenderComponent* render = m_player->AddComponent<GameEngine::RenderComponent>();
	GameEngine::PlayerMovementComponent* movement = m_player->AddComponent<GameEngine::PlayerMovementComponent>(); 
}
