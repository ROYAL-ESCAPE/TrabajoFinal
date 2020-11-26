#pragma once
#include<ctime>
#include"Entidad.h"
#define ANCHO 23
#define ALTO 13
#define tamanho_bloque 60
enum TipoEnemigo
{
	corrupto,
	assasins,
};
class CEnemigo abstract : public NPC {
protected:
	TipoEnemigo tipo;
public:
	CEnemigo(Bitmap^ img) : NPC(img) {

	}
	TipoEnemigo get_tipo() {
		return tipo;
	}
};
class CAsesino :public CEnemigo {

public:
	CAsesino(Bitmap^ img, vector<vector<int>> matriz) : CEnemigo(img) {
		dx = dy = 0;
		
		//variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
		velocidad = 5;
		accion = CaminarAbajo;
		this->ancho_recorte = img->Width / 3;
		this->alto_recorte = img->Height / 4;
		tipo = assasins;
		do
		{
			this->x = rand() % (ANCHO);
			this->y = rand() % (ALTO);
		} while ((matriz[this->y][this->x] != 0));
		this->x *= 60;
		this->y *= 60;
	}
	void Mover(Graphics^ g, vector<vector<int>> arr) override
	{
		Colision(arr);
			x += dx;
			y += dy;
	}
};
class CCorrupto: public CEnemigo {

public:
	CCorrupto(Bitmap^ img, vector<vector<int>> matriz) : CEnemigo(img){
		dx = dy = 0;
		
		velocidad = 5;
		accion = CaminarAbajo;
		ancho_recorte = img->Width / 3;
		alto_recorte = img->Height / 4;
		tipo = corrupto;
		do
		{
			this->x = rand() % (ANCHO);
			this->y = rand() % (ALTO);
		} while ((matriz[this->y][this->x] != 0));
		this->x *= 60;
		this->y *= 60;
	}
	void Mover(Graphics^ g, vector<vector<int>> arr) override
	{
		Colision(arr);
			x += dx;
			y += dy;
	}
};


class Enemigos
{
	vector<CEnemigo*> enemigos;
public:
	void Agregar(CEnemigo* enemigo)
	{
		enemigos.push_back(enemigo);
	}
	void Eliminar(int pos)
	{
		enemigos.erase(enemigos.begin() + pos);
	}
	int Size()
	{
		return enemigos.size();
	}
	CEnemigo* Get(int pos)
	{
		return enemigos[pos];
	}
	bool Colision(CAliado* aliado)
	{
		for (int i = 0; i < enemigos.size(); i++)
		{
			if (enemigos[i]->Area().IntersectsWith(aliado->Area())){
				return true;
			}
		}

		return false;
	}
	bool Colision(CJugador* jg)
	{
		for each (CEnemigo * E in enemigos)
			if (E->Area().IntersectsWith(jg->Area()))
				return true;

		return false;
	}
	void Mover(Graphics^ g, vector<vector<int>> arr,  CAliado* aliados, bool nivel2)//PARA ALIADOS
	{
		for each (CEnemigo * E in enemigos)
		{
			if (nivel2==false) {
				if (E->get_tipo() == corrupto && aliados->get_modo()==Aleatorio) {
					if (E->GetX() % 60 == 0 && E->GetY() % 60 == 0) {
						E->seguir(g, E->GetX() / tamanho_bloque, E->GetY() / tamanho_bloque, aliados->GetX() / tamanho_bloque, aliados->GetY() / tamanho_bloque, arr, E, aliados);
					}
					E->Mover(g, arr);
				}
			}
		}
	}	
	void Mover(Graphics^ g, vector<vector<int>> arr,  CJugador* jg, bool nivel2)//PARA JUGADOR
	{
		for each (CEnemigo * E in enemigos)
		{
			
				if (E->get_tipo() == assasins && nivel2 == true) {
					if (E->GetX() % 60 == 0 && E->GetY() % 60 == 0) {
						E->seguir(g, E->GetX() / tamanho_bloque, E->GetY() / tamanho_bloque, jg->GetX() / tamanho_bloque, jg->GetY() / tamanho_bloque, arr, E, jg);
					}
					E->Mover(g, arr);
				}
				if (E->get_tipo() == corrupto ) {
					if (E->GetX() % 60 == 0 && E->GetY() % 60 == 0) {
						E->seguir(g, E->GetX() / tamanho_bloque, E->GetY() / tamanho_bloque, jg->GetX() / tamanho_bloque, jg->GetY() / tamanho_bloque, arr, E, jg);
					}
					E->Mover(g, arr);
				}
			
		}
	}
	void Mostrar(Graphics^ g, Bitmap^ img, bool nivel2, Bitmap^ img_2)
	{
		for each (CEnemigo * E in enemigos)
		{
			if (nivel2==true && E->get_tipo()==assasins) {
				E->Mostrar(g, img_2);
			}
			if(E->get_tipo()==corrupto){
				E->Mostrar(g, img);
			}
		}
	}
};