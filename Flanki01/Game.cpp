
#include "Game.h"

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
}

//Variables
//Window
void Game::initializeVariables()
{
	this->window = nullptr;
	this->status = Condition::Gra1;

	//Game logic
	this->endGame = false;
	this->canEmptiness = 0;
	this->is_collapsed = false;
	this->your_turn = true;
}

void Game::initializeWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Game 1", sf::Style::Fullscreen);

	this->window->setFramerateLimit(60);
}

void Game::setCan(std::string _s)
{
	//Sets can and checks exeption
	this->setTexture(_s, SpriteType::Can);

	this->can.setScale(0.2f, 0.2f);
	this->can.setPosition(
		(this->window->getSize().x) * 0.5f,
		(this->window->getSize().y) * 0.65f
	);
	this->can.setOrigin(100.f, this->can.getGlobalBounds().top + this->can.getGlobalBounds().height - 150.f);

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
	this->setCan("images/Icon.png");

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
			if (this->ev.key.code == sf::Mouse::Left && this->can.getGlobalBounds().intersects(this->Player1->getSprite().getGlobalBounds()) && your_turn == true)
			{

				this->your_turn = false;

				int x = rand() % 1;
				if (x != 1) {
					this->is_collapsed = true;

					this->setBackground("images/pusty1.png");
					this->status = Condition::Gra2;
				}

				//ODPALAMY PICIE

				//while (!game2_end)
				//{

					//PIJEMY
					

					//na koñcu gry game2_end = true;
				//}


			}
			else if (this->ev.key.code == sf::Mouse::Right)
			{
				this->is_collapsed = false;
			}
		}
	}
}

void Game::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
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
	}
}

void Game::update()
{
	this->pollEvents();

	if (this->getEndGame() == false)
	{
		this->updateMousePositions();

		Player1->update(*this->window);

		this->updateCan();
	}

	//End game
	//if (this->canEmptiness >= 100)
	//{
	//	this->endGame = true;
	//}

}

void Game::renderBackground(sf::RenderTarget& target)
{
	target.draw(this->background);
}

void Game::renderCan(sf::RenderTarget& target)	//target is this->window
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

	this->window->display();
}

void Game::start(Game _game)
{
	while (_game.getWindowIsOpen() && !_game.getEndGame())
	{
		if (this->getCondition() == Condition::Gra1)
		{
			//Update
			_game.update();


			//Render
			_game.render();
		}
		if (this->getCondition() == Condition::Gra2)
		{
			//_game.update2();

			//_game.render2();
		}

	}
}


//TODO
//enum klass - logika w g³ównej pêtli (if (typ) - gra1 lub gra2)
//setTexture
//

//Dlaczego wywala b³¹d przy delete Player i okna
//Dlaczego ci¹gle dzia³a if z Gra1 w metodzie start
