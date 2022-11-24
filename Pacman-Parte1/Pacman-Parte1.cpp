#include <iostream>
#define Map_Vertical 29 //ESTO DEFINE QUE Map_Vertical VA A SER 29 EN TODO EL CODIGO
#define Map_Horizontal 120
using namespace std;
enum CASILLAS {EMPTY = ' ', H_WALL = '_', V_WALL = '|', POIT = '.' };
char map[Map_Vertical][Map_Horizontal]; //ARRAY 2D
bool run = true;

enum INPUT {QUIT, UP, DOWN,LEFT, RIGHT, UNKNOWN };
INPUT currentInput = INPUT::UNKNOWN;

void Setup() { //FUNCION PARA PREPARAR MAPA

	for (size_t i = 0; i < Map_Vertical; i++)
	{
		for (size_t j = 0; j < Map_Horizontal; j++)
		{
			if (i == 0 || i == Map_Vertical - 1)
			{
				map[i][j] = CASILLAS::H_WALL;

			}
			else if (j == 0 || j == Map_Horizontal - 1)
			{
				map[i][j] = CASILLAS::V_WALL;
			}
			else
			{
				map[i][j] = CASILLAS::EMPTY;

			}

		}
	}
}



void Input() {
	char input;
	cin >> input;
	switch (input)
	{
	case 'q':
	case 'Q':

		currentInput = INPUT::QUIT;
		break;
	case 'w':
	case 'W':

		currentInput = INPUT::UP;
		break;
	case 's':
	case 'S':

		currentInput = INPUT::DOWN;
		break;
	case 'd':
	case 'D':

		currentInput = INPUT::RIGHT;
		break;
	case 'a':
	case 'A':

		currentInput = INPUT::LEFT;
		break;
	default:
		currentInput = INPUT::UNKNOWN;
		break;
	}
}

void Logic() {
	switch (currentInput)
	{
	case QUIT:
		run = false;
		break;
	case UP:
		break;
	case DOWN:
		break;
	case LEFT:
		break;
	case RIGHT:
		break;

	}
}

void Draw() { // FUNCION PARA DIBUJAR MAPA
	system("CLS");
	for (size_t i = 0; i < Map_Vertical; i++)
	{
		for (size_t j = 0; j < Map_Horizontal; j++)
		{
			cout << (char)map[i][j];
		}
		cout << endl;
	}
}




int main() {

	Setup();
	Draw();
	while (run) {
		Input();
		Logic();
		Draw();

	}




}