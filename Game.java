/* Honor Pledge: I pledge that I have neither 
* given nor receieved any help on this assignment.
* Class Madness: A3
* Java Player Class
* David Haines */

//imports for input and output
import java.io.*;
import java.util.Scanner;
//import for random # generator
import java.util.Random;


//--Start Game Class--//
public class Game
{
	//--Main Loop--//
	public static void main(String [] args)
	{
		//keep going for while loop continuation
		int keepGoing = 0;
	
		//start random seed
		Random r = new Random();
	
	
		//--Start Game while loop--//
		while (keepGoing == 0)
		{
			//create two new player instances
			Player p1 = new Player("Player 1");
			Player p2 = new Player("Player 2");
		
			//declare variables for the continue question while loop at end.
			String cont;
			int keepGoing2 = 0;
		
			//call Scanner class to use input in continue while loop
			Scanner input = new Scanner(System.in);
		
		
			//--Start Round while loop--//
			//play rounds until one of the player's index is pointing to "E" in the score array
			while (p1.getIndex() < 5 && p2.getIndex() < 5)
			{
			
				//create two random numbers to use for hitchance check
				int rand1 = r.nextInt((100 - 1) + 1) + 1;
				int rand2 = r.nextInt((100 - 1) + 1) + 1;
			
				//set hitchance to respective rand number
				p1.setHitChance(rand1);
				p2.setHitChance(rand2);
			
				//have each player make a shot
				p1.makeShot();
				p2.makeShot();
			
				//print the results for each player
				p1.printResult();
				p2.printResult();
			
			
				//--Shot Check--//
				//see if either player gained a letter
				if (p1.getShot() == "HIT" && p2.getShot() == "MISSED") 
				{
					p2.gainLetter();
				
					//print the letter they just got
					System.out.println("Player 2 gained an " + p2.getChar(p2.getIndex()) + "!");
				} 
				else if (p1.getShot() == "MISSED" && p2.getShot() == "HIT")
				{
					p1.gainLetter();
					System.out.println("Player 1 gained an " + p1.getChar(p1.getIndex()) + "!");
				} 
				//if both players Hit or both missed, then next round plays without anything printing/happening
			}
		
		
			//--After Rounds have ended--//
		
			//print out who won (player who's index isn't 5)
			if (p1.getIndex() == 5) 
			{
				System.out.println("Player 1 has HORSE. Player 2 has won the game!");
			} 
			else if (p1.getIndex() == 5) 
			{
				System.out.println("Player 2 has HORSE. Player 1 has won the game!");
			}
		
		
			//--Ask User if they would like to play again--//
			//while loop for continue question
			while (keepGoing2 == 0) 
			{
				//ask user if they want to play again and get input
				System.out.println("Do you wish to play again? (Y|N)");
				cont = input.next();

				//if loop to determine what to do from how user answers
				
				//if yes, exit question loop and restart game loop
				if (cont.equals("Y")) // can't use normal boolean for java strings
				{
					keepGoing2 = 1;
				} //if no, exit question loop and game loop, as well as clear instances
				else if (cont.equals("N"))   
				{
					keepGoing2 = 1;
					keepGoing = 1;
				} //if neither, ask again
				else 
				{
					System.out.println("I'm not sure what you were trying to do. Please type only 'Y' or 'N'.");
				}
				//nothing needs deleted specifically called in Java
			}
		}
		//exit message
		System.out.println("Thank you for playing!");
	}
}