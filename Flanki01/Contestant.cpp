#include "Contestant.h"


/////////////////////////////////////////////////Contestant////////////////////////////


const sf::Sprite Contestant::getSprite() const
{
	return sprite;
}



/////////////////////////////////////////////////////Enemy////////////////////////////////////////////////////////////////

//Private Functions
void Enemy::initializeSprite(sf::RenderTarget& window)
{
	//Loads basic texture and sprite
	try
	{
		if (this->texture.loadFromFile("images/Pudzian_przeciwnik.png"))
		{
			this->sprite.setTexture(texture);
			this->sprite.setScale(0.5f, 0.5f);
			this->sprite.setPosition(
				static_cast<float>(static_cast<int>(window.getSize().x - this->texture.getSize().x) * 0.625f),
				static_cast<float>(static_cast<int>(window.getSize().y - this->texture.getSize().y) * 0.667f)
			);
		}
		else
		{
			throw(1);
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
		std::cout << "Nie zaladowano enemy \n";
	}
}

void Enemy::initializeVariables()
{
	//Intializes basics

}

//Constructors and Destructors
Enemy::Enemy(sf::RenderTarget& window)
{
	this->initializeSprite(window);
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




/////////////////////////////////////////////////////Player////////////////////////////////////////////////////////////////

//Private Functions
void Player::initializeSprite(sf::RenderTarget& window)
{
	//Loads basic texture and sprite (For now. We will change it to loat given texture)
	//Próbowa³em, ¿eby wszystko ³adowa³o siê w jedn¹ teksturê i jednego sprita, zobaczê jak to dzia³a i czy dzia³a
	//Edit* Póki celownik siê nie rusza - dzia³a, wyœwietla pudziana i celownik, jest git
	//Edit** Póki co dzia³a ruszaj¹cy siê celownik i pudzian stoj¹cy - jest git
	try
	{
		if (this->texture.loadFromFile("images/celownik3.png"))
		{
			this->sprite.setTexture(texture);
			this->sprite.setScale(0.5f, 0.5f);
			this->sprite.setPosition(
				static_cast<float>(static_cast<int>(window.getSize().x) * 0.5f),
				static_cast<float>(static_cast<int>(window.getSize().y) * 0.5f)
			);
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
	this->initializeSprite(window);
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








////Private Functions
//void Contestant::initializeVariables()
//{
//	this->name = "";
//	this->drinkingSpeed = 0.f;
//	this->runningSpeed = 0.f;
//	this->accuracy = 0;
//}
//
////void Contestant::initializeTexture()
////{
////
////}
//
////Constructors and Destructors
//Contestant::Contestant(std::string n, float dS, float rS, int a) : name(n), drinkingSpeed(dS), runningSpeed(rS), accuracy(a)
//{
//	this->initializeVariables();
//}
//
//Contestant::~Contestant()
//{
//
//}
//
//
//
////Class Enemy
//Enemy::Enemy(std::string n, float dS, float rS, int a, int diL, sf::RenderWindow* window) : Contestant(n, dS, rS, a), difficultyLevel(diL)
//{
//	this->setTexture(window);
//}
//
//
//Enemy::~Enemy()
//{
//	//?
//}
//
////
//void Enemy::setTexture(sf::RenderWindow* window)
//{
//	try
//	{
//		if (this->texture.loadFromFile("images/Pudzian_przeciwnik.png"))
//		{
//			this->sprite.setTexture(texture);
//			this->sprite.setScale(0.2f, 0.2f);
//			this->sprite.setPosition(
//				static_cast<float>(/*rand() % */static_cast<int>(window->getSize().x - this->texture.getSize().x) / 1.15f),
//				static_cast<float>(/*rand() % */static_cast<int>(window->getSize().y - this->texture.getSize().y) / 1.4f)
//			);
//		}
//		else
//		{
//			throw(1);
//		}
//	}
//	catch (Exception^ ex)
//	{
//		MessageBox::Show(ex->Message);
//		std::cout << "Nie zaladowano enemy \n";
//	}
//}
//
//void Enemy::render(sf::RenderTarget& target)
//{
//	target.draw(this->sprite);
//}
//
//
////Class Player
//Player::Player(std::string n, float dS, float rS, int a, int duL) : Contestant(n, dS, rS, a), drunkLevel(duL)
//{
//
//}
//
//Player::~Player()
//{
//
//}
//
//void Player::setTexture(sf::RenderWindow* window)
//{
//
//}
//
//void Player::render(sf::RenderTarget& target)
//{
//	//target.draw(this->sprite);
//}

