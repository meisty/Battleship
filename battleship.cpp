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

void Show()
{
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
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

bool Attack(int x, int y)
{
    if(matrix[x][y] == 1)
    {
        matrix[x][y] = 2;
        return true;
    }    
    
}

int main()
{
    srand(time(NULL));
    
    Clear();
    cout << "Welcome to this simple game of battleships.  " << endl;
    cout << "The computer has hidden 3 ships on a 5 x 5 board \n";
    Show();
    cout << "The board shows 0's where no ship is, the computer will hide the ships and they will show as 1's and when sunk 2's. " << endl;
    cout << "-------------------------------- Randomly hiding ships --------------------------------" << endl;
    SetShips();
    int pos1,pos2;
    
    char prompt;
    
    
    
    while(1)
    {

        cout << "Please enter the location of your guess (row then column, numbers 0-4 e.g 0 0 is the first square): ";
        cin >> pos1 >> pos2;
        if(Attack(pos1,pos2))
        {
            cout << "You sunk my Battleship!" << endl;
        }else{
            cout << "Sorry there is no ship at this location, please try again" << endl;
        }
        cout << "Number of ships remaining: " << NumberOfShips() << endl;
        if (NumberOfShips() == 0){
            break;
        }
        cout << "Do you want to surrender (y/n)? ";
        cin >> prompt;
        if(prompt == 'y')
        {
            break;
        }
        

    }
    
    cout << "Game over!" << endl;
    Show();
    
    
    
    return 0;
}