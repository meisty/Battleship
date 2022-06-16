//Battleship.cpp
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Battleship.hpp"
using namespace std;

const int rows = 5;
const int cols = 5;

int matrix[rows][cols];

//Set the board
void Battleship::Clear(){
    for(int i=0; i<rows; i++) {
        for(int j=0; j< cols; j++) {
            matrix[i][j] = 0;        
        }
    }
}

//display
//show ? if unchecked spot
//show * if sunk ship 
//show & if spot checked and no ship
void Battleship::Show(){
    cout << "~~~~~~~~~~" << endl;
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
    cout << "~~~~~~~~~~" << endl;
}
void Battleship::SetShips() {
    int s = 0;
    while (s < MaxShips) {
        int x = rand() % rows;
        int y = rand() % cols;
        if (matrix[x][y]!=1){
            s++;
            matrix[x][y]=1;
        }
    }
}

int Battleship::NumberOfShips(){
    int n=0;
    for(int i=0;i<rows;i++){
        for (int j=0; j<cols; j++) {
            if (matrix[i][j]==1) {
                n++;
            }
        }
    }
    return n;
}

//to do: add in check if coordinate has already been input
bool Battleship::Attack(int x, int y){
    if (matrix[x][y]== 1) {
        matrix[x][y] = 2;
        return true;
    } else {
    	matrix[x][y] = 3;
    	return false;
    }
    return false;
}