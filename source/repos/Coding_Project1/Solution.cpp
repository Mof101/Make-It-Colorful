#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

// Function to set console text color
void SetColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

int main() {
	// This will create a seed based on current time
	unsigned seed;
	seed = time(0);
	srand(seed);

	// Stores the variables for each player's dice rolls
	int dice_roll_p1, dice_roll_p2;

	// Stores the maximum and minimum rolls for the dice in constant variables
	const int MAX_ROLL = 20,
		MIN_ROLL = 1;

	// Stores the names of players in variables
	string player1, player2;
	cout << "Please enter the name of player 1: ";
	getline(cin, player1);
	cout << "Please enter the name of player 2: ";
	getline(cin, player2);

	// Uses random number generation with a formula to keep the number at 20 or below
	dice_roll_p1 = rand() % MAX_ROLL + 1;
	dice_roll_p2 = rand() % MAX_ROLL + 1;

	// Gives the number generated for each player
	cout << player1 << " has rolled a " << dice_roll_p1 << endl;
	cout << player2 << " has rolled a " << dice_roll_p2 << endl;

	// These conditions will output who won and who had critical success and failure
	if (dice_roll_p1 == MAX_ROLL && dice_roll_p2 == MAX_ROLL) {
		SetColor(10);  // Green for critical success
		cout << "Both players have rolled evenly with critical success!" << endl;
		SetColor(7);   // Reset to default color
	}
	else if (dice_roll_p1 == MAX_ROLL) {
		SetColor(10);  // Green for critical success
		cout << player1 << " has rolled with critical success!" << endl;
		SetColor(7);   // Reset to default color
	}
	else if (dice_roll_p1 == MIN_ROLL) {
		SetColor(12);  // Red for critical failure
		cout << player1 << " has rolled with critical failure!" << endl;
		SetColor(7);   // Reset to default color
	}
	else if (dice_roll_p2 == MAX_ROLL) {
		SetColor(10);  // Green for critical success
		cout << player2 << " has rolled with critical success!" << endl;
		SetColor(7);   // Reset to default color
	}
	else if (dice_roll_p2 == MIN_ROLL) {
		SetColor(12);  // Red for critical failure
		cout << player2 << " has rolled with critical failure!" << endl;
		SetColor(7);   // Reset to default color
	}
	else if (dice_roll_p1 == MIN_ROLL && dice_roll_p2 == MIN_ROLL) {
		SetColor(12);  // Red for critical failure
		cout << "Both players have rolled poorly..... critical failure!" << endl;
		SetColor(7);   // Reset to default color
	}
	else if (dice_roll_p1 > dice_roll_p2) {
		cout << player1 << " wins!" << endl;
	}
	else if (dice_roll_p1 < dice_roll_p2) {
		cout << player2 << " wins!" << endl;
	}
	else {
		cout << player1 << " and " << player2 << " are evenly matched!" << endl;
	}

	cout << "Thank you for playing!" << endl;

	return 0;
}
