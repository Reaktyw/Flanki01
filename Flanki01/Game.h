
#pragma once
#include "Contestant.h"


class Game
{
private:
	//Variables (zmienne)
	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::Clock clock;
	float elapsedTime;
	sf::Texture textureBackground;
	sf::Texture textureCan;
	sf::Texture textureCan2;
	sf::Texture brickTexture[4];

	Condition status;
	SpriteType type;
	canType can_type[4];					//zrobiæ


	//Game logic
	bool endGame;
	bool your_turn;
	bool is_collapsed;
	bool render_once;


	//Game objects
	sf::Sprite can;
	sf::Sprite can2;
	sf::Sprite background;
	Contestant* Enemy1;
	Contestant* Player1;

	//Private Functions
	void setTexture(std::string _s, SpriteType _spriteType);
	void initializeVariables();				//Podstawowe inicjalizowanie
	void initializeWindow();
	void setBackground(std::string _s);


	/////////Game2////////////
	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	sf::Font font;

	//Text
	sf::Text uiText;

	//Game logic
	bool endGame2;
	float brickSpawnTimer;
	float brickSpawnTimerMax;
	int maxBricks;
	bool mouseHeld;
	bool startCountdown;

	//Game objects
	std::vector<sf::Sprite> bricks;
	sf::Sprite brick;


	//Private methods
	void initializeFont();
	void initializeText();

	//////////////////////Game3////////////////
	bool enemy_has_rock;

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
	void setCan(std::string _s, canType _cantype);
	void renderText(sf::RenderTarget& target);

	void pollEvents();
	void enemyTurn();
	void updateCan();
	void update();
	//
	void renderBackground(sf::RenderTarget& target);	//target is this->window
	void renderCan(sf::RenderTarget& target);
	void render();

	///////////////Game2//////////////
	void spawnBrick();
	void updateMousePositions();
	void updateText();

	void renderBricks(sf::RenderTarget& target);

	void setCan2(std::string _s);
	void setTextureBrick(std::string _s, canType _can_type);
	void setBrick(std::string _s, canType _can_type);

	canType getCan();

	void updateBricks();
	void updateElapsedTime();
	void update2();

	void renderCan2(sf::RenderTarget& target);
	void render2();


	/////////////////Game3///////////////////
	void updateEnemyTurn();

	void update3();

	void render3();


	void start(Game _game);
};
