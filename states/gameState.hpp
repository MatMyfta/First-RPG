#ifndef __GAMESTATE_HPP__
#define __GAMESTATE_HPP__

#include "state.hpp"
#include "../entities/entity.hpp"

class GameState : public State
{
private:
	Entity player;

protected:
public:
	GameState(sf::RenderWindow *);
	virtual ~GameState();

	void endState();
	void updateKeyBinds(const float &);
	void update(const float &);
	void render(sf::RenderTarget *target = nullptr);
};

#endif // __GAMESTATE_HPP__