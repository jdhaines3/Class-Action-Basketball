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
	
	//index set to zero
	this->index = 0;
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
	return;
}
	
//Getter and setter for hitChance	
int Player::getHitChance()
{
	return hitChance;
}

void Player::setHitChance(int rnd)
{
	hitChance = rnd;
	return;
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
	index = index + 1;
	
	return;
}

//NEED GET CHAR ACCESSOR IN ORDER TO get the char to which the index is pointing
char Player::getChar(int i)
{
	return score[i];
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
	
	return;
}

//print outcome method
//uses name and shot variables in order to distinguish from seperate instances
void Player::printResult()
{
	std::cout << name << " " << shot << " the shot!" << std::endl;
	//test for getindex
	//std::cout << index << std::endl;
	return;
}