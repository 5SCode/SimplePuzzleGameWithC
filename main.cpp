#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
using namespace std;

const int row = 3, col = 3;
char map[row][col] = {'1','2','3','4','5','6','7','8',' '};
char mapSorted[row][col] = {'1','2','3','4','5','6','7','8',' '};
char emptyBox = ' ';
char moveEmptyBox;
int x, y;
int xOld, yOld;

// generate map
void generateMap(){
	// random array map
	int indexRow, indexCol;
	char temp;
	srand(time(NULL));
	for(int i=0; i<row; i++){
		indexRow = rand() % row;
		for(int j=0; j<col; j++){
			indexRow = rand() % col;
			// swap map[i][j] with map[indexRow][indexCol]
			temp = map[i][j];
			map[i][j] = map[indexRow][indexCol];
			map[indexRow][indexCol] = temp;
		}
	}
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(map[i][j] == ' '){
				x = j; y = i;
				emptyBox = map[y][x];
			}
		}
	}
}

// print map
void printMap(){
	for(int i=0; i<row; i++){
		cout << "\t\t";
		for(int k=0; k<col; k++) cout << "--------";
		cout << endl;
		cout << "\t\t";
		for(int j=0; j<col; j++){
			cout << "|   " << map[i][j] << "   ";
		}
		cout << "|";
		cout << endl;
	}
	cout << "\t\t";
	for(int k=0; k<col; k++) cout << "--------";
}

// check map
int checkMap(){
	int same;
	// check all value map[i][j] with mapSorted[i][j]
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
				if(map[i][j] == mapSorted[i][j]){
					same++;
					if(same==(row*col)) return 1;
			}
		}
	}
}


int main(){
	int countMove;
	char temp;
	bool Exit = false;
	
	cout << "\n\n\t\t---------------------------\n";
	cout << "\t\t  Welcome to Puzzle Game" << endl;
	cout << "\t\t        By 5S CODE" << endl;
	cout << "\t\t---------------------------\n";
	cout << "\t\t Sort the numbers as below" << endl << endl;
	
	for(int i=0; i<row; i++){
		cout << "\t\t";
		for(int k=0; k<col; k++) cout << "--------";
		cout << endl;
		cout << "\t\t";
		for(int j=0; j<col; j++){
			cout << "|   " << mapSorted[i][j] << "   ";
		}
		cout << "|";
		cout << endl;
	}
	cout << "\t\t";
	for(int k=0; k<col; k++) cout << "--------";
	
	cout << "\n\n\t\t---------------------------\n";
	cout << "\t\t  Use W S A D key to Move" << endl;
	cout << "\t\t 'r' to Reset, 'x' to Exit" << endl << endl;
	cout << "\t\t Press Any Key to Continue" << endl;
	cout << "\t\t---------------------------\n";
	getch();
	
	// Game Start
	generateMap();
	while(Exit != true){
		system("cls");
		xOld = x;
		yOld = y;
		
		cout << "\n\n\t\t---------------------------\n";
		cout << "\t\t\tPuzzle Game" << endl;
		cout << "\t\t---------------------------\n";
		printMap();
		cout << "\n\n\t\t-----------\t"; cout << "-----------\n";
		cout << "\t\tMove: " << countMove << "    \t"; cout << "Level: Easy\t";
		cout << "\n\t\t-----------\t"; cout << "-----------\n";
		
		if(checkMap() == 1){
			cout << "\nYOU WINNN !!!" << endl;
			Exit = true; 
		}
		moveEmptyBox = getch();
		switch(moveEmptyBox){
			case 'w':
				if(y>0){
					y--;
					countMove++;
					temp = map[y][x];
					map[y][x] = map[yOld][xOld];
					map[yOld][xOld] = temp;
				}
				break;
			case 's':
				if(y<row-1){
					y++;
					countMove++;
					temp = map[y][x];
					map[y][x] = map[yOld][xOld];
					map[yOld][xOld] = temp;
				}
				break;
			case 'a':
				if(x>0){
					x--;
					countMove++;
					temp = map[y][x];
					map[y][x] = map[yOld][xOld];
					map[yOld][xOld] = temp;
				}
				break;
			case 'd':
				if(x<col-1){
					x++;
					countMove++;
					temp = map[y][x];
					map[y][x] = map[yOld][xOld];
					map[yOld][xOld] = temp;
				}
				break;
			case 'r':
				generateMap();
				countMove = 0;
				break;
			case 'x':
				Exit = true;
				break;
			default: break;
		}
	}
	
	return 0;
}
