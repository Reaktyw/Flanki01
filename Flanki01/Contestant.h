#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <ctime>
#include <iostream>
#include <vector>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

enum class Condition {
	Game1, Game2
};

enum class SpriteType {
	Background, Can, Can2
};

enum class canType {
	Beczkowe, Harnas, Kustosz
};

class Contestant
{
private:

protected:
	sf::Texture texture;
	sf::Sprite sprite;

	void setTexture(sf::RenderTarget& window, std::string _s);
	virtual void setSprite(sf::RenderTarget& window, std::string _s) = 0;
	virtual void initializeVariables() = 0;

public:
	Contestant() {};
	virtual ~Contestant() {};

	const sf::Sprite getSprite() const;

	virtual void update(sf::RenderTarget& window) = 0;
	virtual void render(sf::RenderTarget& window) = 0;

};



class Enemy : public Contestant
{
private:

	void setSprite(sf::RenderTarget& window, std::string _s);
	void initializeVariables();
public:

	Enemy(sf::RenderTarget& window);
	~Enemy();

	sf::Time getEnemyTurn();

	void update(sf::RenderTarget& window);
	void render(sf::RenderTarget& window);
};



class Player : public Contestant
{
private:
	float aimVelocity_x;
	float aimVelocity_y;
	float points;							//zrobiæ

	void setSprite(sf::RenderTarget& window, std::string _s);
	void initializeVariables();

public:
	Player(sf::RenderTarget& window);
	~Player();

	void updateWindowBoundsCollision(sf::RenderTarget& window);

	const sf::Sprite getSprite() const;

	void update(sf::RenderTarget& window);
	void render(sf::RenderTarget& window);

};
