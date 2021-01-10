#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"


using namespace Game;

GameBoard::GameBoard()
{
	CreateBackground();
	CreatePlayer();
	std::srand(std::time(NULL));
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	const sf::Time Time = sf::seconds(2.0f);

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

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::PlayerEntity(); 
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	m_player->SetPos(sf::Vector2f(250.0f, 250.0f));
	m_player->SetSize(sf::Vector2f(25.0f, 25.0f));

}

void GameBoard::CreateGround()
{
	m_ground = new GameEngine::Entity(); 
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_ground); 
	m_ground->SetPos(sf::Vector2f(250.0f, 480.0f));
	m_ground->SetSize(sf::Vector2f(500.0f, 10.0f)); 
	GameEngine::RenderComponent* render = m_ground->AddComponent<GameEngine::RenderComponent>(); 
	GameEngine::CollidableComponent* collision = m_ground->AddComponent<GameEngine::CollidablePhysicsComponent>(); 
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
	raindrop = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(raindrop);
	raindrop->SetPos(startPos);
	raindrop->SetSize(sf::Vector2f(40.0f, 40.0f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>(raindrop->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Rain);

	// Animate raindrop falling!
	GameEngine::RaindropComponent* particle = static_cast<GameEngine::RaindropComponent*>(raindrop->AddComponent<GameEngine::RaindropComponent>());
	GameEngine::CollidablePhysicsComponent* physics = raindrop->AddComponent<GameEngine::CollidablePhysicsComponent>(); 
// Set the lifetime
particle->SetLifeTime(9);

}