#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

const int rows = 5;
const int cols = 5;
int MaxShips = 3;

int matrix[rows][cols];

void Clear()
{    
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

//show ? if unchecked spot
//show * if sunk ship 
//show & if spot checked and no ship
void Show(){
    for(int i=0; i<rows; i++) {
        for(int j=0; j< cols; j++) {
        	if ((matrix[i][j] == 0) || (matrix[i][j] == 1)) {
        		cout << '?' << " "; 
        	} else if (matrix[i][j] == 2) {
        		cout << '*' << " ";
        	} else {
        		cout << '&' << " ";
        	}
    	}
        cout << endl;
    }
}

void SetShips()
{
    int s = 0;
    while(s < MaxShips)
    {
        int x = rand() % rows;
        int y = rand() % cols;
        if(matrix[x][y] != 1)
        {
            s++;
            matrix[x][y] = 1;
        }
    }
}

int NumberOfShips()
{
    int c=0;
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)
        {
            if(matrix[i][j] == 1)
            {
                c++;
            }
        }
    }
    
    return c;
}

//to do: add in check if coordinate has already been input
bool Attack(int x, int y){
    if (matrix[x][y]== 1) {
        matrix[x][y] = 2;
        return true;
    } else {
    	matrix[x][y] = 3;
    	return false;
    }
    return false;
}

int main()
{
    srand(time(NULL));
    
    Clear();
    cout << "\nWelcome to simple Battleship!" << endl;
    cout << "There are " << MaxShips << " ships hidden on this 5x5 board." << endl;
    Show();
    cout << "The board shows ?'s where no ship is,\n\t  shows *'s when a ship is sunk and\n\t  shows &'s where no ship is found" << endl;
    SetShips();
    int pos1, pos2;
    char prompt;
    int numShips = NumberOfShips();

    while(1) {
    	cout << "Please enter the location of your guess\n(row then column, numbers 0-4 e.g 0 0 is the first square): ";
        //check for length of input to avoid numbers outside the grid
        cin >> pos1 >> pos2;
        if(Attack(pos1,pos2)) {
            cout << "You sunk my battleship!" << endl;
            numShips=numShips-1;
        } else {
            cout << "No ship at this location, try again." << endl;
        }
        Show();
        cout << "Number of ships remaining: " <<  numShips << endl;
        if (numShips == 0) {
        	cout << "You sunk all the ships!" << endl;
            break;
        }
        cout << "Do you want to surrender (y/n)?" << endl;
        cin >> prompt;
        if (prompt == 'y') {
            break;
        }  
    }
    cout << "Game Over!" << endl;
    Show();
    
    return 0;
}
