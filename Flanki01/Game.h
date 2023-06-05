
#pragma once
#include "Contestant.h"


class Game
{
private:
	//Variables (zmienne)
	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::Texture textureBackground;
	sf::Texture textureCan;
	sf::Texture textureCan2;
	sf::Vector2i mousePosWindow;
	Condition status;
	SpriteType type;


	//Game logic
	bool endGame;
	float canEmptiness;						//zrobiæ
	bool your_turn;
	bool is_collapsed;
	bool render_once;
	sf::Time elapsedTime;


	//Game objects
	sf::Sprite can;
	sf::Sprite can2;
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
	void enemyTurn();
	void updateMousePositions();			//zrobiæ klikanie podczas picia mo¿e w Player
	void updateCan();
	void update();
	//
	void renderBackground(sf::RenderTarget& target);	//target is this->window
	void renderCan(sf::RenderTarget& target);
	void render();

	///////////////Game2//////////////

	void setCan2(std::string _s);

	void update2();

	void renderCan2(sf::RenderTarget& target);
	void render2();


	void start(Game _game);
};
