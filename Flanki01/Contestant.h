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
	sf::Texture texture2;
	sf::Sprite sprite;
	sf::Sprite sprite2;
	float drinkingSpeed;
	float points;
	float movement_speed_x;					//float ¿eby mo¿na by³o do enemy przypisaæ wartoœæ ³atwo w updateElapsed
	float movement_speed_y;

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
	virtual void setSprite2(sf::RenderTarget& window, std::string _s) = 0;
	void setTexture(std::string _s);
	void setTexture2(std::string _s);
	const sf::Sprite getSprite() const;
	const sf::Sprite getSprite2() const;
	float getMovementSpeed_x();
	float getMovementSpeed_y();

	void setCanEmptiness(float _elapsed);

	virtual void update(sf::RenderTarget& window) = 0;
	virtual void update2(sf::RenderTarget& window) = 0;
	void render(sf::RenderTarget& window);
	void render2(sf::RenderTarget& window);

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
	void setSprite2(sf::RenderTarget& window, std::string _s);

	void update(sf::RenderTarget& window);
	void update2(sf::RenderTarget& window);
};



class Player : public Contestant
{
private:
	float aimVelocity_x;
	float aimVelocity_y;

	void initializeVariables();

public:
	Player(sf::RenderTarget& window);
	~Player();

	void setSprite(sf::RenderTarget& window, std::string _s);
	void setSprite2(sf::RenderTarget& window, std::string _s);
	void updateWindowBoundsCollision(sf::RenderTarget& window);

	void setDrinkingSpeed(float _d);
	float getDrinkingSpeed();

	const sf::Sprite getSprite() const;

	void update(sf::RenderTarget& window);
	void update2(sf::RenderTarget& window);
};
