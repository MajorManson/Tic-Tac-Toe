#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


class Game {
private:
	char grid[10];
	int mode, difficulty;

	void display() {
		// system("CLS");
		cout << "\t Tic Tac Toe \n\n";
		if (!difficulty) {
			printf("Player 1-(X)\tPlayer 2-(O)\n\n");
		}
		else {
			printf("Player 1-(X)\tComputer-(O)\n\n");
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
		if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3' &&
			grid[4] != '4' && grid[5] != '5' && grid[6] != '6' &&
			grid[7] != '7' && grid[8] != '8' && grid[9] != '9') {
			return 0;
		}

		return -1;
	}

	int pickBoard(string choice, char sign) {
		int num;
		stringstream(choice) >> num;
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
			if (grid[num] == (num + '0')) {
				grid[num] = sign;
				return 1;
			}
		default:
			return 0;
		}
	}

	void AI(int depth) {

		if (difficulty == 1) { //Easy
			int pos = rand() % 9 + 1;
			if (grid[pos] != ('0' + pos)) { AI(0); }
			else { grid[pos] = 'O'; }
		}
		else if (difficulty == 2) { //Hard
			int i = bestMove(depth);
			grid[i] = 'O';
		}

	}

	int bestMove(int depth) {
		int bestScore = -999;
		int move;

		for (int i{ 1 }; i <= 10; i++) {
			char g = '0' + i;
			if (grid[i] == g) {
				grid[i] = 'O';
				int score = minmax(depth + 1, false);
				grid[i] = g;

				if (score > bestScore) {
					bestScore = score;
					move = i;
				}
			}
		}

		return move;
	}

	int minmax(int depth, bool AI) {

		int gameState = checkWin();
		if (gameState == 1) {
			if (AI) { return -1; }
			else { return 1; }
		}

		else if (!gameState) { return 0; }

		if (AI) {
			int best = -999;
			for (int i{ 1 }; i <= 10; i++) {
				char g = '0' + i;
				if (grid[i] == g) {
					grid[i] = 'O';
					int score = minmax(depth + 1, false);
					grid[i] = g;

					if (score > best) { best = score; }
				}
			}

			return best;
		}
		else {
			int best = 999;
			for (int i{ 1 }; i <= 10; i++) {
				char g = '0' + i;
				if (grid[i] == g) {
					grid[i] = 'X';
					int score = minmax(depth + 1, true);
					grid[i] = g;

					if (score < best) { best = score; }
				}
			}

			return best;
		}
	}

public:
	Game() {
		init();
	}

	void init() {
		grid[0] = '&';
		for (int i{ 1 }; i <= 10; i++) {
			grid[i] = '0' + i;
		}
	}

	int menu() {
		cout << "\t Tic Tac Toe \n\n";
		cout << "(1) Singleplayer\n";
		cout <<"(2) Two players\n";

		char c;
		do {
			cin >> c;
			switch (c - '0') {
			case (1): // Singleplayer
				// system("CLS");
				mode = 1;
				break;
			case (2): //Multiplayer
				// system("CLS");
				mode = 2;
				break;
			default:
				break;
			}
		} while (!mode);

		if (mode == 2) { 
			return 2; 
		}

		//cout << "\t Tic Tac Toe \n\n";
		cout << "(1) Easy\n";
		cout << "(2) Hard\n";

		do {

			cin >> c;
			switch (c - '0') {
			case (1):
				// system("CLS");
				difficulty = 1;
				break;
			case (2):
				// system("CLS");
				difficulty = 2;
				break;
			default:
				break;
			}
		} while (!difficulty);

		
		return 1;
	}

	int singlePlayer() {

		int player{ 1 }, i{ -1 };
		char sign;
		string choice;
		getline(cin, choice);

		int moves{ 0 };

		do {
			player = (player % 2) ? 1 : 2;
			sign = (player == 1) ? 'X' : 'O';

			if (player == 1) {
				display();
				printf("Player %u, enter your number: ", player);
				
				do {
					getline(cin, choice);
					int re = pickBoard(choice, sign);
					if (re) { break; }
					
					printf("Invalid. Enter your number again: ");
				} while(1);

				moves++;
			}
			else {
				AI(moves++);
			}
			
			i = checkWin();
			(i == -1) ? player++ : -1;

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

		printf("Continue (Y/N)?\n");
		char cont;
		do {
			cin >> cont;
			cont = toupper(cont);

			if (cont == 'N') { break; }

			if (cont == 'Y') { 
				init();
				singlePlayer();
				break;
			}

		} while (1);

		return 0;
	}

	int twoPlayer() {

		int player{ 1 }, i{ -1 };
		char sign;
		string choice;
		getline(cin, choice);

		do {
			display();
			player = (player % 2) ? 1 : 2;
			sign = (player == 1) ? 'X' : 'O';
			printf("Player %u, enter your number: ", player);

			do {
				getline(cin, choice);
				int re = pickBoard(choice, sign);
				if (re) { break; }
					
				printf("Invalid. Enter your number again: ");
			} while(1);

			i = checkWin();
			(i == -1) ? player++ : -1;

		} while (i == -1);
		display();

		if (i == 1) {
			printf("Player %d has win!\nPress any key to quit...", player);
		}
		else {
			printf("Draw, no winners.\nPress any key to quit...");
		}

		printf("Continue (Y/N)?\n");
		char cont;
		do {
			cin >> cont;
			cont = toupper(cont);

			if (cont == 'N') { break; }

			if (cont == 'Y') { 
				init();
				twoPlayer();
				break;
			}

		} while (1);
		

		return 0;
	}
};


int main() {

	Game *game = new Game;
	int mode{ game->menu() };
	
	(mode % 2) ? game->singlePlayer() : game->twoPlayer();

	return 0;
}
