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
	
	display();
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

		switch (c = getch()) {
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

			switch (c = getch()) {
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
	for (int i{ 0 }; i < 3; i++) {
		int ind = 1 + i * 3;
		if (grid[ind] == grid[ind + 1] && grid[ind + 1] == grid[ind + 2]) {
			return 1;
		}
	}

	//Diagonal win
	if (grid[1] == grid[5] && grid[5] == grid[9]) {
		return 1;
	}
	else if (grid[3] == grid[5] && grid[5] == grid[7]) {
		return 1;
	}
	//Vertical win
	for (int i{ 0 }; i < 3; i++) {
		int ind = 1 + i;
		if (grid[ind] == grid[ind + 3] && grid[ind + 3] == grid[ind + 6]) {
			return 1;
		}
	}

	//Check if grid[] is filled
	if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3' && grid[4] != '4' &&
		grid[5] != '5' && grid[6] != '6' && grid[7] != '7' && grid[8] != '8' &&
		grid[9] != '9') {
		return 0;
	}

	return -1;

}

void display() {
	system("cls");
	cout << "\t Tic Tac Toe \n\n";
	if (!d) {
		printf("Player 1-(X)\tPlayer 2-(O)\n\n");
	}
	else {
		printf("Player 1-(X)\tComputer 2-(O)\n\n");
	}

	for (int i{ 0 }; i < 3; i++) {
		int ind = 1 + i * 3;

		printf("     |     |     \n");
		printf("  %c  |  %c  |  %c\n", grid[ind], grid[ind + 1], grid[ind + 2]);
		printf("     |     |     \n");
		
		if (i != 2) {
			printf("-----|-----|-----\n");
		}
	}
}

int pickBoard(char choice, char sign) {
	int num = choice - '0';
	switch(num) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:	
	case 7:
	case 8:
	case 9:
		grid[num] = sign;
		return 1;
	default:
		return 0;
	}
}

int singlePlayer() {

	int player{ 1 }, i{ -1 };
	char sign, choice;

	do {
		player = (player % 2) ? 1 : 2;
		sign = (player == 1) ? 'X' : 'O';

		if (player == 1) {

			printf("Player %u, enter your number: ", player);
			cin >> choice;
			
			do {
				int re = pickBoard(choice, sign);
				if (re) { break; }
				
				printf("Invalid, press any key to continue...");
				cin >> choice;
			} while(1);
		}
		else {
			AI();
		}
		
		i = checkWin();
		(i == -1) ? player++ : -1;
		display();

	} while (i == -1);

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

	return 0;
}

int twoPlayer() {

	int player{ 1 }, i{ -1 };
	char sign, choice;

	do {
		player = (player % 2) ? 1 : 2;
		sign = (player == 1) ? 'X' : 'O';
		printf("Player %u, enter your number: ", player);

		cin >> choice;
		
		do {
			int re = pickBoard(choice, sign);
			if (re) { break; }
				
			printf("Invalid, press any key to continue...");
			cin >> choice;
		} while(1);

		i = checkWin();
		(i == -1) ? player++ : -1;
		display();

	} while (i == -1);

	if (i == 1) {
		printf("Player %d has win!\nPress any key to quit...", player);
	}
	else {
		printf("Draw, no winners.\nPress any key to quit...");
	}

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
