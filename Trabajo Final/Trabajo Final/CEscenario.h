#pragma once
#include<ctime>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include"Jugador.h"
#define ANCHO 23
#define ALTO 13
#define tamanho_bloque 60
using namespace System::Drawing;
using namespace std;
class CEscenario {
    vector<vector<int>> matriz;
    vector<vector<int> > pila;
    vector<vector<int> > vecinos;
    int columna;
    int fila;
    vector<int> sig;
    int contador;
public:
    CEscenario() {
        this->contador = 1;
        this->matriz = {};
        this->pila = {};
        this->vecinos = {};
        this->columna = 1;
        this->fila = 1;
        this->sig = {};
        //realizamos todo el algoritmo en el contructor xq solo se genera una vez, no necesita de un timer
        matriz.resize(ALTO);//alto=9 -> arr tiene 7 espacios
                        //cambia el tamaño del vector a alto//el vector arr. esta vacio, entonces lo que hace es darle tamaño de "alto"
        for (int j = 0; j < ALTO; j++) {//alto=7
            matriz[j].resize(ANCHO);//dentro de los 7 espacios del vector ingreso 1 vector de 9 espacios por cada espacio
            // es decir una matriz de 9*7
            for (int i = 0; i < ANCHO; i++) {//ancho = 9
                if (j % 2 == 1 && i % 2 == 1) {//si las coordenadas son impares entra en el if
                    matriz[j][i] = 0;
                 
                }
                else if ((j == 0 && i == 1) || (j == ALTO - 1 && i == ANCHO - 2)) {//para las posiciones de inicio y fin del laberinto
                    matriz[j][i] = 0;
                }
                else {
                    matriz[j][i] = 1;
                 
                }
            }
    
        }

       
        //punto de partida de la creación del laberinto mediante búsqueda en profundidad y retroceso recursivo
        matriz[fila][columna] = 2;//marco la posiscion inicial como visitasa que lo represento con el # 2
        pila.push_back({ fila,columna });//guardo en la pila(vector) el par de coordenadas que estoy recorriendo

  
        //comienza el algoritm
        algoritmo(contador);//pase por referencia del contador, q tiene valor de 1

 
        cout << "\n\n";
    }
    ~CEscenario()
    {
        
    }
    int algoritmo(int& contador) {//funcion del algoritmo
        vecinos.clear();//elimina todos los elementos del vector//el vector neigh me sirve para guardar el par de coordenadas posibles
        // contador para finalizar la llamada recursiva rápidamente
        if (contador >= (ALTO / 2) * (ANCHO / 2)) { return 0; }// normalmente seria h*w, pero como son habitaciones es decir que por cada 3*3 casillas, en el centro es vacio(sin un b)
        //si ese es el caso sale de la funcion
  
        //validaciones para coord posibles, evitando que salga de la matriz o vector de vector
        if (fila + 2 < ALTO - 1 && matriz[fila + 2][columna] == 0) {
            vecinos.push_back({ fila + 2,columna });//abajo
        }
        if (fila - 2 > 0 && matriz[fila - 2][columna] == 0) {
            vecinos.push_back({ fila - 2,columna });//arriba
        }
        if (columna + 2 < ANCHO - 1 && matriz[fila][columna + 2] == 0) {
            vecinos.push_back({ fila,columna + 2 });//derecha
        }
        if (columna - 2 > 0 && matriz[fila][columna - 2] == 0) {
            vecinos.push_back({ fila,columna - 2 });//izquierda
        }
      
        if (vecinos.size() > 0) {//si el tamaño del array vecino es mayor a 0
            sig.clear();//limpio el vector xq lo voy a volver a usar
            sig = vecinos[rand() % vecinos.size()];//elegio aleatoriamente la sig pos
            //marcarlo como visitado
            matriz[sig[0]][sig[1]] = 2;//marcar como visitado la sig posicion
            //contador para saber si ya se han visitado todas las celdas
            contador++;//contador de visitados
            //empujar a la pila//donde se guarda las posiciones donde a estado, pero de inicio a fin
            pila.push_back(sig);//arr2 es donde se guarda las posiciones de la pila, es decir la resolucion
            //quitar las paredes//1==poner pared//2==posicion actual || marcar como visitado
            if (columna - sig[1] < 0) {//si la columna anterios es menor a la actual
                matriz[fila][columna + 1] = 0;//derecha
                columna += 2;//muevo la columna a la posicion actual//solo columna xq es un movimiento y en este caso es horizontal
                algoritmo(contador);//vuelvo a llamas a la funcion
            }
            else if (columna - sig[1] > 0) {
                matriz[fila][columna - 1] = 0;//izq
                columna -= 2; algoritmo(contador);
            }
            else if (fila - sig[0] < 0) {
                matriz[fila + 1][columna] = 0;//arriba
                fila += 2; algoritmo(contador);
            }
            else if (fila - sig[0] > 0) {
                matriz[fila - 1][columna] = 0;//abajo
                fila -= 2; algoritmo(contador);
            }

        }
        //==== backtrack//retroceder
        else if (pila.size() > 0) {//si la pila de camino es mayor a cero
            pila.pop_back();//retrocedo en la pila eliminando el ultimo (coordenada o pos)
            fila = pila[pila.size() - 1][0];//le doy el valor de la fila de la coord anterior
            columna = pila[pila.size() - 1][1];//le doy el valor de la columna de la coor anterios de la pila
            algoritmo(contador);
        }
    }

    //separador//
    vector<vector<int>> get_arr() {
        return matriz;
    }

    void empezar(Graphics^ g, Bitmap^ bmpBase, Bitmap^ bmpSolido) {//dibujar
       
       
        int X, Y = 0;
        for (int j = 0; j < ALTO; j++) {
            X = 0;
            for (int i = 0; i < ANCHO; i++) {
                if (matriz[j][i] == 1) {//paredes
                    g->DrawImage(bmpSolido, X, Y, tamanho_bloque, tamanho_bloque);
                   
                }
                else if (j == 0 && i == 1) {//pos donde es la salida
                  
                }
                else if (j == ALTO - 1 && i == ANCHO - 2) {//pos donde es la entrada
                    
                }
                else {
                    if (matriz[j][i] == 2) {//pos donde es el camino, es decir no tiene caracter, entonce le doy valor de 0 para que luego durante el for no entre a ninguna condicional y muestre un espacio vacio//que representa el camino
                        matriz[j][i] = 0;
                    }
                    g->DrawImage(bmpBase, X, Y, tamanho_bloque, tamanho_bloque);
                   
                }
                X += tamanho_bloque;
            }
            Y += tamanho_bloque;
         
        }
    }
    
};