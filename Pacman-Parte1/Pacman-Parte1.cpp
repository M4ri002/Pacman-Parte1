#include <iostream>
#define Map_Vertical 29 //ESTO DEFINE QUE Map_Vertical VA A SER 29 EN TODO EL CODIGO
#define Map_Horizontal 120
#define Personaje '$'
using namespace std; // AHORRA PONER std
enum CASILLAS {EMPTY = ' ', H_WALL = '-', V_WALL = '*', POINT = '.' };
char map[Map_Vertical][Map_Horizontal]; //ARRAY 2D
bool run = true;


enum INPUT {QUIT, UP, DOWN,LEFT, RIGHT, UNKNOWN };
INPUT currentInput = INPUT::UNKNOWN;

// POSICIONES DEL PERSONAJE
int personaje_x;
int personaje_y;
int puntuacionActual = 0;
int puntuacionTotal;



void Setup() { //FUNCION PARA PREPARAR MAPA
	personaje_x = Map_Horizontal / 2;
	personaje_y = Map_Vertical / 2;
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
	map[10][3] = CASILLAS::POINT;
	map[11][4] = CASILLAS::POINT;
	map[12][5] = CASILLAS::POINT;
	map[13][6] = CASILLAS::POINT;

	

	map[10][0] = CASILLAS::EMPTY;
	map[11][0] = CASILLAS::EMPTY;
	map[12][0] = CASILLAS::EMPTY;
	map[13][0] = CASILLAS::EMPTY;

	map[10][Map_Horizontal - 1] = CASILLAS::EMPTY;
	map[11][Map_Horizontal - 1] = CASILLAS::EMPTY;
	map[12][Map_Horizontal - 1] = CASILLAS::EMPTY;
	map[13][Map_Horizontal - 1] = CASILLAS::EMPTY;

	for (size_t i = 0; i < Map_Vertical; i++)
	{
		for (size_t j = 0; j < Map_Horizontal; j++)
		{
			if (map[i][j] == CASILLAS::POINT) // PINTA AL PERSONAJE
			{
				puntuacionTotal++;
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
	int personaje_y_new = personaje_y;
	int personaje_x_new = personaje_x;

	switch (currentInput)
	{
	case QUIT:
		run = false;
		break;
	case UP:
		personaje_y_new--;
		break;
	case DOWN:
		personaje_y_new++;
		break;
	case LEFT:
		personaje_x_new--;
		break;
	case RIGHT:
		personaje_x_new++;
		break;

	}
	if (personaje_x_new < 0) //TELEPORT DE IZQUIERDA A DERECHA
	{
		personaje_x_new = Map_Horizontal - 1;
	}
	personaje_x_new = personaje_x_new % Map_Horizontal; //MODULO(TELEPORT DE DERECHA A IZQUIERDA)

	switch (map[personaje_y_new][personaje_x_new])
	{
	case CASILLAS::H_WALL:
		break;

	case CASILLAS::V_WALL:
		break;

	case CASILLAS::POINT:
		puntuacionActual++;
		map[personaje_y_new][personaje_x_new] = CASILLAS::EMPTY;
	default:
		personaje_y = personaje_y_new;
		personaje_x = personaje_x_new;
		break;
	}

}

void Draw() { // FUNCION PARA DIBUJAR MAPA
	system("CLS");
	for (size_t i = 0; i < Map_Vertical; i++)
	{
		for (size_t j = 0; j < Map_Horizontal; j++)
		{
			if (i == personaje_y && j == personaje_x) // PINTA AL PERSONAJE
			{
				cout << Personaje;
			}
			else
			{
				cout << (char)map[i][j];	
			}
		}
		cout << endl;
	}
	cout << puntuacionActual << '/' << puntuacionTotal;
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



