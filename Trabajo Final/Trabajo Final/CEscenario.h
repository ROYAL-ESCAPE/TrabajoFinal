#pragma once
#include<ctime>
#include<stdlib.h>
#define filas 35
#define columnas 37
using namespace System::Drawing;
ref class CEscenario
{
private:
	int** matriz;
public:
	CEscenario() {
		matriz = new int* [filas];
	}
	~CEscenario()
	{

	}
	void generarMatriz() {
		srand(time(NULL));
		for (short i = 0; i < filas; i++)
		{
			matriz[i] = new int[columnas];
		}
		for (short i = 0; i < filas; i++)
		{
			for (short j = 0; j < columnas; j++)
			{
				if (i == 0 || j == 0 || i==filas-1||j==columnas-1) {//borde del laberinto
					matriz[i][j] = 1;
				}
				else {
					if ((i==1 &&(j==1||j==2))||(j==1 && i==2)||(i==filas-2 && (j==columnas-3||j==columnas-2)) ||(i == filas - 3 && j == columnas - 2)) {
						matriz[i][j] = 2;
					}
					else {
						matriz[i][j] = rand() % (2) + 2;
					}
				}
			}
		}
	}
	void PintarBase(Graphics^ graficador, Bitmap^ bmpBase) {
		int X, Y = 0;
		for (short i = 0; i < filas; i++)
		{
			X = 0;
			for (short j = 0; j < columnas; j++)
			{
				if (matriz[i][j] == 2) {
					graficador->DrawImage(bmpBase, X, Y, 20, 20);
				}
				X += 20;
			}
			Y += 20;
		}
	}
	void PintarMatriz(Graphics^ graficador, Bitmap^ bmpSolido, Bitmap^ bmpDestruible) {
		int X, Y = 0;
		for (short i = 0; i < filas; i++)
		{
			X = 0;
			for (short j = 0; j < columnas; j++)
			{
				if (matriz[i][j]==1) {
					graficador->DrawImage(bmpSolido, X, Y, 20, 20);
				}
				else
				{
					if (matriz[i][j] == 3) {
						graficador->DrawImage(bmpDestruible, X, Y, 20, 20);
					}
				}
				X += 20;
			}
			Y += 20;
		}
	}
	int** get_matriz() {
		return matriz;
	}
};
