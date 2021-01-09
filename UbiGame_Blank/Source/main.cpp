#include "GameEngine/GameEngineMain.h"

int main()
{
	GameEngine::GameEngineMain* mainEngine = GameEngine::GameEngineMain::GetInstance();
	while (mainEngine->GetRenderWindow()->isOpen())
	{		
		AddEntity();		
		mainEngine->Update();
	}

	delete mainEngine;
	return 0;
}