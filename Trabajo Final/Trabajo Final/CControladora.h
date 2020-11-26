#pragma once
#include<conio.h>
#include"CEscenario.h"
#include"Jugador.h"
#include"Corrupto.h"
#include"Entidad.h"
#define max_kamizake 4
ref class CControladora
{
private:
	Cportales* portal_1;
	Cportales* portal_2;
	CEscenario* escenario;
	CJugador* player;
	Enemigos* enemigos;
	Aliados* aliados;


	Bitmap^ jg;
	Bitmap^ asesino;
	Bitmap^ alia;
	Bitmap^ corrupt;
	Bitmap^ bmpSolido;
	Bitmap^ bmpBase;
	Bitmap^ porta;


	int tiempo;
	bool ganar;
	int golpeEnemigo;
	bool nivel_2;
	int time_animacion;
	int colddown_portal;

	int cont_kamikaze;
	int cont_corruptos;
	int v;
public:
	CControladora() {
		srand(time(NULL));
		tiempo= 150 * 1000 + clock();
		time_animacion = 0;
		ganar = false;
		v = 30;//velocidad
		cont_kamikaze = 0;
		int golpeEnemigo;
		cont_corruptos = 4;
		this->nivel_2 = false;
		this->porta = gcnew Bitmap("MATERIALES\\portal.png");
		this->bmpSolido = gcnew Bitmap("MATERIALES//ladrillo2.png");
		this->bmpBase = gcnew Bitmap("MATERIALES//grass.png");
		this->asesino = gcnew Bitmap("MATERIALES//assasin.png");
		this->alia = gcnew Bitmap("MATERIALES//aliado.png");
		this->corrupt = gcnew Bitmap("MATERIALES\\corrupt.png");
		this->jg = gcnew Bitmap("MATERIALES\\jugador.png");
		this->aliados = new Aliados();
		this->enemigos = new Enemigos();
		
		
		
		this->escenario = new CEscenario();
		this->portal_1 = new Cportales(porta, escenario->get_arr(), 1);
		this->portal_2 = new Cportales(porta, escenario->get_arr(), 2);
		//aliados aleatorio proporcional a corruptos
		enemigos->Agregar(new CCorrupto(corrupt, escenario->get_arr()));
		enemigos->Agregar(new CCorrupto(corrupt, escenario->get_arr()));
		enemigos->Agregar(new CCorrupto(corrupt, escenario->get_arr()));
		enemigos->Agregar(new CCorrupto(corrupt, escenario->get_arr()));
		enemigos->Agregar(new CAsesino(asesino, escenario->get_arr()));
		enemigos->Agregar(new CAsesino(asesino, escenario->get_arr()));
		enemigos->Agregar(new CAsesino(asesino, escenario->get_arr()));
		enemigos->Agregar(new CAsesino(asesino, escenario->get_arr()));
		enemigos->Agregar(new CAsesino(asesino, escenario->get_arr()));
		enemigos->Agregar(new CAsesino(asesino, escenario->get_arr()));
		enemigos->Agregar(new CAsesino(asesino, escenario->get_arr()));


		aliados->Agregar(new CAliado(alia, Aleatorio, escenario->get_arr()));
		aliados->Agregar(new CAliado(alia, Aleatorio, escenario->get_arr()));
		aliados->Agregar(new CAliado(alia, Aleatorio, escenario->get_arr()));
		aliados->Agregar(new CAliado(alia, Aleatorio, escenario->get_arr()));
		aliados->Agregar(new CAliado(alia, Aleatorio, escenario->get_arr()));
		aliados->Agregar(new CAliado(alia, Aleatorio, escenario->get_arr()));
		aliados->Agregar(new CAliado(alia, Aleatorio, escenario->get_arr()));
		aliados->Agregar(new CAliado(alia, Aleatorio, escenario->get_arr()));
		aliados->Agregar(new CAliado(alia, Aleatorio, escenario->get_arr()));
		aliados->Agregar(new CAliado(alia, Escolta, escenario->get_arr()));
		aliados->Agregar(new CAliado(alia, Escolta, escenario->get_arr()));
		

		this->player = new CJugador(jg);
		hacer_transparente(porta);
		hacer_transparente(alia);
		hacer_transparente(corrupt);
		hacer_transparente(asesino);
		hacer_transparente(jg);
	}
	~CControladora()
	{
		delete this->escenario, player;
	}
	void MoverJugador(bool accion, Keys key)
	{
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
	int get_cont_corruptos() {
		return this->cont_corruptos;
	}
	bool Mover(Graphics^ g) 
	{
		if (tiempo - clock() <= 0)//cuando se acaba el time se sale del juego
		{
			ganar = false;
			return false;
		}

		player->Mover(g, escenario->get_arr());

		aliados->Mover(g, escenario->get_arr(), this->player);
		for (int i = 0; i < aliados->Size(); ++i)
		{
			if (player->hay_colision(aliados->Get(i)->Area()) && aliados->Get(i)->get_modo()==Aleatorio) {
				aliados->Eliminar(i);
				player->set_vidas(1);
			}
			if (nivel_2 == false) {
				if (aliados->Get(i)->get_modo() == Aleatorio) {
					enemigos->Mover(g, escenario->get_arr(), aliados->Get(i), nivel_2);
				}
				if (cont_kamikaze == max_kamizake)
				{
					enemigos->Mover(g, escenario->get_arr(), player, nivel_2);
				}
			}
			else
			{
				enemigos->Mover(g, escenario->get_arr(), player, nivel_2);
			}
			if (aliados->Colision(player) && aliados->Get(i)->get_modo() == Kamikaze && aliados->Get(i)->Area().IntersectsWith(player->Area())) {//aliados kamikaze colisionan con jugador
				
				player->set_vidas(-1);
				cont_kamikaze++;
				aliados->Eliminar(i);
				if (player->get_vidas() <= 0) {
					ganar = false;
					return false;
				}
			}
			for (int j = 0; j < enemigos->Size(); ++j)
			{
				if (enemigos->Colision(aliados->Get(i))) {

					if (enemigos->Get(j)->get_tipo() == assasins && nivel_2 == true && aliados->Get(i)->get_modo() == Aleatorio
						&& enemigos->Get(j)->Area().IntersectsWith(aliados->Get(i)->Area())) {
						aliados->Get(i)->set_modo(Kamikaze);
						enemigos->Eliminar(j);
					}
					if (enemigos->Get(j)->get_tipo() == corrupto && aliados->Get(i)->get_modo() == Aleatorio &&
						enemigos->Get(j)->Area().IntersectsWith(aliados->Get(i)->Area())) {
						cont_corruptos--;
						aliados->Get(i)->set_modo(Kamikaze);
						enemigos->Eliminar(j);
					}
				}
			}


		}
		if (player->Area().IntersectsWith(Rectangle((ANCHO - 2) * tamanho_bloque, (ALTO) * tamanho_bloque, tamanho_bloque, tamanho_bloque))) {//cuando llega a la meta
			ganar = true;
			return false;
		} //cuando el jugador llega al final
		
		if (enemigos->Colision(player))
		{
			for (int i = 0; i < enemigos->Size(); ++i)
			{
				if (enemigos->Get(i)->get_tipo() == corrupto && clock() - golpeEnemigo >= 3000 && player->Area().IntersectsWith(enemigos->Get(i)->Area())) {
						golpeEnemigo = clock();
						player->set_vidas(-1);
						enemigos->Eliminar(i);
						cont_corruptos--;
						if (player->get_vidas() <= 0) {
							ganar = false;
							return false;
						}
					
				}
				if (enemigos->Get(i)->get_tipo() == assasins && clock() - golpeEnemigo >= 3000 && player->Area().IntersectsWith(enemigos->Get(i)->Area())) {
					if (nivel_2==true) {
						golpeEnemigo = clock();
						player->set_vidas(-1);
						enemigos->Eliminar(i);
						if (player->get_vidas() <= 0) {
							ganar = false;
							return false;
						}
					}
				}
			}
		}
		return true;

	}
	int get_time() {
		return this->tiempo;
	}
	bool nivel2() {
		return nivel_2;
	}
	void set_nivel(bool value) {
		nivel_2 = value;
	}
	int get_kamikaze() {
		return this->cont_kamikaze;
	}
	void on_time_animacion() {
		this->time_animacion = 1000 * 13;
	}
	bool GetResultado()
	{
		return ganar;
	}
	void Mostrar(Graphics^ g)
	{
		escenario->empezar(g, this->bmpBase, this->bmpSolido);
		g->DrawString("Tiempo: " + ((tiempo - clock()+time_animacion) / 1000)+"   ", gcnew Font("Aral", 20), Brushes::Black, 150, 0);
		g->DrawString("Vidas: " + player->get_vidas()+"   ", gcnew Font("Aral", 20), Brushes::Red, 350, 0);
		
		if (nivel_2 == true) {//mostrar portales
			
			portal_1->mostrar_portal(g, porta);
			portal_2->mostrar_portal(g, porta);
			if (player->hay_colision(portal_1->Area()) == true && clock() - colddown_portal >= 3000) {//si jugador intersecta con el portal inicio se cambia el x y a la ubicacion del portal salida
				colddown_portal = clock();
				player->SetX(portal_2->GetX());
				player->SetY(portal_2->GetY());
			}
			if (player->hay_colision(portal_2->Area()) == true && clock() - colddown_portal >= 3000) {
				colddown_portal = clock();
				player->SetX(portal_1->GetX());
				player->SetY(portal_1->GetY());
			}
		}
		
		aliados->Mostrar(g, alia);
		enemigos->Mostrar(g, corrupt,nivel_2, asesino);
		player->Mostrar(g, jg);
	}
	void hacer_transparente(Bitmap^ img) {
		Color color = img->GetPixel(0, 0);  //Permite la transparencia
		img->MakeTransparent(color);
	}
};