#include "pch.h"
#include "Tic Tac Toe.h"
#include <ctype.h>
#include <conio.h>
#include <string>
#include <iostream>

using namespace std;

char grid[10] = { '&','1','2', '3', '4', '5', '6', '7', '8', '9' };
int d{ 0 };

int main() {

	int mode{ menu() };
	
	(mode % 2) ? singlePlayer() : twoPlayer();

	return 0;
}

int menu() {
	string p = "->"; 
	int e{ 1 }, m{ 1 };

	cout << "\t Tic Tac Toe \n\n";

	cout << p << "Singleplayer\n";
	cout <<"  Two players";

	do {

		int c = 0;

		switch (c = _getch()) {
		case (KEY_UP):

			system("cls");
			m = 1;
			cout << "\t Tic Tac Toe \n\n";

			cout << p << "Singleplayer\n";
			cout << "  Two players";
			break;
		case (KEY_DOWN):

			system("cls");
			m = 2;
			cout << "\t Tic Tac Toe \n\n";

			cout << "  Singleplayer\n";
			cout << p << "Two players";
			break;
		case (KEY_ENTER):
			e = 0;
			continue;
		}
	} while (e == 1);

	if (m == 1) {

		e = 1;

		system("cls");
		cout << "\t Tic Tac Toe \n\n";
		cout << p << "Easy\n";
		cout << "  Hard";

		do {

			int c = 0;

			switch (c = _getch()) {
			case (KEY_UP):

				system("cls");
				d = 1;
				cout << "\t Tic Tac Toe \n\n";

				cout << p << "Easy\n";
				cout << "  Hard";
				break;
			case (KEY_DOWN):

				system("cls");
				d = 2;
				cout << "\t Tic Tac Toe \n\n";

				cout << "  Easy\n";
				cout << p << "Hard";
				break;
			case (KEY_ENTER):
				e = 0;
				continue;
			}
		} while (e == 1);
	}
	return m;
}

int checkWin() {
	//Horizontal win
	if (grid[1] == grid[2] && grid[2] == grid[3]) {
		return 1;
	}
	else if (grid[4] == grid[5] && grid[5] == grid[6]) {
		return 1;
	}
	else if (grid[7] == grid[8] && grid[8] == grid[9]) {
		return 1;
	}
	//Diagonal win
	else if (grid[1] == grid[5] && grid[5] == grid[9]) {
		return 1;
	}
	else if (grid[3] == grid[5] && grid[5] == grid[7]) {
		return 1;
	}
	//Vertical win
	else if (grid[1] == grid[4] && grid[4] == grid[7]) {
		return 1;
	}
	else if (grid[2] == grid[5] && grid[5] == grid[8]) {
		return 1;
	}
	else if (grid[3] == grid[6] && grid[6] == grid[9]) {
		return 1;
	}
	//Check if grid[] is filled
	else if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3' && grid[4] != '4' &&
		grid[5] != '5' && grid[6] != '6' && grid[7] != '7' && grid[8] != '8' &&
		grid[9] != '9') {
		return 0;
	}
	else {
		return -1;
	}
}

void display() {
	system("cls");
	cout << "\t Tic Tac Toe \n\n";
	cout << "Player 1-(X)\tPlayer 2-(O)\n\n";

	for (int i{ 1 }; i < 4; i++) {
		//cout << "     |     |     \n";
		printf("     |     |     \n");
		switch (i) {
			case(1):
				printf("  %c  |  %c  |  %c\n", grid[1], grid[2], grid[3]);
				//cout << " " << grid[1] << "   |  " << grid[2] << "  |  " << grid[3] << "\n";
				printf("     |     |     \n");
				//cout << "     |     |     \n";
				printf("-----|-----|-----\n");
				//cout << "-----|-----|-----\n";
				break;
			case(2):
				printf("  %c  |  %c  |  %c\n", grid[4], grid[5], grid[6]);
				//cout << " " << grid[4] << "   |  " << grid[5] << "  |  " << grid[6] << "\n";
				printf("     |     |     \n");
				//cout << "     |     |     \n";
				printf("-----|-----|-----\n");
				//cout << "-----|-----|-----\n";
				break;
			case(3):
				printf("  %c  |  %c  |  %c\n", grid[7], grid[8], grid[9]);
				//cout << " " << grid[7] << "   |  " << grid[8] << "  |  " << grid[9] << "\n";
				printf("     |     |     \n");
				//cout << "     |     |     \n";
				break;
		}
	}
}

int singlePlayer() {

	int player{ 1 }, i{ -1 }, choice;
	char sign;
	display();

	do {

		player = (player % 2) ? 1 : 2;
		sign = (player == 1) ? 'X' : NULL;

		if (player == 1) {

			printf("Player %u, enter your number: ", player);
			cin >> choice;

			if (choice == 1 && grid[1] == '1') {
				grid[1] = sign;
			}
			else if (choice == 2 && grid[2] == '2') {
				grid[2] = sign;
			}
			else if (choice == 3 && grid[3] == '3') {
				grid[3] = sign;
			}
			else if (choice == 4 && grid[4] == '4') {
				grid[4] = sign;
			}
			else if (choice == 5 && grid[5] == '5') {
				grid[5] = sign;
			}
			else if (choice == 6 && grid[6] == '6') {
				grid[6] = sign;
			}
			else if (choice == 7 && grid[7] == '7') {
				grid[7] = sign;
			}
			else if (choice == 8 && grid[8] == '8') {
				grid[8] = sign;
			}
			else if (choice == 9 && grid[9] == '9') {
				grid[9] = sign;
			}
			else {
				printf("Invalid, press any key to continue...");
				_getch();
			}
		}
		else {
			AI();
		}
		
		i = checkWin();
		(i == -1) ? player++ : NULL;
		display();

	} while (i == -1);

	display();
	if (i == 1) {
		if (player == 1) {
			printf("Player %d has win!\nPress any key to quit...", player);
		}
		else {
			printf("AI has win!\nPress any key to quit...");
		}
	}
	else {
		printf("Draw, no winners.\nPress any key to quit...");
	}

	_getch();
	return 0;
}

int twoPlayer() {

	int player{ 1 }, i{ -1 };
	char sign;
	string choice;
	display();

	do {

		player = (player % 2) ? 1 : 2;
		sign = (player == 1) ? 'X' : 'O';
		printf("Player %u, enter your number: ", player);

		getline(cin, choice);

		if (choice == "1" && grid[1] == '1') {
			grid[1] = sign;
		}
		else if (choice == "2" && grid[2] == '2') {
			grid[2] = sign;
		}
		else if (choice == "3" && grid[3] == '3') {
			grid[3] = sign;
		}
		else if (choice == "4" && grid[4] == '4') {
			grid[4] = sign;
		}
		else if (choice == "5" && grid[5] == '5') {
			grid[5] = sign;
		}
		else if (choice == "6" && grid[6] == '6') {
			grid[6] = sign;
		}
		else if (choice == "7" && grid[7] == '7') {
			grid[7] = sign;
		}
		else if (choice == "8" && grid[8] == '8') {
			grid[8] = sign;
		}
		else if (choice == "9" && grid[9] == '9') {
			grid[9] = sign;
		}
		else {
			printf("Invalid, press any key to continue...");
			_getch();
		}

		i = checkWin();
		(i == -1) ? player++ : NULL;
		display();
		choice = "";

	} while (i == -1);

	display();
	if (i == 1) {
		printf("Player %d has win!\nPress any key to quit...", player);
	}
	else {
		printf("Draw, no winners.\nPress any key to quit...");
	}

	_getch();
	return 0;
}

void AI() {

	int r = rand() % 100 + 1;
	if (d == 1) { //Easy
		bool n_lim{ r >= 60 };
	}
	else if (d == 2) { //Hard
		bool n_lim{ r >= 90 };
	}

}