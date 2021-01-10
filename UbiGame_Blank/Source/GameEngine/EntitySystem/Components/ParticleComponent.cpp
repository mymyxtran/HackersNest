#include "ParticleComponent.h"



using namespace GameEngine;

ParticleComponent::ParticleComponent()
	: m_lifeTimer(2.f)
{

}


ParticleComponent::~ParticleComponent()
{

}


void ParticleComponent::OnAddToWorld()
{
	Component::OnAddToWorld();
}


void ParticleComponent::OnRemoveFromWorld()
{
	Component::OnAddToWorld();
}


void ParticleComponent::Update()
{
	// This is just an example of particle emitting snippet
	sf::Vector2f emitPos = GetEntity()->GetPos();

	// Increment x and y

	float delta_y = 0.15;
	float delta_x = 0;
	sf::Vector2f delta(0, delta_y);
	this->GetEntity()->SetPos(emitPos + delta);

	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();

	m_lifeTimer -= dt;

	if (m_lifeTimer <= 0.f)
	{
		GameEngine::GameEngineMain::GetInstance()->RemoveEntity(GetEntity());
	}
}