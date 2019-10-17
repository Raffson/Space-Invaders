/*
 * GameState.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: raffson
 */

#include "GameState.h"

namespace AR {

GameState::GameState()
	: started(false), paused(false), gameOver(false)
{
		//initialize a list with aliens for level 0
}

GameState::~GameState()
{

}

const std::vector<std::shared_ptr<Object> >&
	GameState::GetObjects() const { return entities; }

const bool GameState::Started() const { return started; }
const bool GameState::Paused() const { return paused; }
const bool GameState::GameOver() const { return gameOver; }
void GameState::Reset()
{
	started = false;
	paused = false;
	gameOver = false;
}

void GameState::StartGame() { started = true; }
void GameState::EndGame() { gameOver = true; }
void GameState::PauseGame() { paused = true; }
void GameState::ResumeGame() { paused = false; }
const bool GameState::NoBullets() const { return true; }

}  // namespace AR
