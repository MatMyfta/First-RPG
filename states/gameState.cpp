#include "gameState.hpp"
#include <iostream>

GameState::GameState(sf::RenderWindow *window) : State(window) {}

GameState::~GameState() {}

void GameState::endState()
{
	std::cout << "Ending the game state...\n";
}

void GameState::updateKeyBinds(const float &dt)
{
	this->checkForQuit();
}

void GameState::update(const float &dt)
{
	this->updateKeyBinds(dt);

	this->player.update(dt);
}

void GameState::render(sf::RenderTarget *target)
{
	this->player.render(this->window);
}