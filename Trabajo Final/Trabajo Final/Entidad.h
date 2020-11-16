#pragma once
#include<iostream>
#include<vector>
#include<time.h>
#define ANCHO 21
#define ALTO 11
#define tamanho_bloque 50
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

enum MovimientoPersonaje
{
	CaminarAbajo,
	CaminarIzquierda,
	CaminarDerecha,
	CaminarArriba,
};
class Imagen {  //NUESTROS OBSTACULOS

protected:
int x, y;		 //Posicion
int ancho, alto; //Tamaño

public:

	Imagen() {

		x = y = 0;
		ancho = alto = 0;
		//se contruye la imagen usando la ruta

	}
int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
 int GetAncho()
	{
		return ancho;
	}
	int GetAlto()
	{
		return alto;
	}
	void SetX(int value)
	{
		x = value;
	}
	void SetY(int value)
	{
		y = value;
	}
	Rectangle Area()
	{
		return Rectangle(x, y, 40, 40);//modifica los tamaños de las img
	}

};
	



class Entidad: public Imagen{ //TODOS NUESTROS PERSONAJES
protected:
	
	int dx, dy;		//Velocidad
	int IDx;
	MovimientoPersonaje accion;
public:
	Entidad(Bitmap^ img)
	{
		x = y = 0;
		dx = dy = 0;
		//ancho = alto = 0;
		IDx = 0;

		ancho = img->Width / 3;
		alto = img->Height / 4;
	}
	
	int GetDX()
	{
		return dx;
	}
	int GetDY()
	{
		return dy;
	}
	
	int GetIDx()
	{
		return IDx;
	}
	void SetDX(int value)
	{
		dx = value;
	}
	void SetDY(int value)
	{
		dy = value;
	}
	void SetAncho(int value)
	{
		ancho = value;
	}
	void SetAlto(int value)
	{
		alto = value;
	}
	virtual void Mover(Graphics^ g, vector<vector<int>> arr)
	{
		Colision(arr);
		if (x + dx >= 0 && x + dx + ancho < (ANCHO)*tamanho_bloque) {
			x += dx;
		}
		if (y + dy >= 0 && y + dy + alto < g->VisibleClipBounds.Height) {
			y += dy;
		}
	}
	virtual void Mostrar(Graphics^ g, Bitmap^ img)
	{
		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Black, Area());
		IDx = (IDx + 1) % 3;
	}
	Rectangle NextArea()
	{
		return Rectangle(x + dx, y + dy, 40, 40);
	}
	Point get_ubicacion() {//manda las coordenadas de un punto, lo pense usar para hacer la funcion perseguir
		return Point(this->Area().X + this->Area().Width / 2,
			this->Area().Y + this->Area().Height / 2);
	}
	void Colision(vector<vector<int>> arr) {
		int X, Y = 0;
		for (int i = 0; i < ALTO; i++)
		{
			X = 0;
			for (int j = 0; j < ANCHO; j++)
			{
				Rectangle c1 = Rectangle(X, Y, tamanho_bloque, tamanho_bloque);
				if (arr[i][j] == 1) {//paredes
					if (NextArea().IntersectsWith(c1)) { 
						dx = 0; 
						dy = 0;
					};
				}
				X += tamanho_bloque;
			}
			Y += tamanho_bloque;
		}
	}
};