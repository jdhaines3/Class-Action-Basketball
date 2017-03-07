/* Honor Pledge: I pledge that I have neither 
 given nor receieved any help on this assignment.
 Class Madness: A3
C++ game file
 David Haines */

//--includes--//
 
#include "Player.h"
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>

//--Game main function--//
int main()
{
	//declare variable needed for game while loop to continue
	int keepGoing = 0;
	
	//create seed for random # gen
	srand(time(NULL));
	
	//game while loop -- for if user wants to play another game at end
	while (keepGoing == 0) {
		
		//create two instances/objects of Player on heap
		Player * P1 = new Player("Player 1");
		Player * P2 = new Player("Player 2");
		
		//declare char array size of one for Y|N while loop to continue at end
		std::string cont = "";
		int keepGoing2 = 0;
		
		//new while loop for each round; continue until one object's char index = 5
		while (P1->getIndex() <= 5 || P2->getIndex() <= 5) {
			
			//declare variables for while loop: 2 variables to store random numbers for hitChance
			int randP1 = rand() % 100 + 1;
			int randP2 = rand() % 100 + 1;
		
			//set hitchance to respective rand number
			P1->setHitChance(randP1);
			P2->setHitChance(randP2);
			
			//have each player make a shot
			P1->makeShot();
			P2->makeShot();
			
			//print the results for each player
			P1->printResult();
			P2->printResult();
			
			//determine if anybody earned a letter; compare shot strings for both players
			if (P1->getShot() == "HIT" && P2->getShot() == "MISSED") {
				P2->gainLetter();
				//print the letter they just got
				std::cout << "Player 2 gained an " << P2->getChar(P2->getIndex()) << "!" << std::endl;
			} else if (P1->getShot() == "MISSED" && P2->getShot() == "HIT") {
				P1->gainLetter();
				std::cout << "Player 1 gained an " << P1->getChar(P1->getIndex()) << "!" << std::endl;
			}
		}
		
		
		//print out who won
		if (P1->getIndex() == 5) {
			std::cout << "Player 1 has HORSE. Player 2 has won the game!" << std::endl;
		} else if (P2->getIndex() == 5) {
			std::cout << "Player 2 has HORSE. Player 1 has won the game!" << std::endl;
		}
		
		
		//while loop for continue question
		while (keepGoing2 == 0) {
			//ask user if they want to play again and get input
			std::cout << "Do you wish to play again? (Y|N)" << std::endl;
			std::cin >> cont;
			
			//if loop to determine what to do from how user answers
			//if yes, exit question loop and restart game loop, clear instances
			if (cont == "Y") {
				keepGoing2 = 1;
				delete P1;
				delete P2;
			//if no, exit question loop and game loop, as well as clear instances
			} else if (cont == "N") {
				keepGoing2 = 1;
				keepGoing = 1;
				delete P1;
				delete P2;
			//if neither, ask again
			} else {
				std::cout << "I'm not sure what you were trying to do. Please type only 'Y' or 'N'." << std::endl;
			}
		}
	}
	
	std::cout << "Thank you for playing!" << std::endl;
	
	return 0;
		
}
	