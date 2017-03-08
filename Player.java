/* Honor Pledge: I pledge that I have neither 
* given nor receieved any help on this assignment.
* Class Madness: A3
* Java Player Class
* David Haines */

//imports: just standard io lib
import java.io * 

//--Start Player class--//
public class Player
{
	//list attributes all set to private: name, hitchance, shot, horse array, index
	private int hitChance, index;
	private char[] score = {'A', 'H', 'O', 'R', 'S', 'E'};  //initialize score array
	private String name, shot;
	
	
	//--Default Constructor--//
	public Player()
	{
		//set everything to zero/Null
		this.hitChance = 0;
		this.score = score;
		this.index = 0;
		this.name = "";
		this.shot = "";
	}
	
	
	//--Constructor--//
	public Player(String n)
	{
		
		//set everything except name to zero/Null
		this.hitChance = 0;
		this.score = score;
		this.index = 0;
		this.shot = "";
		//set name to passed string
		this.name = n;
	}
	
	//no deconstructor needed
	
	
	//--Access Methods--//
	
	//Getter and setter for 'shot' variable
		//getter for 'hitChance' and setter for 'shot' not used, but included because their opposite access method is
	String getShot()
	{
		return shot;
	}
	
	void setShot(String s)
	{
		shot = s;
		return;
	}
	
	//Getter and Setter for hitChance
	int getHitChance()
	{
		return hitChance;
	}
	
	void setHitChance(int rnd)  //takes in random number generated by 'game'
	{
		hitChance = rnd;
		return;
	}
	
	//getter and "setter" for score index; setter just increments index by 1
	int getIndex()
	{
		return index;
	}
	
	void gainLetter()	//takes no arguments due to just incrementing index by 1
	{
		index = index + 1;
		return;
	}
	
	//need get char to get the letter to which index is pointing
	char getChar(i)
	{
		return score[i];
	}
	
	
	//--Member Methods--//
	
	/*makeShot uses the rand # passed from game and runs it through if statement for check against hit %
	*then sets shot to hit or missed*/ 
	void makeShot()
	{
		if (hitChance >= 1 && hitChance <= 50)	//50% hit chance
		{
			shot = "MISSED";
		}
		else if (hitChance >= 51 && hitChance <= 100)
		{
			shot = "HIT";
		}
		
		return;
	}
	
	//prints the results using name and shot variables
	void printResult()
	{
		System.out.println(name + " " + shot + " the shot!");
		//could also use: System.out.format("%s %s the shot!%n", name, shot)
		return;
	}
}

/*maybe add restraints in getters and setters, such that if hitChance < 1 or > 100 set to 1 or 100 respectively
or make sure index doesn't go over 5, although it shouldn't be needed*/
		