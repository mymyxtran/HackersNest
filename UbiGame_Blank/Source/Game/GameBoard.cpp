#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h" 
#include "GameEngine/EntitySystem/Components/ParticleComponent.h" 
#include "GameEngine/EntitySystem/Components/ParticleEmitterComponent.h" 
#include <vector>
#include <time.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>  

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace Game;

sf::Clock Timer;

//Global Variable to store all raindrops

GameBoard::GameBoard()
{
	CreatePlayer();
	std::srand( std::time(NULL) );

}

GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	const sf::Time Time   = sf::seconds(2.0f);

	if(Timer.getElapsedTime() > Time){

		// Bounds for raindrops for left and right most
		float min_x = 32.0f;
		float max_x = 460.0f;
		
		float x = (float) (rand()%(int)((max_x+1)-min_x)) + min_x;
		float y = 0;

		CreateRaindrop( sf::Vector2f(x, y) );
		Timer.restart();
	}
	
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

void GameBoard::CreateRaindrop(sf::Vector2<float> startPos)
{
	raindrop = new GameEngine::Entity(); 
	GameEngine::GameEngineMain::GetInstance()->AddEntity(raindrop);
	raindrop->SetPos(startPos);
	raindrop->SetSize(sf::Vector2f(40.0f, 40.0f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>(raindrop->AddComponent<GameEngine::SpriteRenderComponent>() );

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Rain);

	// Animate raindrop falling!
	GameEngine::RaindropComponent* particle = static_cast< GameEngine::RaindropComponent* >(raindrop->AddComponent<GameEngine::RaindropComponent>() );
	
	// Set the lifetime
	particle->SetLifeTime(9);

}

