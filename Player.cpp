/* Honor Pledge: I pledge that I have neither 
 given nor receieved any help on this assignment.
 Class Madness: A3
 C++ Player File
 David Haines */

#include "Player.h"
#include <iostream>
#include <string>

//--Constructors--//
//every constructor, deconstructor, access, or member method must have namespace of Player

//default constructor
Player::Player()
{
	//fill score with Horse (and throwaway char at score[0] as starting point)
	//fill everything else with null or zero values
	this->score[6] = {'A', 'H', 'O', 'R', 'S', 'E'};
	this->hitChance = 0;
	
	this->name = "";
	this->shot = "";
	
	//set ptrIndex to address of index (and value of zero)
	this->index = 0;
	this->ptrIndex = &index;
}

//Constructor
Player::Player(std::string n)
{
	//all same null or zero values except name
	this->score[6] = {'A', 'H', 'O', 'R', 'S', 'E'};
	this->hitChance = 0;
	
	this->name = n;
	this->shot = "";
	
	this->index = 0;
	this->ptrIndex = &index;
}

//--Deconstructor--//
Player::~Player()
{
	std::cout << "Destroying classes!" << std::endl;
}

//--Access Methods--//

//Getter and setter for "Shot"
std::string Player::getShot()
{
	return shot;
}

void Player::setShot(std::string s)
{
	shot = s;
	return 0;
}
	
//Getter and setter for hitChance	
int Player::getHitChance()
{
	return hitChance;
}

void Player::setHitChance(int rnd)
{
	hitChance = rnd;
	return 0;
}

//get and set methods for index
int Player::getIndex()
{
	return index;
}

//set index is only used for incrementing the index by one when a player receives a letter
//so takes no arguments
void Player::gainLetter()
{
	(*ptrIndex) = (*ptrIndex) + 1;
	return 0;
}
		
		
//--Member Methods--//

/*make shot method uses the random # passed from the game file and checks it against the player's
make percentage, then set's shot to "missed" or "hit"*/
void Player::makeShot()
{
	if ( hitChance >= 1 && hitChance <= 50) {
		shot = "MISSED";
	} else if ( hitChance >= 51 && hitChance <= 100) {
		shot = "HIT";
	}
	
	return 0;
}

//print outcome method
//uses name and shot variables in order to distinguish from seperate instances
void Player::printResult()
{
	std::cout << name << " " << shot << " the shot!" << std::endl;
