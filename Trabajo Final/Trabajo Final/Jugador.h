#pragma once
#include<iostream>
#include"Entidad.h"
#include"CEscenario.h"
using namespace System;
using namespace System::Drawing;
#define ANCHO 23
#define ALTO 13
#define tamanho_bloque 60

enum ModoAliado {
	Escolta,
	Kamikaze,
	Aleatorio,
};


class CJugador: public Entidad {

	short vidas;
public:
	CJugador(Bitmap^ img) : Entidad(img){

		x =  tamanho_bloque;
		y =  tamanho_bloque;
		dx = dy = 0;
		ancho_recorte = img->Width / 3;
		alto_recorte = img->Height / 4;
		this->vidas = 10;
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
	short get_vidas() {
		return vidas;
	}
	void set_vidas(short value) {
		this->vidas = vidas+value;
	}
};
class CAliado :  public NPC{

	ModoAliado modo;
	bool marcado;
public:
	CAliado(Bitmap^ img, ModoAliado modo_, vector<vector<int>> matriz) : NPC(img) {
		
		accion = CaminarArriba;
		ancho = alto = tamanho_bloque;
		ancho_recorte = img->Width / 3;
		alto_recorte = img->Height / 4;
		modo = modo_;
		marcado = false;
		velocidad = 15;
		if (modo==Escolta) {
			do
			{
				this->x = rand() % (ANCHO/5);
				this->y = rand() % (ALTO/5);
			} while ((matriz[this->y][this->x] != 0));
			this->x *= 60;
			this->y *= 60;
		}
		if (modo==Aleatorio) {
			do
			{
				this->x = rand() % (ANCHO);
				this->y = rand() % (ALTO);
			} while ((matriz[this->y][this->x] != 0));
			this->x *= 60;
			this->y *= 60;
		}
		
	}
	~CAliado() {}
	void set_marcado(bool value) {
		this->marcado = value;
	}
	bool get_marcado() {
		return this->marcado;
	}
	void Mover(Graphics^ g, vector<vector<int>> arr) override
	{
		Colision(arr);
		if (this->modo==Escolta || this->modo==Kamikaze) {//si es escolta lo sigue
			x += dx;
			y += dy;
		}
		if (modo==Aleatorio) {//solo se mueve en la posicion donde se genero
			this->accion = CaminarAbajo;
			Colision(arr);
			/*if (rand()%2==0) {
				dx = rand() % 10 - 5;
				if (dx == 0) dx = 5;	
			}
			else
			{
				dy = rand() % 10 - 5;
				if (dy == 0) dy = 5;
			}*/
		}
		
	}
	ModoAliado get_modo() {
		return this->modo;
	}
	void set_modo(ModoAliado modo) {
		this->modo = modo;
	}
};

class Aliados{

	vector<CAliado*> aliados;
public:
	void Agregar(CAliado* enemigo)
	{
		aliados.push_back(enemigo);
	}
	void Eliminar(int pos)
	{
		aliados.erase(aliados.begin() + pos);
	}
	int Size()
	{
		return aliados.size();
	}
	CAliado* Get(int pos)
	{
		return aliados[pos];
	}
	void eliminar(CAliado* A) {
		for (int i = 0; i < aliados.size(); i++)
		{
			if (aliados.at(i) == A) {

				delete A;
				aliados.erase(aliados.begin() + i);
				i--;
			}
		}
	}
	bool Colision(CJugador* jg)
	{
		
		for (int i = 0; i < aliados.size(); i++)
		{
			if (aliados[i]->Area().IntersectsWith(jg->Area()) && aliados[i]->get_modo()==Kamikaze) {
				return true;
			}
		}
		return false;
	}

	void Mover(Graphics^ g, vector<vector<int>> arr,  Entidad* jg)
	{
		for each (CAliado * E in aliados)
		{
			if (E->get_modo()==Escolta) {
				if (E->GetX() % 60 == 0 && E->GetY() % 60 == 0) {
					E->seguir(g, E->GetX() / tamanho_bloque, E->GetY() / tamanho_bloque, jg->GetX() / tamanho_bloque, jg->GetY() / tamanho_bloque, arr, E, jg);
				}
			}
		    if (E->get_modo()==Kamikaze) {
				if (E->GetX() % 60 == 0 && E->GetY() % 60 == 0) {
					E->seguir(g, E->GetX() / tamanho_bloque, E->GetY() / tamanho_bloque, jg->GetX() / tamanho_bloque, jg->GetY() / tamanho_bloque, arr, E, jg);
				}
			}
				E->Mover(g, arr);
		}
	}	
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		for each (CAliado * E in aliados)
		{
			E->Mostrar(g, img);
			if (E->get_modo()==Kamikaze) {
				g->DrawRectangle(Pens::Red, E->Area());
			}
		}
	}
};