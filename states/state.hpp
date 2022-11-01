#ifndef __STATE_HPP__
#define __STATE_HPP__

#include <vector>
#include <SFML/Graphics.hpp>

class State
{
private:
	std::vector<sf::Texture *> textures;
	bool quit;

protected:
	sf::RenderWindow *window;

public:
	State(sf::RenderWindow *);
	virtual ~State();

	const bool &getQuit() const;

	virtual void checkForQuit();

	virtual void endState() = 0;
	virtual void updateKeyBinds(const float &) = 0;
	virtual void update(const float &) = 0;
	virtual void render(sf::RenderTarget *target = nullptr) = 0;
};

#endif // __STATE_HPP__