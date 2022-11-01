/*
 * This class creates and controls the window and the context of the game.
 */

#include <iostream>
#include <fstream>
#include <sstream>

#include "game.hpp"

#include "states/gameState.hpp"

// Constructor
Game::Game()
{
	this->initWindow();
	this->initStates();
}

// Destructor
Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}

	std::cout << "Ending Game\n";
}

/*
 * Initialize the window variables.
 * @return void
 */
void Game::initWindow()
{

	video_mode.width = 800;
	video_mode.height = 600;
	std::string title = "None";
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;

	std::ifstream ifs("config/window.ini");

	if (!ifs.is_open())
	{
		// TODO: Open error in alert window.
		std::cerr << "Couldn't open file window.ini, using default values";
	}
	else
	{
		std::getline(ifs, title);
		ifs >> video_mode.width >> video_mode.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	ifs.close();

	this->window = new sf::RenderWindow(
		 video_mode,
		 title,
		 sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

/*
 * Initialize the states stack.
 * @return void
 */
void Game::initStates()
{
	this->states.push(new GameState(this->window));
}

/*
 * Check if the game is running.
 * @return bool
 */
const bool Game::running() const
{
	return this->window->isOpen();
}

/*
 * Updates the dt variable with the time it takes to update and render one frame.
 * @return void
 */
void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

/*
 * @return void
 */
void Game::pollEvents()
{
	// Event polling
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
}

/*
 * @return void
 */
void Game::update()
{
	this->pollEvents();

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);
		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
}

/*
 * @return void
 */
void Game::render()
{

	if (!this->states.empty())
		this->states.top()->render();

	// window rendering
	this->window->clear();
	// this->window->draw();
	this->window->display();
}