#pragma once
#include"CEscenario.h"
#include"Jugador.h"
#include"Corrupto.h"
ref class CControladora
{
private:
	CEscenario* escenario;
	CJugador* player;
	CCorrupto* corrupto;
	CAliado* aliado;
	CAsesino* asesino;
	Bitmap^ jg;
	Bitmap^ ass;
	Bitmap^ alia;
	Bitmap^ corrupt;
	Bitmap^ bmpSolido;
	Bitmap^ bmpBase;
public:
	CControladora() {
		this->bmpSolido = gcnew Bitmap("MATERIALES//ladrillo2.png");
		this->bmpBase = gcnew Bitmap("MATERIALES//grass.png");
		this->ass = gcnew Bitmap("MATERIALES//asesino.jpg");
		this->alia = gcnew Bitmap("MATERIALES//aliado.png");
		this->asesino = new CAsesino(ass);
		this->aliado = new CAliado(alia);
		this->escenario = new CEscenario();
		this->corrupt = gcnew Bitmap("MATERIALES\\corrupt.png");
		this->corrupto = new CCorrupto(corrupt);
		this->jg = gcnew Bitmap("MATERIALES\\jugador.png");
		this->player = new CJugador(jg);
	}
	~CControladora()
	{
		delete this->escenario, player, corrupto;
	}
	void MoverJugador(bool accion, Keys key)
	{
		int v = 5;
		if (accion == true )
		{
			if (key == Keys::Up)
			{
				player->SetDY(-v);
				player->SetAccion(CaminarArriba);
			}
			else if (key == Keys::Down)
			{
				player->SetDY(v);
				player->SetAccion(CaminarAbajo);
			}
			else if (key == Keys::Left)
			{
				player->SetDX(-v);
				player->SetAccion(CaminarIzquierda);
			}
			else if (key == Keys::Right)
			{
				player->SetDX(v);
				player->SetAccion(CaminarDerecha);
			}
		}
		else
		{
			if (key == Keys::Up)
				player->SetDY(0);
			else if (key == Keys::Down)
				player->SetDY(0);
			else if (key == Keys::Left)
				player->SetDX(0);
			else if (key == Keys::Right)
				player->SetDX(0);
		}
	}
	void Mover(Graphics^ g) 
	{
		//if (escenario->Colision(this->player)==false)
		player->Mover(g, escenario->get_arr());
	}
	void Mostrar(Graphics^ g)
	{
		escenario->empezar(g, this->bmpBase, this->bmpSolido);
		aliado->Direccion(player->GetX(),player->GetY());
		hacer_transparente(alia);
		aliado->Mostrar(g, alia);
		aliado->Mover(g, escenario->get_arr());
		hacer_transparente(ass);
		asesino->Mostrar(g, ass);
		asesino->perseguir(this->player);
		asesino->Mover(g, escenario->get_arr());
		hacer_transparente(corrupt);
		corrupto->Mostrar(g, corrupt);
		corrupto->perseguir(this->player);
		corrupto->Mover(g, escenario->get_arr());
		hacer_transparente(jg);
		player->Mostrar(g, jg);
	}
	void hacer_transparente(Bitmap^ img) {
		Color color = img->GetPixel(0, 0);  //Permite la transparencia
		img->MakeTransparent(color);
	}
};
