/*
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

*/
#define Length 150 

#include <iostream>
#include <time.h>
using namespace std;
//the field
//		ARR[X][Y]
bool Field[Length][Length];
//first clear the field
void clearField();
void setRandoms();
void show();
void play();
void wait();

//
int main(){
    clearField();
    setRandoms();
    int limit=100000;
	show();
    for (int i=0; i<limit;i++){
		system("clear");
		play();
		show();
		wait();
	}
}

void clearField(){
	for(int i=0; i<Length; i++){
		for(int j=0; j<Length; j++){
			Field[i][j]=false;
		}
	}
}

void setRandoms(){
	for(int i=0; i<Length; i++){
		for(int j=0; j<Length; j++){
			int rando=0;
			rando= rand() % 100;
			if (rando>100){
				Field [i][j]=true;
			}
		}
	}
}

void show(){
	for(int i=0; i<Length; i++){
		for(int j=0; j<Length; j++){
			if (Field[i][j]){
				cout << "*";
			}else{
				cout << " ";
			}
		}
		cout << "\n";
	}
}
//delay some time so game can print
void wait(){
	clock_t t;
	t = clock();
	clock_t time = 1000000;
	clock_t elapsed = clock() - t;
	//
	while(elapsed<time){
		elapsed = clock() - t;
	}//nothing just wait
}

void play(){
	for(int i=0; i<Length; i++){
		//cout << i /10 ;
		for(int j=0; j<Length; j++){
			//cout << j /10;

		//at each array location
		// _______________
		// |    |    |    | 
		// | 1  | 2  | 3  |
		// ---------------|
		// |    |arr |    | 
		// | 4  |spa9| 5  |
		// ---------------|
		// |    |    |    | 
		// | 6  | 7  |  8 |
		// _______________|
		//search all spaces and refrence a bool array
		//use bool array to map and output new life 



		//init that array to false
		int c=0;
		//space number 1
		if (Field[i-1][j+1]){
			c++;
		}
		//space 2
		if (Field[i][j+1]){
			c++;
		}
		//space 3
		if (Field[i+1][j+1]){
			c++;
		}
		//space 4
		if (Field[i-1][j]){
			c++; 
		}
		//space 5
		if (Field[i+1][j]){
			c++;
		}
		//space 6
		if (Field[i-1][j-1]){
			c++;
		}
		//space 7
		if (Field[i][j-1]){
			c++; 
		}
		//space 8
		if (Field[i+1][j-1]){
			c++;
		}
		//space 9
		if(Field[i][j]){
			c++;
		}
		//

		//now make it alive if it is dead and has 3 neighbors
		if ((Field[i][j]==0)&&((c==3)||(c==2))){
			Field[i][j]=true;
		}

		//now kill the life if there is too many or too little
		if ((c>3)||(c<2)){
			Field[i][j]=false;
		}
		c=0;
		//checking for line in X
		for (int r =-2; r<2;r++){
			if (Field[i+r][j]){
				c++;
			}
		}
		if (c>3){
			Field[i][j]=false;
		}
		c=0;

		for (int r =-2; r<2;r++){
			if (Field[i][j+r]){
				c++;
			}
		}
		if (c>3){
			Field[i][j]=false;
		}
	}
}

}