#include "entity.hpp"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(32.f, 32.f));
	this->shape.setFillColor(sf::Color::White);
	this->movement_speed = 100.f;
}

Entity::~Entity()
{
}

void Entity::move(const float &dt, const float x, const float y)
{
	this->shape.move(x * this->movement_speed * dt, y * this->movement_speed * dt);
}

void Entity::update(const float &dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->move(dt, 0.f, 1.f);
}

void Entity::render(sf::RenderTarget *target)
{
	target->draw(this->shape);
}