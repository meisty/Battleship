//Battleship.hpp 

#pragma once	//protect the file from being included more than once and have a name ambiguity problem
				//With modern compilers it's possible to convert the include guards to #pragma once.

// data structure definitions
const int MaxShips = 3;

class Battleship {
	public: 
		void Clear();
		void Show();
		void SetShips();
		int NumberOfShips();
		bool Attack(int x, int y);
		//Constructor
		Battleship(){};
};