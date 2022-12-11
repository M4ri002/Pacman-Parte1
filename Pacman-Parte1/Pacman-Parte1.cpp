#include <iostream>
#include <stdio.h>
#include <conio.h>
#define Map_Vertical 29 //ESTO DEFINE QUE Map_Vertical VA A SER 29 EN TODO EL CODIGO
#define Map_Horizontal 120
#define Map_Muro_x 15
#define Map_Muro_y 20
#define Peronaje '$'
using namespace std; // AHORRA PONER std
enum CASILLAS {EMPTY = ' ', H_WALL = '-', V_WALL = '*', MURO = '%', POINT = '.' };
char map[Map_Vertical][Map_Horizontal]; //ARRAY 2D
char muros[Map_Muro_x][Map_Muro_y];
bool run = true;


enum INPUT {QUIT, UP, DOWN,LEFT, RIGHT, RELOAD, UNKNOWN};
INPUT currentInput = INPUT::RELOAD;

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

	map[16][46] = CASILLAS::POINT;
	map[19][10] = CASILLAS::POINT;
	map[15][88] = CASILLAS::POINT;
	map[15][39] = CASILLAS::POINT;
	map[7][90] = CASILLAS::POINT;
	map[21][42] = CASILLAS::POINT;
	map[7][50] = CASILLAS::POINT;
	map[3][51] = CASILLAS::POINT;
	map[26][88] = CASILLAS::POINT;
	map[16][76] = CASILLAS::POINT;
	map[24][29] = CASILLAS::POINT;
	map[10][104] = CASILLAS::POINT;
	map[20][68] = CASILLAS::POINT;
	map[14][75] = CASILLAS::POINT;
	map[2][99] = CASILLAS::POINT;




	for (size_t i = 4; i < 10; i++)
	{
		map[i][Map_Horizontal/2] = CASILLAS::MURO;
	}
	for (size_t i = 20; i < 40; i++)
	{
		map[6][i] = CASILLAS::MURO;
	}	
	for (size_t i = 20; i < 40; i++)
	{
		map[23][i] = CASILLAS::MURO;
	}
	for (size_t i = 80; i < 100; i++)
	{
		map[6][i] = CASILLAS::MURO;
	}
	for (size_t i = 80; i < 100; i++)
	{
		map[23][i] = CASILLAS::MURO;
	}
	for (size_t i = 20; i < 26; i++)
	{
		map[i][Map_Horizontal / 2] = CASILLAS::MURO;
	}

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

//IZQUIERDA 97
//ARRIBA 119
//DERECHA 100
//ABAJO 115
//p = 112
void Input() {
	int input = 112;
	
	if (_kbhit()) {
	printf("\033[1;35m");
		input = _getch();
	printf("\033[0m");	
	}
	//cin >> input;
	switch (input)
	{
	case 113:
	/*case 'Q':*/

		currentInput = INPUT::QUIT;
		break;
	case 119:
	//case 'W':

		currentInput = INPUT::UP;
		break;
	case 115:
	//case 'S':

		currentInput = INPUT::DOWN;
		break;
	case 100:
	//case 'D':

		currentInput = INPUT::RIGHT;
		break;
	case 97:
	//case 'A':

		currentInput = INPUT::LEFT;
		break;
	case 112:
		currentInput = INPUT::RELOAD;
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
	case RELOAD:
		
		break;
	case UNKNOWN:
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

	case CASILLAS::MURO:
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
				printf("\033[1;32m");
				cout << Peronaje;
				printf("\033[0m");
			}
			else
			{
				printf("\033[31m");
				cout << (char)map[i][j];
				printf("\033[0m");
			}
		}
		cout << endl;
	}
	printf("\033[36m");
	cout << puntuacionActual << '/' << puntuacionTotal;
	printf("\033[0m");
	if (puntuacionActual == 15) {
		run = false;
		printf("\033[1;33m");
		cout << "\n********************";
		printf("\033[1;35m");
		cout << "   \nHAS GANADO!!";
		printf("\033[1;33m");
		cout << "\n********************";
		printf("\033[0m");

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



