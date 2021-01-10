#include "RaindropComponent.h"



using namespace GameEngine;

RaindropComponent::RaindropComponent()
	: m_lifeTimer(2.f)
{

}


RaindropComponent::~RaindropComponent()
{

}


void RaindropComponent::OnAddToWorld()
{
	Component::OnAddToWorld();
}


void RaindropComponent::OnRemoveFromWorld()
{
	Component::OnAddToWorld();
}


void RaindropComponent::Update()
{
	//This is just an example of Raindrop emitting snippet
	sf::Vector2f emitPos = GetEntity()->GetPos();

	//Increment raindrop position in y position
	sf::Vector2f delta(0.0f, 0.09);

	this->GetEntity()->SetPos(emitPos + delta);
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();

	m_lifeTimer -= dt;

	if (m_lifeTimer <= 0.f)
	{
		GameEngine::GameEngineMain::GetInstance()->RemoveEntity(GetEntity());
	}
}