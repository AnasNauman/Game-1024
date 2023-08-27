#include <iostream>
#include <iomanip>
#include <ctime>
#include <conio.h>
using namespace std;

const int rows = 4, columns = 4;

void generateRandomNumber(int grid[][columns])
{
	srand(time(0));
	bool generate = false;
	for (int i = 0; i < rows * columns && !generate; i++)
	{
		if (grid[(i / 4)][(i % 4)] == 0) {
			generate = true;
		}
	}
	if (!generate) {
		return;
	}
	int r = rand() % rows, c = rand() % columns;
	do {
		if (grid[r][c] ==0) {
			grid[r][c] = rand() % 2 + 1;
			break;
		}
		r = rand() % rows;
		c = rand() % columns;
	} while (true);
}

void up(int grid[rows][columns])
{ 
	bool movement = false;
	for (int j = 0; j < columns; j++){
		int i2 = 0, j2 = j;
		for (int i = 1; i < rows; i++) {
			if (grid[i][j] != 0){
				if (grid[i][j] == grid[i - 1][j] || grid[i - 1][j] == 0) {
					movement = true;
					if (grid[i2][j2] == grid[i][j]) {
						grid[i2][j2] = grid[i][j] + grid[i][j];
						grid[i][j] = 0;
						i2++;
					}
					else {
						if (grid[i2][j2] == 0){
							grid[i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
						else{
							grid[++i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
					}
				}
				else {
					i2++;
				}
			}
		}
	}

	if(movement){
		generateRandomNumber(grid);
	}
}
void right(int grid[rows][columns])
{
	bool movement = false;
	for (int i = 0; i < 4; i++) {
		int i2 = i, j2 = columns - 1;
		for (int j = j2 - 1; j >= 0; j--) {
			if (grid[i][j] != 0) {
				if (grid[i][j] == grid[i][j + 1] || grid[i][j + 1] == 0) {
					movement = true;
					if (grid[i2][j2] == grid[i][j]) {
						grid[i2][j2] = grid[i][j] + grid[i][j];
						grid[i][j] = 0;
						j2--;
					}
					else {
						if (grid[i2][j2] == 0) {
							grid[i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
						else {
							grid[i2][--j2] = grid[i][j];
							grid[i][j] = 0;
						}
					}
				}
				else {
					j2--;
				}
			}
		}
	}

	if (movement) {
		generateRandomNumber(grid);
	}
}
void down(int grid[rows][columns])
{
	bool movement = false;
	for (int j = 0; j < columns; j++){
		int i2 = rows - 1, j2 = j;
		for (int i = i2 - 1; i >= 0; i--){
			if (grid[i][j] != 0){
				if (grid[i][j] == grid[i + 1][j] || grid[i + 1][j] == 0){
					movement = true;
					if (grid[i2][j2] == grid[i][j]){
						grid[i2][j2] = grid[i][j] + grid[i][j];
						grid[i][j] = 0;
						i2--;
					}
					else {
						if (grid[i2][j2] == 0){
							grid[i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
						else{
							grid[--i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
					}
				}
				else {
					i2--;
				}
			}
		}
	}

	if (movement) {
		generateRandomNumber(grid);
	}
}
void left(int grid[rows][columns])
{
	bool movement = false;
	for (int i = 0; i < rows; i++){
		int i2 = i, j2 = 0;
		for (int j = 1; j < columns; j++){
			if (grid[i][j] != 0){
				if (grid[i][j] == grid[i][j - 1] || grid[i][j - 1] == 0){
					movement = true;
					if (grid[i2][j2] == grid[i][j]){
						grid[i2][j2] = grid[i][j] + grid[i][j];
						grid[i][j] = 0;
						j2++;
					}
					else{
						if (grid[i2][j2] == 0){
							grid[i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
						else{
							grid[i2][++j2] = grid[i][j];
							grid[i][j] = 0;
						}
					}
				}
				else {
					j2++;
				}
			}
		}
	}

	if (movement) {
		generateRandomNumber(grid);
	}
}


void displayGrid(int grid[][columns])
{
	cout << endl << endl << "\t\t\t\t\t*********************************" << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << "\t\t\t\t\t";
		for (int j = 0; j < columns; j++)
		{
			if (grid[i][j] == 0)
				cout << "|\t";
			else
				cout << "| " << setw(5) << left << grid[i][j] << "\t";
		}
		cout << "|" << endl;
		cout << "\t\t\t\t\t*********************************" << endl;
	}
}
bool winnerCheck(int grid[][columns])
{
	bool  gameWon = false;
	for (int i = 0; i < rows * columns &&!gameWon; i++) {
		if (grid[(i / 4)][(i % 4)] == 1024) {
			gameWon = true;
		}
	}
	return gameWon;
}
bool loserCheck(int grid[][columns])
{
	bool gameLoose = true;
	for (int i = 0; i < rows * columns && gameLoose; i++) {
		if (grid[(i / 4)][(i % 4)] == 0) {
			gameLoose = false;
		}
	}

	for (int i = 1; i < rows && gameLoose; i++) {
		for (int j = 0; j < columns && gameLoose; j++) {
			if (grid[i][j] == grid[i - 1][j]) {
				gameLoose = false;
			}
		}
	}

	for (int i = 1; i < columns && gameLoose; i++) {
		for (int j = 0; j < rows && gameLoose; j++) {
			if (grid[j][i] == grid[j][i - 1]) {
				gameLoose = false;
			}
		}
	}
	return gameLoose;
}

void printInstructions() {
	cout << "\t\tInstructions: " << endl;
	cout << "\t\t\tPress W/Up    to Move Up" << endl;
	cout << "\t\t\tPress D/Right to Move Right" << endl;
	cout << "\t\t\tPress S/Down  to Move Down" << endl;
	cout << "\t\t\tPress A/Left  to Move Left" << endl;
	cout << "\t\t\tPress Q/Esc   to Quit" << endl;
}

int main()
{
	int key,grid[rows][columns] = { {0},{0},{0},{0} };
	cout << "\t\t\t\t\t****Welcome To 1024****" << endl<<endl<<endl;
	printInstructions();
	generateRandomNumber(grid);
	generateRandomNumber(grid);
	displayGrid(grid); 
	do
	{
		cout << "> ";
		 key = _getch();
		if (key == 113 || key == 27){
			cout << "You have Quit The Game";
			break;
		}
		else if (key == 119|| key == 87 ||key ==72 ){
			up(grid);
		}
		else if (key == 100 || key == 68 || key == 77){
			right(grid);
		}
		else if (key == 115 || key == 83 || key == 80){
			down(grid);
		}
		else if (key == 97 || key == 65 || key == 75){
			left(grid);
		}
		else{
			if (key != 224) {
				cout << "Invalid Input" << endl;
			}
			continue;
		}

		system("CLS");
		displayGrid(grid);

		if (winnerCheck(grid)){
			cout << "You Win.";
			break;
		}

		if (loserCheck(grid)){
			cout << "You Lose.";
			break;
		}
	}while (true);
	return 0;
}