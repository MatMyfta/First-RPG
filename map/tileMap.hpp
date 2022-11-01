#ifndef __TILEMAP_HPP__
#define __TILEMAP_HPP__

#include "tile.hpp"

class TileMap
{
private:
	// std::vector<std::vector<std::vector<Tile>>> map;
	sf::Vector2u maxSize;
	unsigned gridSizeU;
	unsigned layers;

public:
	TileMap();
	~TileMap();

	void update();
	void render(sf::RenderTarget &);
};

#endif // __TILEMAP_HPP__