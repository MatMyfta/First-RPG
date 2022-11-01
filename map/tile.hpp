#ifndef __TILE_HPP__
#define __TILE_HPP__

#include <SFML/Graphics.hpp>

enum TileType
{
	DEFAULT,
	DAMAGING,
	ENEMY_SPAWNER
};

class Tile
{
private:
protected:
	sf::RectangleShape shape;
	bool collision;

public:
	Tile();
	Tile(float x, float y, float grid_size);

	const TileType getType() const;
	const bool getCollision() const;
	const sf::Vector2f &getPosition() const;
	const sf::FloatRect getGlobalBounds() const;
	const bool intersects(const sf::FloatRect) const;

	void update();
	void render(sf::RenderTarget &);
};

#endif // __TILE_HPP__