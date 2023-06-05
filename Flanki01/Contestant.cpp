#include "Contestant.h"


//////////////////////////////////////////Contestant//////////////////////////////////


void Contestant::setTexture(sf::RenderTarget& window, std::string _s)
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

const sf::Sprite Contestant::getSprite() const
{
	return sprite;
}




///////////////////////////////////////////Enemy/////////////////////////////////////////////

//Private Functions

void Enemy::setSprite(sf::RenderTarget& window, std::string _s)
{
	//Loads basic texture and sprite
	this->setTexture(window, _s);
	this->sprite.setScale(0.5f, 0.5f);
	this->sprite.setPosition(
		static_cast<float>(static_cast<int>(window.getSize().x - this->texture.getSize().x) * 0.625f),
		static_cast<float>(static_cast<int>(window.getSize().y - this->texture.getSize().y) * 0.667f)
	);
}

void Enemy::initializeVariables()
{
	//Intializes basics
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

void Enemy::render(sf::RenderTarget& window)
{
	window.draw(this->sprite);
}




///////////////////////////////////////////Player///////////////////////////////////////////////

//Private Functions


void Player::setSprite(sf::RenderTarget& window, std::string _s)
{
	//Loads basic texture and sprite (For now. We will change it to load given texture)
	//Próbowa³em, ¿eby wszystko ³adowa³o siê w jedn¹ teksturê i jednego sprita, zobaczê jak to dzia³a i czy dzia³a

	this->setTexture(window, _s);
	this->sprite.setScale(0.5f, 0.5f);
	this->sprite.setPosition(
		static_cast<float>(static_cast<int>(window.getSize().x) * 0.5f),
		static_cast<float>(static_cast<int>(window.getSize().y) * 0.5f)
	);
}

void Player::initializeVariables()
{
	//Intializes basics
	this->aimVelocity_x = 5.f;
	this->aimVelocity_y = 5.f;
	this->points = 0;
}




//Constructors and Destructors
Player::Player(sf::RenderTarget& window)
{
	this->setSprite(window, "images/celownik3.png");
	this->initializeVariables();

}

Player::~Player()
{

}


void Player::updateWindowBoundsCollision(sf::RenderTarget& window)
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

const sf::Sprite Player::getSprite() const
{
	return this->sprite;
}


//Public Functions
void Player::update(sf::RenderTarget& window)
{
	this->updateWindowBoundsCollision(window);
	this->sprite.move(aimVelocity_x, aimVelocity_y);
}

void Player::render(sf::RenderTarget& window)
{
	window.draw(this->sprite);
}


