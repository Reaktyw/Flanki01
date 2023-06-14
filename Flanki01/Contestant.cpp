#include "Contestant.h"


//////////////////////////////////////////Contestant//////////////////////////////////


void Contestant::setDrinkingSpeed(float _d)
{
	this->drinkingSpeed = this->drinkingSpeed + _d;
}

float Contestant::getDrinkingSpeed()
{
	return this->drinkingSpeed;
}

void Contestant::setPoints(float _p)
{
	this->points = this->points + _p;
}

float Contestant::getPoints()
{
	return this->points;
}

void Contestant::setTexture(std::string _s)
{
	try
	{
		if (this->texture.loadFromFile(_s))
		{
			this->sprite.setTexture(texture);
		}
		else
		{
			throw(1);
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
		std::cout << "Nie zaladowano celownika \n";
	}
}

void Contestant::setTexture2(std::string _s)
{
	try
	{
		if (this->texture2.loadFromFile(_s))
		{
			this->sprite2.setTexture(texture2);
		}
		else
		{
			throw(1);
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
		std::cout << "Nie zaladowano celownika \n";
	}
}

const sf::Sprite Contestant::getSprite() const
{
	return this->sprite;
}

const sf::Sprite Contestant::getSprite2() const
{
	return this->sprite2;
}

float Contestant::getMovementSpeed_x()
{
	return this->movement_speed_x;
}

float Contestant::getMovementSpeed_y()
{
	return this->movement_speed_y;
}

float Contestant::getCanEmptiness()
{
	return this->canEmptiness;
}

void Contestant::render(sf::RenderTarget& window)
{
	window.draw(this->sprite);
}

void Contestant::render2(sf::RenderTarget& window)
{
	window.draw(this->sprite2);
}




///////////////////////////////////////////Enemy/////////////////////////////////////////////

//Private Functions

void Enemy::setSprite(sf::RenderTarget& window, std::string _s, std::string end)
{
	//Loads basic texture and sprite
	if (end == "n")
	{
		this->setTexture(_s);
		this->sprite.setScale(0.4f, 0.4f);
		this->sprite.setPosition(
			static_cast<float>(static_cast<int>(window.getSize().x) * 0.55f),
			static_cast<float>(static_cast<int>(window.getSize().y) * 0.35f)
		);
	}
	else if (end == "y1")
	{
		this->setTexture(_s);
		this->sprite.setScale(1.f, 1.f);
		this->sprite.setPosition(
			0.f, 
			static_cast<float>(static_cast<int>(window.getSize().y - this->sprite.getGlobalBounds().height))
		);
	}
	else if (end == "y2")
	{
		this->setTexture(_s);
		this->sprite.setScale(1.5f, 1.5f);
		this->sprite.setPosition(
			0.f,
			static_cast<float>(static_cast<int>(window.getSize().y) * 0.5f)
		);
	}

}

void Enemy::setSprite2(sf::RenderTarget& window, std::string _s)
{
	this->setTexture(_s);
	this->sprite.setScale(0.5f, 0.5f);
	this->sprite.setPosition(
		static_cast<float>(static_cast<int>(window.getSize().x - this->texture.getSize().x) * 0.625f),
		static_cast<float>(static_cast<int>(window.getSize().y - this->texture.getSize().y) * 0.667f)
	);
}

void Enemy::setCanEmptiness(float _elapsed)
{
	this->canEmptiness -= _elapsed;
	std::cout << "Enemy can emptiness " << this->canEmptiness << std::endl;
}

void Enemy::initializeVariables()
{
	//Intializes basics
	this->canEmptiness = 100.f;
	this->movement_speed_x = 10.f;
	this->movement_speed_y = 10.f;
}

//Constructors and Destructors
Enemy::Enemy(sf::RenderTarget& window)
{
	this->setSprite(window, "images/Pudzian_gratulacje.png", "n");
	this->setSprite(window, "images/Pudzian_przeciwnik.png", "n");
	this->initializeVariables();	
}

Enemy::~Enemy()
{
	
}

//Public Functions
void Enemy::update(sf::RenderTarget& window)
{
	
}

void Enemy::update2(sf::RenderTarget& window)
{

}




///////////////////////////////////////////Player///////////////////////////////////////////////

//Private Functions


void Player::setSprite(sf::RenderTarget& window, std::string _s, std::string end)
{
	//Loads basic texture and sprite (For now. We will change it to load given texture)
	this->setTexture(_s);
	this->sprite.setScale(0.5f, 0.5f);
	this->sprite.setPosition(
		static_cast<float>(static_cast<int>(window.getSize().x) * 0.5f),
		static_cast<float>(static_cast<int>(window.getSize().y) * 0.5f)
	);
}

void Player::setSprite2(sf::RenderTarget& window, std::string _s)
{
	this->setTexture2(_s);
	this->sprite2.setScale(0.5f, 0.5f);
	this->sprite2.setPosition(
		static_cast<float>(rand() % static_cast<int>(window.getSize().x - this->sprite2.getGlobalBounds().width)),
		static_cast<float>(rand() % static_cast<int>(window.getSize().y - this->sprite2.getGlobalBounds().height))
	);
}

void Player::setCanEmptiness(float _elapsed)
{
	if (this->drinkingSpeed > 0)
	{
		this->canEmptiness -= this->drinkingSpeed;
	}
	std::cout << "Player can emptiness " << this->canEmptiness << std::endl;
}

void Player::initializeVariables()
{
	//Intializes basics
	this->canEmptiness = 100.f;
	this->aimVelocity_x = 20.f;
	this->aimVelocity_y = 7.f;
	this->points = 0;
	this->drinkingSpeed = 0.1f;														//zmieniæ
	this->movement_speed_x = 10.f;
	this->movement_speed_y = 10.f;
}



//Constructors and Destructors
Player::Player(sf::RenderTarget& window)
{
	this->setSprite(window, "images/celownik3.png", "y1");
	this->setSprite2(window, "images/spejson.png");
	this->initializeVariables();
}

Player::~Player()
{
	
}

void Player::updateWindowBoundsCollision(sf::RenderTarget& window, std::string _s)
{
	if (_s == "small")
	{
		if (this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width >= window.getSize().x * 0.75) {
			aimVelocity_x = -std::abs(aimVelocity_x);
		}
		else if (this->getSprite().getGlobalBounds().left <= window.getSize().x * 0.25) {
			aimVelocity_x = std::abs(aimVelocity_x);
		}
		if (this->getSprite().getGlobalBounds().top + this->getSprite().getGlobalBounds().height >= window.getSize().y * 0.9) {
			aimVelocity_y = -std::abs(aimVelocity_y);
		}
		else if (this->getSprite().getGlobalBounds().top <= window.getSize().y * 0.3) {
			aimVelocity_y = std::abs(aimVelocity_y);
		}
	}
	else if(_s == "big")
	{
		if (this->sprite2.getGlobalBounds().left <= 0.f)
			this->sprite2.setPosition(0.f, this->sprite2.getGlobalBounds().top);
		if (this->sprite2.getGlobalBounds().left + this->sprite2.getGlobalBounds().width >= window.getSize().x)
			this->sprite2.setPosition(window.getSize().x - this->sprite2.getGlobalBounds().width, this->sprite2.getGlobalBounds().top);

		if (this->sprite2.getGlobalBounds().top <= 0.f)
			this->sprite2.setPosition(this->sprite2.getGlobalBounds().left, 0.f);
		if (this->sprite2.getGlobalBounds().top + this->sprite2.getGlobalBounds().height >= window.getSize().y)
			this->sprite2.setPosition(this->sprite2.getGlobalBounds().left, window.getSize().y - this->sprite2.getGlobalBounds().height);
	}

}

void Player::updateMovement(sf::RenderTarget& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->sprite2.move(-this->movement_speed_x, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->sprite2.move(this->movement_speed_x, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->sprite2.move(0.f, -this->movement_speed_y);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->sprite2.move(0.f, this->movement_speed_y);
	}
}


//Public Functions
void Player::update(sf::RenderTarget& window)
{
	this->updateWindowBoundsCollision(window, "small");
	this->sprite.move(aimVelocity_x, aimVelocity_y);
}

void Player::update2(sf::RenderTarget& window)
{
	this->updateMovement(window);
	this->updateWindowBoundsCollision(window, "big");
}
