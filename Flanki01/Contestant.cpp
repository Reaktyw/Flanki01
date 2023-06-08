#include "Contestant.h"


//////////////////////////////////////////Contestant//////////////////////////////////


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
	return sprite;
}

const sf::Sprite Contestant::getSprite2() const
{
	return sprite2;
}

float Contestant::getMovementSpeed_x()
{
	return this->movement_speed_x;
}

float Contestant::getMovementSpeed_y()
{
	return this->movement_speed_y;
}

void Contestant::setCanEmptiness(float _elapsed)
{
	this->canEmptiness = this->canEmptiness - _elapsed;
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


void Enemy::setSprite(sf::RenderTarget& window, std::string _s)
{
	//Loads basic texture and sprite
	this->setTexture(_s);
	this->sprite.setScale(0.5f, 0.5f);
	this->sprite.setPosition(
		static_cast<float>(static_cast<int>(window.getSize().x - this->texture.getSize().x) * 0.625f),
		static_cast<float>(static_cast<int>(window.getSize().y - this->texture.getSize().y) * 0.667f)
	);
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

void Enemy::initializeVariables()
{
	//Intializes basics
	this->drinkingSpeed = 10.f;
	this->movement_speed_x = 10.f;
	this->movement_speed_y = 10.f;
}

//Constructors and Destructors
Enemy::Enemy(sf::RenderTarget& window)
{
	this->setSprite(window, "images/Pudzian_przeciwnik.png");
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


void Player::setSprite(sf::RenderTarget& window, std::string _s)
{
	//Loads basic texture and sprite (For now. We will change it to load given texture)
	//Próbowa³em, ¿eby wszystko ³adowa³o siê w jedn¹ teksturê i jednego sprita, zobaczê jak to dzia³a i czy dzia³a

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

void Player::initializeVariables()
{
	//Intializes basics
	this->aimVelocity_x = 10.f;
	this->aimVelocity_y = 8.f;
	this->points = 0;
	this->drinkingSpeed = 10.f;
	this->movement_speed_x = 10.f;
	this->movement_speed_y = 10.f;
}




//Constructors and Destructors
Player::Player(sf::RenderTarget& window)
{
	this->setSprite(window, "images/celownik3.png");
	this->setSprite2(window, "images/player.png");
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

void Player::setDrinkingSpeed(float _d)
{
	this->drinkingSpeed = this->drinkingSpeed + _d;
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
