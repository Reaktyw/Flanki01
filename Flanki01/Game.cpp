
#include "Game.h"

////////////////////////////////////Game1////////////////////

void Game::setTexture(std::string _s, SpriteType _spriteType)
{
	//Sets textures based on enum class
	if (_spriteType == SpriteType::Background)
	{
		try
		{
			if (this->textureBackground.loadFromFile(_s))
			{
				this->background.setTexture(this->textureBackground);
			}
			else
			{
				throw(1);
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
			std::cout << "Nie zaladowano t³a \n";
		}
	}

	else if (_spriteType == SpriteType::Can)
	{
		try
		{
			if (this->textureCan.loadFromFile(_s))
			{
				this->can.setTexture(this->textureCan);
			}
			else
			{
				throw(1);
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
			std::cout << "Nie zaladowano puszki \n";
		}
	}

	else if (_spriteType == SpriteType::Can2)
	{
		try
		{
			if (this->textureCan2.loadFromFile(_s))
			{
				this->can2.setTexture(this->textureCan2);
			}
			else
			{
				throw(1);
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
			std::cout << "Nie zaladowano puszki 2 \n";
		}
	}
}

//Variables
//Window
void Game::initializeVariables()
{
	this->window = nullptr;
	this->status = Condition::Game1;

	//Game logic
	this->endGame = false;
	this->is_collapsed = false;
	this->your_ture = true;
	this->render_once = true;
	this->which_ture = "Your ture";

	this->startCountdown = false;
	this->enemy_has_rock = false;

	this->brickSpawnTimerMax = 10.f;
	this->brickSpawnTimer = this->brickSpawnTimerMax;
	this->mouseHeld = false;
	this->maxBricks = 10;
}

void Game::initializeWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Game 1", sf::Style::Fullscreen);
	this->window->setFramerateLimit(40);
}

void Game::setCan(std::string _s, canType _can_type)
{
	//Sets can and checks exeption
	
	if (_can_type == canType::Beczkowe && this->getCondition() == Condition::Game1)
	{
		this->setTexture(_s, SpriteType::Can);
		this->can.setScale(70.0f / this->can.getGlobalBounds().width, 150.0f / this->can.getGlobalBounds().height);
		this->can.setPosition(
			(this->window->getSize().x) * 0.55f,
			(this->window->getSize().y) * 0.65f
		);
		this->can.setOrigin(100.f, 200.f);
	}
	else if (_can_type == canType::Harnas && this->getCondition() == Condition::Game1)
	{
		this->can.setScale(70.0f / this->can.getGlobalBounds().width, 140.0f / this->can.getGlobalBounds().height);
		this->setTexture(_s, SpriteType::Can);
		this->can.setPosition(
			(this->window->getSize().x) * 0.55f,
			(this->window->getSize().y) * 0.65f
		);
		this->can.setOrigin(100.f, 200.f);
	}
	else if (_can_type == canType::Kustosz && this->getCondition() == Condition::Game1)
	{
		this->setTexture(_s, SpriteType::Can);
		this->can.setScale(70.0f / this->can.getGlobalBounds().width, 150.0f / this->can.getGlobalBounds().height);
		this->can.setPosition(
			(this->window->getSize().x) * 0.55f,
			(this->window->getSize().y) * 0.65f
		);
		this->can.setOrigin(100.f, 200.f);
	}

}

void Game::setBackground(std::string _s)
{
	this->setTexture(_s, SpriteType::Background);
	this->background.setScale(
		static_cast<float>(this->window->getSize().x) / textureBackground.getSize().x,
		static_cast<float>(this->window->getSize().y) / textureBackground.getSize().y
	);
	this->background.setTextureRect(sf::IntRect(0, 0, 1500, 1500));
}

//Constructors and Destructors
Game::Game()
{
	this->initializeVariables();
	this->initializeWindow();
	this->setBackground("images/Plansza1.png");
	this->setCan("images/beczkowe_wisnia.png", canType::Beczkowe);
	this->setCan2("images/kozel.png");
	this->initializeFont();
	this->initializeText();

	Enemy1 = new Enemy(*this->window);
	Player1 = new Player(*this->window);
}

Game::~Game()
{
	//delete this->window;
	//delete this->Player1;
}


const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

//Accessors (akcesoria)
const bool Game::getEndGame() const
{
	return this->endGame;
}

const sf::Sprite Game::getBackground() const
{
	return this->background;
}

const Condition Game::getCondition() const
{
	return this->status;
}


//Public Functions
void Game::pollEvents()
{
	//Checks if we want to end and starts second part of the game
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close(); break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
			{
				this->window->close(); break;
			}
		case sf::Event::MouseButtonPressed:
		{

			if (this->ev.key.code == sf::Mouse::Left && this->your_ture == true && this->status == Condition::Game1)
			{
				//Our turn
				this->your_ture = false;
				if (this->can.getGlobalBounds().intersects(this->Player1->getSprite().getGlobalBounds()))
				{
					int x = rand() % 2;
					if (x == 1)
					{
						this->clock.restart();
						this->is_collapsed = true;
						this->startCountdown = true;
						this->Enemy1->setSprite(*this->window, "images/pusty1.png", "n");
						this->status = Condition::Game2;
					}
					else if (x != 1)
					{
						this->which_ture = "Enemy ture";
						this->clock.restart();
						this->startCountdown = true;
					}
				}
				else
				{				
					//Enemy turn
					this->which_ture = "Enemy ture";
				}
				this->clock.restart();
				this->startCountdown = true;

			}

			else if (this->ev.key.code == sf::Mouse::Right)
			{
				this->your_ture = true;
				this->is_collapsed = false;
				this->status = Condition::Game1;
				this->which_ture = "Your ture";
				this->setBackground("images/Plansza1.png");
				this->Enemy1->setSprite(*this->window, "images/Pudzian_przeciwnik.png", "n");
				this->can.setPosition(
					(this->window->getSize().x) * 0.55f,
					(this->window->getSize().y) * 0.65f
				);
			}
		}
		}
	}
}


void Game::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateCan()
{
	if (this->is_collapsed == true)
	{
		this->can.setRotation(90);
	}
	else if (!is_collapsed)
	{
		this->can.setRotation(0);
		this->can.setPosition(
			(this->window->getSize().x) * 0.55f,
			(this->window->getSize().y) * 0.65f
		);
	}
	if (this->can.getGlobalBounds().intersects(this->Player1->getSprite2().getGlobalBounds()))
	{
		this->your_ture = true;
		this->is_collapsed = false;
		this->startCountdown = false;
		this->setBackground("images/Plansza1.png");
		this->status = Condition::Game1;
		this->which_ture = "Your ture";
		this->clock.restart();
		this->startCountdown;
	}
}

void Game::update()
{
	this->pollEvents();

	if (this->getEndGame() == false)
	{
		this->updateCan();

		this->updateEnemyTurn();

		this->updateMousePositions();

		this->updateText();

		Player1->update(*this->window);
	}

}

void Game::renderBackground(sf::RenderTarget& target)
{
	target.draw(this->background);
}

void Game::renderCan(sf::RenderTarget& target)
{
	target.draw(this->can);
}


void Game::render()
{
	this->window->clear(sf::Color::Black);

	this->renderBackground(*this->window);

	Enemy1->render(*this->window);
	
	this->renderCan(*this->window);

	Player1->render(*this->window);

	this->renderText(*this->window);

	this->window->display();
}


/////////////////////////////////////Game2////////////////////////////////
//Private Functions
void Game::initializeFont()
{
	this->font.loadFromFile("Fonts/comic-sans-ms/comici.ttf");
}

void Game::initializeText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(30);
	this->uiText.setFillColor(sf::Color::Red);
	this->uiText.setString("HMMMMMMMMMMMMMMM");
}


//Public functions
void Game::spawnBrick()
{
	/*
	Spawns bricks and sets types, colours, positions
	*/

	//Randomize type
	int type = rand() % 4;

	switch (type)
	{
	case 0:
		this->setBrick("images/beczkowe_wisnia.png", canType::Beczkowe);
		this->can_type.emplace_back(canType::Beczkowe);
		break;
	case 1:
		this->setBrick("images/zubr.png", canType::Zubr);
		this->can_type.emplace_back(canType::Zubr);
		break;
	case 2:
		this->setBrick("images/harnas.png", canType::Harnas);
		this->can_type.emplace_back(canType::Harnas);
		break;
	case 3:
		this->setBrick("images/kustosz.png", canType::Kustosz);
		this->can_type.emplace_back(canType::Kustosz);
		break;
	}

	//Spawn brick
	this->bricks.emplace_back(this->brick);
	//std::cout << "can type"<<can_type.size()<<std::endl;
	//std::cout << "bricks "<<bricks.size() << std::endl;
}

void Game::updateText()
{
	if (this->status != Condition::EndScreen)
	{
		std::stringstream ss;
		ss << "Points: " << this->Player1->getPoints() << std::endl
			<< "Player beer amount " << this->Player1->getCanEmptiness() << std::endl
			<< "Enemy beer amount " << this->Enemy1->getCanEmptiness() << std::endl << std::endl
			<< this->which_ture;
		this->uiText.setString(ss.str());
	}
	else if(this->Player1->getCanEmptiness() < this->Enemy1->getCanEmptiness())
	{
		std::stringstream ss;
		ss << "Tanio skory nie sprzedam!";
		this->uiText.setPosition(
			this->window->getSize().x * 0.55,
			this->window->getSize().y * 0.6
		);
		this->uiText.setScale(2.f, 2.f);
		this->uiText.setColor(sf::Color::White);
		this->uiText.setString(ss.str());
	}
	else if (this->Player1->getCanEmptiness() > this->Enemy1->getCanEmptiness())
	{
		std::stringstream ss;
		ss << "POLSKA GUROOM!";
		this->uiText.setPosition(
			this->window->getSize().x * 0.55,
			this->window->getSize().y * 0.6
		);
		this->uiText.setScale(2.f, 2.f);
		this->uiText.setColor(sf::Color::White);
		this->uiText.setString(ss.str());
	}
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
}

void Game::renderBricks(sf::RenderTarget& target)
{
	for (auto& el : this->bricks) {
		target.draw(el);
	}
}

void Game::setCan2(std::string _s)
{
	//Sets can and checks exeption
	this->setTexture(_s, SpriteType::Can2);

	this->can2.setScale(2.5f, 3.0f);
	this->can2.setPosition(
		(this->window->getSize().x) * 0.01f,
		(this->window->getSize().y) * 0.6f
	);
}

void Game::setTextureBrick(std::string _s, canType _can_type)
{
	if (_can_type == canType::Zubr)
	{
		try
		{
			if (this->brickTexture[0].loadFromFile(_s))
			{
				this->brick.setTexture(this->brickTexture[0]);
			}
			else
			{
				throw(1);
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
			std::cout << "Nie zaladowano brick 0 \n";
		}
	}
	else if (_can_type == canType::Harnas)
	{
		try
		{
			if (this->brickTexture[1].loadFromFile(_s))
			{
				this->brick.setTexture(this->brickTexture[1]);
			}
			else
			{
				throw(1);
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
			std::cout << "Nie zaladowano brick 1 \n";
		}
	}
	else if (_can_type == canType::Kustosz)
	{
		try
		{
			if (this->brickTexture[2].loadFromFile(_s))
			{
				this->brick.setTexture(this->brickTexture[2]);
			}
			else
			{
				throw(1);
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
			std::cout << "Nie zaladowano brick 2 \n";
		}
	}
	else if (_can_type == canType::Beczkowe)
	{
		try
		{
			if (this->brickTexture[3].loadFromFile(_s))
			{
				this->brick.setTexture(this->brickTexture[3]);
			}
			else
			{
				throw(1);
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
			std::cout << "Nie zaladowano brick 3 \n";
		}
	}
}

void Game::setBrick(std::string _s, canType _can_type)
{
	this->setTextureBrick(_s, _can_type);
	this->brick.setScale(0.4f, 0.4f);
	this->brick.setPosition(
		static_cast<float>(rand() % static_cast<int>(
			(this->window->getSize().x - this->brick.getGlobalBounds().width) / 2) + this->window->getSize().x / 2),
		0.f
	);
	if (_can_type == canType::Zubr)
	{
		this->brick.setScale(1.f, 1.f);
	}
}

void Game::renderCan2(sf::RenderTarget& target)
{
	target.draw(this->can2);
}

void Game::updateBricks()
{
	//Updating timer for brick spawning
	if (this->bricks.size() < this->maxBricks) {
		if (this->brickSpawnTimer >= this->brickSpawnTimerMax)
		{
			//Spawn brick and reset the timer
			this->spawnBrick();
			this->brickSpawnTimer = 0.f;
		}
		else
			this->brickSpawnTimer += 1.f;
	}

	//Move and update bricks
	for (int i = 0; i < this->bricks.size(); i++) {

		bool deleted = false;

		this->bricks[i].move(0.f, 5.f);

		//Delete at bottom
		if (this->bricks[i].getPosition().y > this->window->getSize().y)
		{
			this->bricks.erase(this->bricks.begin() + i);
			this->can_type.erase(this->can_type.begin() + i);
		}
	}

	//Check if clicked
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->mouseHeld == false)
		{
			this->mouseHeld = true;

			bool deleted = false;

			for (int i = 0; i < this->bricks.size() && deleted == false; i++)
			{
				if (this->bricks[i].getGlobalBounds().contains(this->mousePosView))
				{
					if (this->can_type[i] == canType::Beczkowe || this->can_type[i] == canType::Harnas || this->can_type[i] == canType::Kustosz)
					{
						this->Player1->setPoints(10);
						this->Player1->setDrinkingSpeed(0.01);
						std::cout << this->Player1->getPoints();
					}
					else
					{
						this->Player1->setPoints(-10);
						if (this->Player1->getDrinkingSpeed() > 0)
						{
							this->Player1->setDrinkingSpeed(-0.1);
						}
						std::cout << this->Player1->getPoints();
					}


					//Delete brick
					deleted = true;
					this->bricks.erase(this->bricks.begin() + i);
					this->can_type.erase(this->can_type.begin() + i);
				}
			}
		}
	}
	else
	{
		this->mouseHeld = false;
	}

}

void Game::updateElapsedTime()
{
	if (this->startCountdown)
	{
		this->elapsedTime = clock.getElapsedTime().asSeconds();
	}
	if (this->elapsedTime >= this->Enemy1->getMovementSpeed_x())
	{
		this->is_collapsed = false;
		this->Enemy1->setSprite(*this->window, "images/Pudzian_przeciwnik.png", "n");
		this->clock.restart();
		this->status = Condition::Game1;
		this->which_ture = "Enemy ture";
	}
}

void Game::update2()
{
	if (this->Player1->getCanEmptiness() <= 0)
	{
		this->status = Condition::EndScreen;
		this->Enemy1->setSprite(*this->window, "images/Pudzian_gratulacje.png", "y1");
	}

	this->pollEvents();

	if (this->getEndGame() == false)
	{
		this->updateElapsedTime();

		this->updateMousePositions();

		this->updateText();

		this->updateBricks();

		this->updateCan();

		this->Player1->setCanEmptiness(0.1f);
	}
}

void Game::render2()
{
	this->window->clear(sf::Color::Black);

	this->renderBackground(*this->window);
	
	Enemy1->render(*this->window);

	this->renderCan(*this->window);

	this->renderCan2(*this->window);

	this->renderBricks(*this->window);

	this->renderText(*this->window);

	this->window->display();
}

//////////////////////Game3/////////////////


void Game::updateEnemyTurn()
{
	if (this->startCountdown)
	{
		this->elapsedTime = clock.getElapsedTime().asSeconds();
	}
	if (this->elapsedTime >= 3 && this->startCountdown && this->status == Condition::Game1)
	{
		this->your_ture = false;
		this->is_collapsed = false;
		this->startCountdown = false;
		this->enemy_has_rock = true;
	}
	else if (this->enemy_has_rock)
	{
		//Enemy turn
		int j = rand() % 2;
		if (j == 1)
		{
			this->is_collapsed = true;
			this->setBackground("images/Tlo.png");
			this->enemy_has_rock = false;

			this->can.setPosition(
				static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->can.getGlobalBounds().width) * 0.9f),
				static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->can.getGlobalBounds().width) * 0.9f)
			);

			this->Player1->setSprite2(*this->window, "images/spejson.png");

			this->status = Condition::Game3;
		}
		else if (j == 0)
		{
			//Our ture
			this->which_ture = "Your ture";
			this->enemy_has_rock = false;
			this->your_ture = true;
		}
	}
}

void Game::update3()
{
	if (this->Enemy1->getCanEmptiness() <= 0)
	{
		this->status = Condition::EndScreen;
		this->Enemy1->setSprite(*this->window, "images/pudzian_wysmiewa.png", "y2");
	}

	this->pollEvents();

	if (this->getEndGame() == false)
	{
		this->updateEnemyTurn();

		this->updateCan();

		this->updateText();

		this->Player1->update2(*this->window);

		this->Enemy1->setCanEmptiness(0.2f);
	}
}

void Game::render3()
{
	this->window->clear(sf::Color::Black);

	this->renderBackground(*this->window);

	this->renderCan(*this->window);

	this->Player1->render2(*this->window);

	this->renderText(*this->window);

	this->window->display();
}

////////////////EndScreen////////////////
void Game::update4()
{
	this->pollEvents();

	if (this->getEndGame() == false)
	{
		this->updateEnemyTurn();

		this->updateCan();

		this->updateText();
	}
}

void Game::render4()
{
	this->window->clear(sf::Color::Black);

	this->renderBackground(*this->window);

	this->renderText(*this->window);

	this->Enemy1->render(*this->window);

	this->window->display();
}




void Game::start(Game _game)
{
	srand(time(NULL));

	while (_game.getWindowIsOpen() && !_game.getEndGame())
	{
		if (this->getCondition() == Condition::Game1)
		{
			//Update
			_game.update();


			//Render
			_game.render();
		}
		if (this->getCondition() == Condition::Game2)
		{
			_game.update2();


			_game.render2();
		}
		if (this->getCondition() == Condition::Game3)
		{
			_game.update3();


			_game.render3();
		}
		if (this->getCondition() == Condition::EndScreen)
		{
			_game.update4();


			_game.render4();
		}
		this->status = _game.getCondition();
	}

	this->window->close();
}



//TODO
/*
Ekran końcowy:
Wyświetlanie Pudziana

*/

//Dlaczego wywala b³¹d przy delete Player i okna
//Dlaczego ci¹gle dzia³a if z Gra1 w metodzie start
