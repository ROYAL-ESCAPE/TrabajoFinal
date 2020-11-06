#pragma once
#include"CEscenario.h"
ref class CControladora
{
private:
	CEscenario^ escenario;
public:
	CControladora() {
		escenario = gcnew CEscenario();
	}
	~CControladora()
	{

	}
	void CambiarNivel() {
		escenario->generarMatriz();
	}
	void dibujar(Graphics^ graficador, Bitmap^ bmpBase, Bitmap^ bmpSolido, Bitmap^ bmpDestruible) {
		escenario->PintarBase(graficador, bmpBase);
		escenario->PintarMatriz(graficador, bmpSolido, bmpDestruible);
	}
};


