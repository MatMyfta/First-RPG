#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <SFML/Graphics.hpp>

class Entity
{
private:
protected:
	sf::RectangleShape shape;
	float movement_speed = 100.f;

public:
	Entity();
	virtual ~Entity();

	void move(const float &, const float, const float);
	void update(const float &);
	void render(sf::RenderTarget *);
};

#endif // __ENTITY_HPP__