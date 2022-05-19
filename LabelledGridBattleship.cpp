//rework of simple battleship singleplayer implementation from unlabelled grid of 0's to labelled grid B-J 1-9

#include<iostream> 
#include<cstdlib> 
#include<ctime> 
#include<string> 
#include<stdio.h> 
using namespace std; 

//10x10 grid
const int ROWS=10; 
const int COLUMNS=10; 
int MaxShips = 3;

int computer = 0;
int player = 0;

bool run;
int num, nfl;
char xinput, prompt;
int yinput;

char board[ROWS][COLUMNS]={' ','1','2','3','4','5','6','7','8','9','B','.','.','.','.','.','.','.','.','.', 
'C','.','.','.','.','.','.','.','.','.','D','.','.','.','.','.','.','.','.','.', 
'E','.','.','.','.','.','.','.','.','.','F','.','.','.','.','.','.','.','.','.', 
'G','.','.','.','.','.','.','.','.','.','H','.','.','.','.','.','.','.','.','.', 
'I','.','.','.','.','.','.','.','.','.','J','.','.','.','.','.','.','.','.','.'};

// set all board items to one object
void Clear(){
	for (int i=0;i<ROWS;i++) {
		for (int j=0; j<COLUMNS; j++) {
			if (board[i][j] == '.') {
				board[i][j] = 0;
			}
		}
	}
}

//hide ships on the board and display board
void Map(){
	for (int i=0;i<ROWS;i++) {
		for (int j=0; j<COLUMNS; j++) {
			if (board[i][j]=='$') {
				cout << '.';
			} else {
				cout << board[i][j];
			}
		}
		cout << endl;
	}
}

//convert letters to numbers
//1 not included because first row and column are labels and should not be manipulated
int NumberFromLetter(char input1) {
	switch (input1) {
	    case 'B': case 'b':
	        num = 1;
	        break;
	    case 'C': case 'c':
	        num = 2;
	        break;
	    case 'D': case 'd':
	        num = 3;
	        break;
	    case 'E': case 'e':
	        num = 4;
	        break;
	    case 'F': case 'f':
	        num = 5;
	        break;
	    case 'G': case 'g':
	        num = 6;
	        break;
	    case 'H': case 'h':
	    	num = 7;
	        break;
	    case 'I': case 'i':
	        num = 8;
	        break;
	    case 'J': case 'j':
	        num = 9;
	        break;
	    default:
	        printf("Choice outside range");
	        break;
	    }
    return num;
}

//randomly set MaxShips number of enemy ships on the board
void SetShips() {
	int s = 0;
	while (s < MaxShips) {
		int r1 = rand() % (ROWS-1) + 1;
		int r2 = rand() % (COLUMNS-1) + 1;
		if (board[r1][r2]!='$') {
			s++;
			board[r1][r2]='$';
		}
	}
}


//to do: add in check if coordinate has already been input
bool Attack(char pos1, int pos2){
    if (board[pos1][pos2]=='$') {
    	board[pos1][pos2]='*';
    	return true;
    } else {
    	board[pos1][pos2]='&';
    }
    return false;
}

int main() {
	run = false;
	srand(time(NULL));
	cout << "----------Welcome to Battleship----------" << endl;
    cout << "The board shows ?'s where no ship is,\n\t  shows *'s when a ship is sunk and\n\t  shows &'s where no ship is found" << endl;
	cout << "------------------------------------------" << endl;
	Map();
	SetShips();
	int numShips = MaxShips;
	
	while (!run) {
		cout << "Enter coordinates of guess: ";
		cin >> xinput >> yinput;
		nfl = NumberFromLetter(xinput);
		//variable nfl is number converted from x axis letter
		//cout << "Trying " << nfl << "," << yinput << endl;
		
		//make sure values are within range 
		if ((nfl > 0 && nfl <= 9) && (yinput > 0 && yinput <= 9)) {
			if (Attack(nfl,yinput)) {
				cout << "*****You sunk my battleship!*****" << endl;
				numShips--;
			} else {
				cout << "No ship at this location, try again." << endl;
			}
		} else {
			cout << "INVALID COORDINATES! Enter coordinates between B-J 1-9:";
			cin >> xinput >> yinput;
		}
		Map();
		cout << "Number of ships remaining: " <<  numShips << endl;
        if (numShips == 0) {
        	cout << "You sunk all the ships!" << endl;
            break;
        }
		cout << "Do you want to surrender (y/n)? ";
        cin >> prompt;
        if (prompt == 'y') {
            break;
        }  
	}
	cout << "Game Over!" << endl;
    Map();
    return 0;
}
