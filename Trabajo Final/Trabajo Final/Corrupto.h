#pragma once

#include"Entidad.h"
#define ANCHO 21
#define ALTO 11
#define tamanho_bloque 50
class CEnemigo : public Entidad {

public:
	CEnemigo(Bitmap^ img) : Entidad(img) {

	}
	virtual void perseguir(CJugador* jugador) {
		Random^ r = gcnew Random;
		short confusion = r->Next(1, 10) > 2 ? 1 : -1;

		Point orco_xy = this->get_ubicacion();
		Point jugador_xy = jugador->get_ubicacion();
		if (jugador_xy.X - orco_xy.X < 0 && jugador_xy.X != orco_xy.X && jugador_xy.Y != orco_xy.Y) {
			this->dx -= 1 * confusion;
			this->accion = CaminarIzquierda;
		}
		else if (jugador_xy.X - orco_xy.X > 0 && jugador_xy.X != orco_xy.X && jugador_xy.Y != orco_xy.Y) {
			this->dx += 1 * confusion;
			this->accion = CaminarDerecha;
		}
		if (jugador_xy.Y - orco_xy.Y < 0 && jugador_xy.X != orco_xy.X && jugador_xy.Y != orco_xy.Y) {
			this->dy -= 1 * confusion;
			this->accion = CaminarArriba;
		}
		else if (jugador_xy.Y - orco_xy.Y > 0 && jugador_xy.X != orco_xy.X && jugador_xy.Y != orco_xy.Y) {
			this->dy += 1 * confusion;
			this->accion = CaminarAbajo;
		}
		delete r;
	}
};
class CAsesino :public CEnemigo {

public:
	CAsesino(Bitmap^ img) : CEnemigo(img) {
		x = (ANCHO - 2) * tamanho_bloque;
		y = (ALTO - 2) * tamanho_bloque;
		dx = dy = 0;
		accion = CaminarAbajo;
	}
	void perseguir(CJugador* jugador) override{
		Random^ r = gcnew Random;
		short confusion = r->Next(1, 10) > 2 ? 1 : -1;
		Point orco_xy = this->get_ubicacion();
		Point jugador_xy = jugador->get_ubicacion();
		if (jugador_xy.X - orco_xy.X < 0 && jugador_xy.X != orco_xy.X && jugador_xy.Y != orco_xy.Y) {
			this->dx -= 1 * confusion;
			this->accion = CaminarIzquierda;
		}
		else if (jugador_xy.X - orco_xy.X > 0 && jugador_xy.X != orco_xy.X && jugador_xy.Y != orco_xy.Y) {
			this->dx += 1 * confusion;
			this->accion = CaminarDerecha;
		}
		if (jugador_xy.Y - orco_xy.Y < 0 && jugador_xy.X != orco_xy.X && jugador_xy.Y != orco_xy.Y) {
			this->dy -= 1 * confusion;
			this->accion = CaminarArriba;
		}
		else if (jugador_xy.Y - orco_xy.Y > 0 && jugador_xy.X != orco_xy.X && jugador_xy.Y != orco_xy.Y) {
			this->dy += 1 * confusion;
			this->accion = CaminarAbajo;
		}
		delete r;
	}
};
class CCorrupto: public CEnemigo {

public:
	CCorrupto(Bitmap^ img) : CEnemigo(img){
		x = (ANCHO - 2) * tamanho_bloque+5;
		y = (ALTO - 3) * tamanho_bloque+5;
		dx = dy = 0;
		accion = CaminarAbajo;
	}
	void perseguir(CJugador* jugador) override {
		Random^ r = gcnew Random;
		short confusion = r->Next(1, 10) > 2 ? 1 : -1;

		Point orco_xy = this->get_ubicacion();
		Point jugador_xy = jugador->get_ubicacion();
		if (jugador_xy.X - orco_xy.X < 0 && jugador_xy.X != orco_xy.X && jugador_xy.Y != orco_xy.Y) {
			this->dx -= 1 * confusion;
			this->accion = CaminarIzquierda;
		}
		else if (jugador_xy.X - orco_xy.X > 0 && jugador_xy.X != orco_xy.X && jugador_xy.Y != orco_xy.Y) {
			this->dx += 1 * confusion;
			this->accion = CaminarDerecha;
		}
		if (jugador_xy.Y - orco_xy.Y < 0 && jugador_xy.X != orco_xy.X && jugador_xy.Y != orco_xy.Y) {
			this->dy -= 1 * confusion;
			this->accion = CaminarArriba;
		}
		else if (jugador_xy.Y - orco_xy.Y > 0 && jugador_xy.X != orco_xy.X && jugador_xy.Y != orco_xy.Y) {
			this->dy += 1 * confusion;
			this->accion = CaminarAbajo;
		}
		delete r;
	}
};