
Authors: Jinfeng Chen (c.jinfeng@wustl.edu), Daniel Ryu (r.seunghyeondaniel@wustl.edu), Matthew Kim (mkim25@wustl.edu)

CSE 332S  Lab 4

This program supports two games, Tic-Tac-Toe and Gomoku. 

Users can play Tic-Tac-Toe, Gomoku, or customized Gomoku with appropriate command line arguments:

	"TicTacToe" for the Tic-Tac-Toe game, 
	"Gomoku" for the standard Gomoku game, which has a 19 by 19 gameboard and winning condition of 5 pieces in any directions
	"Gomoku x" for the standard Gomoku game, which has a x by x gameboard and winning condition of 5 pieces in any directions
	"Gomoku x y" for the customized Gomoku game, which has an x by x gameboard and wining condition of y pieces in any directions


Notes:
	Gomoku: Game is a draw when there are less than [winning condition] number of consecutive empty spaces on the board


Return Codes:

	0 - Successful completion of the game
	1 - Fail to extract Coordinates from user input
	2 - Invalid input
	3 - Game quits with user prompt
	4 - Game is draw
	5 - Incorrect usage (incorrect command line input)
	6 - Bad allocation exception from dynamic memory allocation


Work Assignment

	6. Daniel R.
	7. Daniel R.
	8. Jinfeng C. 
	9. Matthew K.
	10.-12. Jinfeng C.
	13.-15. Daniel R.
	16. Jinfeng C.
	17. Daniel R.
	18. Daniel R. Jinfeng C.
	20.-23. Daniel R.
	24. Matthew K. Daniel R.
	25. Matthew k. 
	26. Jinfeng C. Daniel R.
	27. Daniel R.
	-----
	34. Daniel R.
	35. JinFeng C. Daniel R.
	36-38. Daniel R.
	

Errors/Warnings:

	- When the coordinate contained a two digit integer value, its display on the board was relatively more shifted to the right compared to the pieces with single digit
	coordinate value. 

	- The program didnt take into account how the board was set up differently between TicTacToe and Gomoku. In TicTacToe, the x and y axis coordinate label
	begins from 0, while in Gomoku, it begins from 1. Also, coordinate value of 1 was out of bounds in TicTacToe, while in Gomoku, it represented the lowest
	possible value for an inbound coordinate.

	C4267: 'initializing': conversion from 'size_t' to 'int', possible loss of data
		Solved by redeclaring variable as size_t variable
	E0392	member function "TicTacToe::turn" may not be redeclared outside its class	
		Solved by adding a closing bracket to the previous code segment
	
	C26451  Arithmetic overflow: Using operator '+' on a 4 byte value and then casting the result to a 8 byte value. 
			Cast the value to the wider type before calling operator '+' to avoid overflow (io.2).	
		Solved by static_cast to size_t/ add (long) to cast the number bigger
	
	E0020	identifier "playerO" is undefined
		Solved by declaring the member variable and defined it in the constructor body


	C4018	'>': signed/unsigned mismatch
		Solved by changing one variable from int to size_t
