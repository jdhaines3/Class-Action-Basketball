#Honor Pledge: I pledge that I have neither 
#given nor receieved any help on this assignment.
#Class Madness: A3
#C++ Make File
#David Haines

ClassMadness.exe: Player.o game.o
	g++ Player.o game.o -o ClassMadness.exe

Player.o: Player.cpp
	g++ -c Player.cpp

game.o: game.cpp
	g++ -c game.cpp

clean:
	rm -f *.o
	rm ClassMadness