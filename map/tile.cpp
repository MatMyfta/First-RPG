#include "tile.hpp"

Tile::Tile(float x, float y, float grid_size)
{
	this->shape.setSize(sf::Vector2f(grid_size, grid_size));
	this->shape.setFillColor(sf::Color::Green);
}

void Tile::update()
{
}

void Tile::render(sf::RenderTarget &target)
{
	target.draw(this->shape);
}