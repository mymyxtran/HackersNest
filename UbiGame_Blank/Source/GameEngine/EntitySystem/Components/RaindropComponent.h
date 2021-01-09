#pragma once

#include "GameEngine/EntitySystem/Component.h"

namespace GameEngine
{
	// class CollidableComponent;

	class RaindropComponent : public Component
	{
	public:
		RaindropComponent();
		virtual ~RaindropComponent();

		virtual void Update() override;

	private:
		int timer; 
	};
}


