#pragma once
using namespace System::Drawing;
using namespace System;
using namespace System::Windows::Forms;
#define abajo 0
#define izquierda 1
#define derecha 2
#define arriba 3
#define alto 20
#define ancho 20
enum MovimientoEntidad {
	MoverArriba,//0
	MoverIzquierda,//1
	MoverDerecha,//2
	MoverAbajo//3
};

ref class CEntidad abstract
{
protected:
	short dx, dy,filas,columnas;
	Rectangle area_dibujo;//x,y,alto,ancho
	Bitmap^ imagen;
	MovimientoEntidad accion;
public:
	CEntidad(short x, short y, String^ ruta){
		this->area_dibujo = Rectangle(x, y, ancho, alto);
		this->dx = dx;
		this->dy = dy;
		this->filas = 4;
		this->columnas = 2;
		this->imagen = gcnew Bitmap(ruta);

	}
	~CEntidad() {
		delete this->imagen;
	}
	virtual void mover(){}
	virtual void dibujar(){}
	bool hay_colision(CEntidad^ otro){
		return this->area_dibujo.IntersectsWith(otro->area_dibujo);
	}
};

ref class CJugador : public CEntidad {
public:
	CJugador(short x, short y) : CEntidad(x, y,"MATERIALES/jugador.png") {}
	
	void mover(bool act, Keys tecla) override{// act para ver si presiono o no//creditos : taller
		if (accion == true)
		{
			if (tecla == Keys::Up)
			{
				--this->dy;
				this->accion = MoverArriba;
			}
			else if (tecla == Keys::Down)
			{
				++this->dy;
				this->accion = MoverAbajo;
			}
			else if (tecla == Keys::Left)
			{
				--this->dx;
				this->accion = MoverIzquierda;
			}
			else if (tecla == Keys::Right)
			{
				--this->dx;
				this->accion = MoverDerecha;
			}
		}
		else
		{
			if (tecla == Keys::Up)
				this->dy = 0;
			else if (tecla == Keys::Down)
				this->dy = 0;
			else if (tecla == Keys::Left)
				this->dx = 0;
			else if (tecla == Keys::Right)
				this->dx = 0;
		}
	}
};


