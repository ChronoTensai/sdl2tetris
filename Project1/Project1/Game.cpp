#include "Game.h"

Board* gameBoard;
bool init = false;

Game::Game()
{
	
	gameBoard = new Board();
}

void Game::CreateAssetPool()
{

}

void Game::Update()
{
	if (!init)
	{
		LBlock* block = new LBlock();
		gameBoard->AddAtTopBoard(block->GetLogicMatriz(),4,4);
		init = true;
	}
}


Game::~Game()
{
}
