/* Honor Pledge: I pledge that I have neither 
 given nor receieved any help on this assignment.
 Class Madness: A3
 C++ Header file
 David Haines */
 
 //Header Guard
#ifndef PLAYER_H
#define PLAYER_H

//include string for name and shot
#include <string>

//--Header file for Player class--//
class Player
{
	//--Private member variables--//
	private:
	
		/*player will have name, a %to hit chance, a char array for HORSE, 
		and a variable to keep track of if they made a basket*/
		char score[6];
		int hitChance;
		std::string name;
		std::string shot;
		//index will be used to call score[index] char
		int index;
		
	//--Public Methods, Constructors, Access Methods, Deconstructors--//
	public:
		
		//--Constructors--//
		Player();
		Player(std::string name);  //initialize player with a name to avoid access method
		
		//--Destructors--//
		~Player();
		
		
		//--Access Methods--//
		//need getters and setters to access private variables
		
		/*set shot and get hitChance won't be used by game file, but included because their opposite
		getter/setter will be*/
		std::string getShot();
		void setShot(std::string s);
		
		int getHitChance();
		void setHitChance(int rnd);
		
		//will get value at pointer, set will increment ptr by one
		int getIndex();
		void gainLetter();
		
		//uses to find which char the index is pointing to
		char getChar(int i);
		
		//--Member Methods--//
		//determines if player hits or misses shot, sets shot
		void makeShot();
		
		//prints outcome
		void printResult();
		
};

#endif
		