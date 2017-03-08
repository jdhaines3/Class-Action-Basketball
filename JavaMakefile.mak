# Honor Pledge: I pledge that I have neither 
# given nor receieved any help on this assignment.
# Class Madness: A3
# Java Makefile
# David Haines

Game.class: Game.java
	javac Game.java
	
Player.class: Player.java
	javac Player.java
	
clean:
	rm *.class