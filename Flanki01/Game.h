
#pragma once
#include "Contestant.h"

enum class Condition {
	Gra1, Gra2
};

enum class SpriteType {
	Background, Can
};

class Game
{
private:
	//Variables (zmienne)
	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::Texture textureBackground;
	sf::Texture textureCan;
	sf::Vector2i mousePosWindow;
	Condition status;
	SpriteType type;


	//Game logic
	bool endGame;
	float canEmptiness;						//zrobiæ
	bool your_turn;
	bool is_collapsed;


	//Game objects
	sf::Sprite can;
	sf::Sprite background;
	Contestant* Enemy1;
	Contestant* Player1;

	//Private Functions
	void setTexture(std::string _s, SpriteType _spriteType);
	void initializeVariables();		//Podstawowe inicjalizowanie
	void initializeWindow();
	void setCan(std::string _s);
	void setBackground(std::string _s);


public:
	//Constructors and Destructors
	Game();
	virtual ~Game();

	//Accessors (akcesoria)
	const bool getWindowIsOpen() const;
	const bool getEndGame() const;
	const sf::Sprite getBackground() const;
	const Condition getCondition() const;

	//Public Functions
	//void spawnCan();

	///////////////Game1///////////////

	void pollEvents();
	void updateMousePositions();			//zrobiæ klikanie podczas picia mo¿e w Player
	void updateCan();
	void update();
	//
	void renderBackground(sf::RenderTarget& target);
	void renderCan(sf::RenderTarget& target);
	void render();

	///////////////Game2//////////////

	void update2();

	void render2();


	void start(Game _game);
};
