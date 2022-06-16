//BattleshipTest.cpp

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Battleship.hpp"
using namespace std;

 int main() {
    srand(time(NULL));
    Battleship b;
    b.Clear();
    cout << "\nWelcome to simple Battleship!" << endl;
    cout << "There are " << MaxShips << " ships hidden on this 5x5 board." << endl;
    b.Show();
    cout << "The board shows ?'s where no ship is,\n\t  shows *'s when a ship is sunk and\n\t  shows &'s where no ship is found" << endl;
    b.SetShips();
    int pos1, pos2;
    char prompt;
    int numShips = b.NumberOfShips();

    while(1) {
    	cout << "Please enter the location of your guess with a space in between\n(row then column, numbers 0-4 e.g 0 0 is the first square): ";
        //check for length of input to avoid numbers outside the grid
        cin >> pos1 >> pos2;
        while ((pos1 > 9 || pos1 < 0)||(pos2 > 9 || pos2 < 0)) {
            cout << "Enter a valid location between 0 and 9 for both row and column: " << endl;
            cin >> pos1 >> pos2;
        }
        if(b.Attack(pos1,pos2)) {
            cout << "You sunk my battleship!" << endl;
            numShips=numShips-1;
        } else {
            cout << "No ship at this location, try again." << endl;
        }
        b.Show();
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
    b.Show();
    return 0;
}