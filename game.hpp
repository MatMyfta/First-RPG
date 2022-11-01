#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <SFML/Graphics.hpp>
#include <stack>

#include "states/state.hpp"

class Game
{
private:
	sf::RenderWindow *window;
	sf::VideoMode video_mode;
	sf::Event event;

	sf::Clock dtClock;
	float dt;

	std::stack<State *> states;

	void initWindow();
	void initStates();

public:
	// Constructor
	Game();
	// Destructor
	~Game();

	// Accessors
	const bool running() const;

	// Functions
	void updateDt();
	void pollEvents();
	void update();
	void render();
};

#endif // __GAME_HPP__