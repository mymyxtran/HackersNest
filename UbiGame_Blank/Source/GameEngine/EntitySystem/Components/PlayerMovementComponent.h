#pragma once

#include "GameEngine/EntitySystem/Component.h"

namespace GameEngine
{
	// class CollidableComponent;

	class PlayerMovementComponent : public Component
	{
	public:
		PlayerMovementComponent();
		virtual ~PlayerMovementComponent();

		virtual void Update() override;

	private:
		int timer; 
	};
}


