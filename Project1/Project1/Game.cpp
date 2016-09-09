#include "Game.h"

Game::Game()
{
	gameBoard = new Board(&HEIGHT_BOARD, &WIDTH_BOARD, BOARD_X, BOARD_Y, TILE_SIZE);
	hasTetrominioActive = false;

	//EngineTools::InputService().RegisterInput(InputDefinition::InputKeys::UP, RotateTetrominio);
	//EngineTools::InputService().RegisterInput(InputDefinition::InputKeys::LEFT, MoveLeftTetrominio);
	//EngineTools::InputService().RegisterInput(InputDefinition::InputKeys::RIGHT, MoveRightTetrominio);
	//EngineTools::InputService().RegisterInput(InputDefinition::InputKeys::DOWN, DownTetrominio);

}

void Game::CreateAssetPool()
{
	tetrominioMap[0] = new IBlock();
	tetrominioMap[1] = new JBlock();
	tetrominioMap[2] = new LBlock();
	tetrominioMap[3] = new OBlock();
	tetrominioMap[4] = new SBlock();
	tetrominioMap[5] = new TBlock();
	tetrominioMap[5] = new ZBlock();
}

//Primero se consumen los inputs

void Game::RotateTetrominio()
{

}

void Game::MoveLeftTetrominio()
{
}

void Game::MoveRightTetrominio()
{
}

void Game::DownTetrominio()
{
}

//Despues se llama al Update

void Game::PickTetrominio()
{
	//Pick Random Tetriminio
	activeTetrominio = tetrominioMap[0];
	hasTetrominioActive = true;
}

void Game::Update()
{
	//PickTetrominio
	if (!hasTetrominioActive)
	{
		PickTetrominio();
	}
	//DownTetrominio
	//CheckColision
	//if(collision == true)
	//{
		// Update Board
		// gameBoard->Redraw();
	//}
	//else
	//{
		//En el caso de usar solo un renderer
		gameBoard->Redraw();
		activeTetrominio->Redraw();
	//}	
}



Game::~Game()
{
	delete gameBoard;
	gameBoard = nullptr;

	delete activeTetrominio;

	for (std::map<int, Tetrimino*>::iterator it = tetrominioMap.begin(); it != tetrominioMap.end(); ++it)
	{
		delete (it->second);
	}
	tetrominioMap.clear();
}
