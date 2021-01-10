#pragma once
#include "GameEngine/EntitySystem/Entities/PlayerEntity.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <time.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <vector>
#include <time.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;	

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		void Update();		
		bool IsGameOver() { return false; }

	private: 
		void CreatePlayer();
		void CreateGround(sf::Vector2f pos, sf::Vector2f size); 
		GameEngine::PlayerEntity* m_player;
		void CreateRaindrop(sf::Vector2<float> startPos);
		void CreateBackground();
		GameEngine::Entity* raindrop;
		sf::Clock Timer;

	};
}

