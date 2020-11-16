#pragma once
#include<iostream>
#include"Entidad.h"
#include"CEscenario.h"
using namespace System;
using namespace System::Drawing;
#define ANCHO 21
#define ALTO 11
#define tamanho_bloque 50

class CJugador: public Entidad {

	short vidas;
public:
	CJugador(Bitmap^ img) : Entidad(img){

		x = y = tamanho_bloque;
		dx = dy = 0;
		this->vidas = 5;
		accion = CaminarAbajo;
	}
	void SetAccion(MovimientoPersonaje value)
	{
		if (accion != value)
			IDx = 0;
		accion = value;
	}
	MovimientoPersonaje GetAccion()
	{
		return accion;
	}

	/*void Mover(Graphics^ g, vector<vector<int>> arr)
	{
		Colision(arr);
		if (x + dx >= 0 && x + dx + ancho < g->VisibleClipBounds.Width ) {
			x += dx;
		}
		if (y + dy >= 0 && y + dy + alto < g->VisibleClipBounds.Height ) {
			y += dy;
		}
	}*/
	void Mostrar(Graphics^ g, Bitmap^ img) 
	{
		
		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
		g->DrawRectangle(Pens::Black, Area());
		IDx = (IDx + 1) % 3;
	}
};
class CAliado : public Entidad {

public:
	CAliado(Bitmap^ img) : Entidad(img) {
		this->x = tamanho_bloque;
		this->y = tamanho_bloque;

	}
	~CAliado() {}
	void Direccion(int Px, int Py) {
		int v = 5;

		if (!((abs(x - Px) < v * 3 && abs(x - Px) > 0) && (abs(y - Py) < v * 3 && abs(y - Py) > 0)))
		{
			if (Px > x) { dx += v; accion = CaminarIzquierda; }
			else { dx -= v; accion = CaminarDerecha; }
			if (Py > y) { dy += v; accion = CaminarAbajo; }
			else { dy -= v; accion = CaminarArriba; }
		}

	}
};