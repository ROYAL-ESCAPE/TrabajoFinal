#pragma once
#include<iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <string>
#include <queue>
#include"Jugador.h"
#define ANCHO 23
#define ALTO 13
#define tamanho_bloque 60
#define NDIR 4
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;


struct Ubicacion
{
    int F, C;

    Ubicacion()
    {
        F = C = 0;
    };

    Ubicacion(int r, int c)
    {
        F = r;
        C = c;
    };
};

class Nodo//casilla//celda
{
private:

    // posición actual
    int rPos;
    int cPos;

    // distancia total ya recorrida para llegar al nodo
    int GValue;

    // FValue = GValue + estimación de distancia restante
    int FValue;  // FValue más pequeño tiene prioridad

public:
    Nodo(const Ubicacion& loc, int g, int f)
    {
        rPos = loc.F; cPos = loc.C; GValue = g; FValue = f;

    }
    Ubicacion get_Ubicacion() const { return Ubicacion(rPos, cPos); }
    int get_G() const { return GValue; }
    int get_F() const { return FValue; }

    void calcular_valor_F(const Ubicacion& ubic_Destino)
    {
        FValue = GValue + get_H(ubic_Destino) * 10;
    }
    void actualizar_G(const int& i) // i: direction
    {
        GValue += (NDIR == 8 ? (i % 2 == 0 ? 10 : 14) : 10);
    }

    // Función de estimación de la distancia restante a la meta.
    const int& get_H(const Ubicacion& ubic_destino) const
    {
        static int rd, cd, d;
        rd = ubic_destino.F - rPos;
        cd = ubic_destino.C - cPos;

        // Euclidian Distance
        d = static_cast<int>(sqrt((double)(rd * rd + cd * cd)));

        // Manhattan distance
       // d = abs(rd) + abs(cd);

        // Chebyshev distance
        //d = max(abs(rd), abs(cd));

        return(d);
    }

    // Determinar el valor F (en la cola de prioridad)
    friend bool operator<(const Nodo& a, const Nodo& b)
    {
        return a.get_F() > b.get_F();
    }
};
enum MovimientoPersonaje
{
	CaminarAbajo,
	CaminarIzquierda,
	CaminarDerecha,
	CaminarArriba,
};

class Entidad abstract{ //TODOS NUESTROS PERSONAJES
protected:
    int x, y;		 //Posicion
    int ancho, alto; //Tamaño
    int ancho_recorte, alto_recorte;
	int dx, dy;		//Velocidad
	int IDx;
	MovimientoPersonaje accion;

public:
	Entidad(Bitmap^ img)
	{
		x = y = 0;
		dx = dy = 0;
		IDx = 0;
        this->ancho_recorte = this->alto_recorte = 0;
        this->ancho = this->alto =tamanho_bloque;
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
		return ancho;}
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
        return Rectangle(x, y, ancho, alto);//modifica los tamaños de las img
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
		if (y + dy >= 0 && y + dy + alto < (ALTO+1)*tamanho_bloque) {
			y += dy;
		}
	}
	virtual void Mostrar(Graphics^ g, Bitmap^ img)
	{
		Rectangle corte = Rectangle(IDx * ancho_recorte, accion * alto_recorte, ancho_recorte, alto_recorte);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
        if (dx != 0 || dy != 0)
		IDx = (IDx + 1) % 3;
	}
	Rectangle NextArea()
	{
		return Rectangle(x + dx, y + dy, ancho, alto);//tamaño de la img para hacer la funcion colision
	}
    bool hay_colision(Rectangle area) {
        if (this->Area().IntersectsWith(area)) {
            return true;
        }
        return false;
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

class Cportales :public Entidad {
private:
    int tipo;
public:
    Cportales(Bitmap^ img, vector<vector<int>> matriz, int tipo) :Entidad(img) {
        srand(time(NULL));
        this->tipo = tipo;//tipo 1 entrada//tipo 2 salida
        if (tipo==1) {//si es entrada
            do
            {
                this->x = rand() % (ANCHO/2);
                this->y = rand() % (ALTO/2);
            } while ((matriz[this->y][this->x] != 0));
        }
        else//la salida
        {
            do
            {
                this->x = rand() % (ANCHO/2) + ANCHO/2;
                this->y = rand() % (ALTO/2)+ALTO/2;
            } while ((matriz[this->y][this->x] != 0));
        }
        this->x *= tamanho_bloque;
        this->y *= tamanho_bloque;
        ancho = alto = tamanho_bloque;
        this->ancho_recorte = img->Width/4;
        this->alto_recorte = img->Height;
        this->IDx = 0;
        dx = dy = 0;
    }
    void mostrar_portal(Graphics^ g, Bitmap^ img)
    {
        Rectangle corte = Rectangle( IDx*ancho_recorte,  0, ancho_recorte, alto_recorte);
        g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
       
        //if (dx != 0 || dy != 0)
        IDx = (IDx + 1) % 4;
    }
};

class NPC abstract: public Entidad{
protected:
    int velocidad;

 public:

    int i_dir[NDIR] = { 1, 0, -1, 0 };
    int j_dir[NDIR] = { 0, 1, 0, -1 };
    // lista de nodos cerrados (de salida)
    int nodos_cerrados[ALTO][ANCHO];//matriz nodos cerrados

    // lista de nodos abiertos (aún no extraídos)
    int nodos_abiertos[ALTO][ANCHO];//matriz nodos abierto

    // mapa de direcciones (0: Este, 1: Norte, 2: Oeste, 3: Sur)
    int dir_mapa[ALTO][ANCHO];//matriz de dirreciones del mapa

 public:
     NPC(Bitmap^ img) : Entidad(img) {
     
     }

    string Encontrar_camino(const Ubicacion& ubic_inicio, const Ubicacion& ubic_final, vector<vector<int>> arr){
        //pasa por parametro la pos inicial y final 
        // lista de nodos abiertos (aún no extraídos)
        static priority_queue <Nodo> q[2];//una clase contenedora que contiene una clase contenedora

        // q índice
        static int qi;

        static Nodo* p_nodo1;//puntero de clase Nodo
        static Nodo* p_nodo2;//puntero de clase Nodo
        static int i, j, fila, columna, i_siguiente, j_siguiente;
        static char c;
        qi = 0;

        // restablecer las listas de nodos 
        for (j = 0; j < ANCHO; j++) {
            for (i = 0; i < ALTO; i++) {
                nodos_cerrados[i][j] = 0;
                nodos_abiertos[i][j] = 0;
            }
        }

        // crear el nodo de inicio y enviarlo a la lista de nodos abiertos
        p_nodo1 = new Nodo(ubic_inicio, 0, 0);
        p_nodo1->calcular_valor_F(ubic_final);
        q[qi].push(*p_nodo1);

        // A* search
        while (!q[qi].empty()) {
            // obtener el nodo actual con el FValue más bajo
            // de la lista de nodos abiertos
            p_nodo1 = new Nodo(q[qi].top().get_Ubicacion(),
                q[qi].top().get_G(), q[qi].top().get_F());

            fila = (p_nodo1->get_Ubicacion()).F;
            columna = p_nodo1->get_Ubicacion().C;

            // eliminar el nodo de la lista abierta
            q[qi].pop();
            nodos_abiertos[fila][columna] = 0;

            // márquelo en la lista de nodos cerrados
            nodos_cerrados[fila][columna] = 1;

            //dejar de buscar cuando se alcance el estado objetivo
            if (fila == ubic_final.F && columna == ubic_final.C) {


                // generar la ruta desde el final hasta el inicio desde dirMap
                string Camino = "";
                while (!(fila == ubic_inicio.F && columna == ubic_inicio.C)) {//mientras no este en la pos de inicio
                    j = dir_mapa[fila][columna];
                    c = '0' + (j + NDIR / 2) % NDIR;
                    Camino = c + Camino;
                    fila += i_dir[j];
                    columna += j_dir[j];
                }

                // recolección de basura
                delete p_nodo1;

                // vaciar los nodos sobrantes
                while (!q[qi].empty()) q[qi].pop();
                return Camino;
            }

            // generar movimientos en todas las direcciones posibles
            for (i = 0; i < NDIR; i++) {
                i_siguiente = fila + i_dir[i];
                j_siguiente = columna + j_dir[i];

                // si no es muro (obstáculo) ni en la lista cerrada
                if (!(i_siguiente < 0 || i_siguiente > ALTO - 1 || j_siguiente < 0 || j_siguiente > ANCHO - 1 ||
                    arr[i_siguiente][j_siguiente] == 1 || nodos_cerrados[i_siguiente][j_siguiente] == 1)) {

                    // generar un nodo hijo
                    p_nodo2 = new Nodo(Ubicacion(i_siguiente, j_siguiente), p_nodo1->get_G(), p_nodo1->get_F());
                    p_nodo2->actualizar_G(i);
                    p_nodo2->calcular_valor_F(ubic_final);

                    // si no está en la lista abierta, agréguelo
                    if (nodos_abiertos[i_siguiente][j_siguiente] == 0) {
                        nodos_abiertos[i_siguiente][j_siguiente] = p_nodo2->get_F();
                        q[qi].push(*p_nodo2);
                        // marcar la dirección de su nodo padre/principal
                        dir_mapa[i_siguiente][j_siguiente] = (i + NDIR / 2) % NDIR;
                    }

                    // ya en la lista abierta
                    else if (nodos_abiertos[i_siguiente][j_siguiente] > p_nodo2->get_F()) {
                        //actualizar la información de FValue
                        nodos_abiertos[i_siguiente][j_siguiente] = p_nodo2->get_F();

                        // actualizar la información de la dirección principal, marcar la dirección del nodo principal/padre
                        dir_mapa[i_siguiente][j_siguiente] = (i + NDIR / 2) % NDIR;

                        // Reemplazar el nodo vaciando uno q al otro
                        // excepto que el nodo a reemplazar será ignorado
                        // y el nuevo nodo se insertará en su lugar
                        while (!(q[qi].top().get_Ubicacion().F == i_siguiente &&
                            q[qi].top().get_Ubicacion().C == j_siguiente)) {
                            q[1 - qi].push(q[qi].top());
                            q[qi].pop();
                        }

                        // eliminar el nodo deseado
                        q[qi].pop();

                        // vaciar el tamaño q más grande al más pequeño
                        if (q[qi].size() > q[1 - qi].size()) qi = 1 - qi;
                        while (!q[qi].empty()) {
                            q[1 - qi].push(q[qi].top());
                            q[qi].pop();
                        }
                        qi = 1 - qi;

                        // agregue el mejor nodo en su lugar
                        q[qi].push(*p_nodo2);
                    }
                    else delete p_nodo2;
                }

            }
            delete p_nodo1;
        }
        //no se encontró camino
        return "";
    }
    
	virtual void seguir(Graphics^ g,int x_inicial,  int y_inicial, int x_final, int y_final, vector<vector<int>> arr,Entidad* seguidor, Entidad* objetivo) {//posiciones del jugador
        if (seguidor->NextArea().IntersectsWith(objetivo->Area())==false) {//solo entra a la funcion si su distancia es mayor a uno
             string camino=Encontrar_camino(Ubicacion(y_inicial, x_inicial), Ubicacion(y_final, x_final), arr);
             char c;
             int m, n;
             int i = y_inicial;//guarda las pos iniciales en i y j
             int j = x_inicial;//guarda las pos iniciales en i y j
             c = camino.at(0);//devuelve el caracter en la pos m de la cadena path
             n = atoi(&c);//sirve para darle a n el valor en numero de c que es un caracter
             i = i + i_dir[n];//y
             j = j + j_dir[n];//x
             if (i_dir[n] == 1 && j_dir[n] == 0) {
                 accion = CaminarAbajo;
                 dy = +velocidad;
                 dx = 0;
             }
             if (i_dir[n] == 0 && j_dir[n] == 1) {
                 accion = CaminarDerecha;
                 dx = +velocidad;
                 dy = 0;
             }
             if (i_dir[n] == -1 && j_dir[n] == 0) {
                 accion = CaminarArriba;
                 dy = -velocidad;
                 dx = 0;
             }
             if (i_dir[n] == 0 && j_dir[n] == -1) {
                 accion = CaminarIzquierda;
                 dx = -velocidad;
                 dy = 0;
             }
        }
    }
};