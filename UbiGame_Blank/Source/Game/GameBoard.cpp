#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"


using namespace Game;

GameBoard::GameBoard()
{
	CreateBackground();
	CreatePlayer();
	CreateGround(sf::Vector2f(300.0f, 602.0f), sf::Vector2f(600.0f, 4.0f));
	CreateGround(sf::Vector2f(-2.f, 300.f), sf::Vector2f(4.0f, 600.0f));
	CreateGround(sf::Vector2f(602.f, 350.f), sf::Vector2f(4.0f, 600.0f));

	std::srand(std::time(NULL));
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	const sf::Time Time = sf::seconds(2.0f);
	if (m_player->isAlive()) {
		if (Timer.getElapsedTime() > Time) {
			// Bounds for raindrops for left and right most
			float min_x = 32.0f;
			float max_x = 460.0f;

			float x = (float)(rand() % (int)((max_x + 1) - min_x)) + min_x;
			float y = 0;

			CreateRaindrop(sf::Vector2f(x, y));
			Timer.restart();
		}
	}
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::PlayerEntity(); 
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

}

void GameBoard::CreateGround(sf::Vector2f pos, sf::Vector2f size)
{
	GameEngine::Entity* ground = new GameEngine::Entity(); 
	GameEngine::GameEngineMain::GetInstance()->AddEntity(ground);
	ground->SetPos(pos);
	ground->SetSize(size);
	GameEngine::RenderComponent* render = ground->AddComponent<GameEngine::RenderComponent>(); 
	GameEngine::CollidableComponent* collision = ground->AddComponent<GameEngine::CollidablePhysicsComponent>(); 
}

void GameBoard::CreateBackground()
{
	GameEngine::Entity* backgroundEntity = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(backgroundEntity);

	backgroundEntity->SetPos(sf::Vector2f(300.f, 300.f));
	backgroundEntity->SetSize(sf::Vector2f(600.f, 600.f));

	GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>(backgroundEntity->AddComponent<GameEngine::SpriteRenderComponent>());
	render->SetFillColor(sf::Color::Transparent);

	render->SetTexture(GameEngine::eTexture::Background);

}

void GameBoard::CreateRaindrop(sf::Vector2<float> startPos)
{
	GameEngine::Entity* m_raindrop = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_raindrop);
	m_raindrop->SetPos(startPos);
	m_raindrop->SetSize(sf::Vector2f(40.0f, 40.0f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>(m_raindrop->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Rain);

	// Animate raindrop falling!
	GameEngine::RaindropComponent* particle = static_cast<GameEngine::RaindropComponent*>(m_raindrop->AddComponent<GameEngine::RaindropComponent>());
	GameEngine::CollidablePhysicsComponent* physics = m_raindrop->AddComponent<GameEngine::CollidablePhysicsComponent>();
	// Set the lifetime
	particle->SetLifeTime(20);

}
