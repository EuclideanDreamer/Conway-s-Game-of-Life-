# Conway-s-Game-of-Life-
Implemented by Bailey Nichols in C++


Bailey Nichols 10/20/2021

Game of life time baby ohh yeah 

rules from Wikipedia the free encyclopedia 
https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life :
"The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead, (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

    Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    Any live cell with two or three live neighbours lives on to the next generation.
    Any live cell with more than three live neighbours dies, as if by overpopulation.
    Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
"


for our purposes we can just say each array position is a space, and we will show the 'board' in 2D


//at each array location
		// _______________
		// |    |    |    | 
		// | 1  | 2  | 3  |
		// ---------------|
		// |    |arr |    | 
		// | 4  |spac| 5  |
		// ---------------|
		// |    |    |    | 
		// | 6  | 7  |  8 |
		// _______________|
		//search all spaces 
		//use array to output new life 


	as a note windows users will need to change the sys("clear"); to whatever those unfortunate types would use 


I think this works
