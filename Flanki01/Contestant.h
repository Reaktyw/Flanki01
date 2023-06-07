#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

enum class Condition {
	Game1, Game2, Game3
};

enum class SpriteType {
	Background, Can, Can2
};

enum class canType {
	Beczkowe, Harnas, Kustosz, Zubr
};



class Contestant
{
private:

protected:
	sf::Texture texture;
	sf::Sprite sprite;
	float drinkingSpeed;
	float points;
	sf::Vector2f movement_speed;

	float canEmptiness;						//zrobiæ

	virtual void initializeVariables() = 0;

public:
	Contestant() {};
	virtual ~Contestant() {};

	virtual void setDrinkingSpeed(float _d) = 0;
	float getDrinkingSpeed();
	void setPoints(float _p);
	float getPoints();
	virtual void setSprite(sf::RenderTarget& window, std::string _s) = 0;
	void setTexture(sf::RenderTarget& window, std::string _s);
	const sf::Sprite getSprite() const;
	sf::Vector2f getMovementSpeed();

	void setCanEmptiness(float _elapsed);

	virtual void update(sf::RenderTarget& window) = 0;
	virtual void render(sf::RenderTarget& window) = 0;

};



class Enemy : public Contestant
{
private:
	
	void initializeVariables();
public:

	Enemy(sf::RenderTarget& window);
	~Enemy();

	void setDrinkingSpeed(float _d) {};

	void setSprite(sf::RenderTarget& window, std::string _s);

	void update(sf::RenderTarget& window);
	void render(sf::RenderTarget& window);
};



class Player : public Contestant
{
private:
	float aimVelocity_x;
	float aimVelocity_y;
	float drinkingSpeed;

	void initializeVariables();

public:
	Player(sf::RenderTarget& window);
	~Player();

	void setSprite(sf::RenderTarget& window, std::string _s);
	void updateWindowBoundsCollision(sf::RenderTarget& window);

	void setDrinkingSpeed(float _d);
	float getDrinkingSpeed();
	void setPoints(float _d);
	float getPoints();

	const sf::Sprite getSprite() const;

	void update(sf::RenderTarget& window);
	void render(sf::RenderTarget& window);

};
