#pragma once
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
ref class C_Imagen_N {
protected:
	Rectangle area_dibujo;
	Bitmap^ img;

public:
	C_Imagen_N(String^ ruta, Rectangle area) {
		this->area_dibujo = area;
		this->img = gcnew Bitmap(ruta);
	}
	~C_Imagen_N() {
		delete img;
	}
	virtual void Dibujar(Graphics^ graficador) {
		graficador->DrawImage(img, area_dibujo);
	}
	void hacer_transparente() {
		Color color1 = img->GetPixel(1, 1);  //Permite la transparencia
		img->MakeTransparent(color1);
	}

};
ref class Corrupto_N : public C_Imagen_N {
	int idx, idy;
	int tiempo;
public:
	Corrupto_N(String^ ruta, Rectangle area) : C_Imagen_N(ruta, area) {
		idx = 0;
		idy = 2;
		this->tiempo = 0;
	}
	~Corrupto_N() {}
	void Mover() {
		int v = 5;
		if (this->tiempo <= 3000) {
			this->area_dibujo.X += v;
			idx = (idx + 1) % 3;
		}
	}
	int get_tiempo() { return this->tiempo; }
	void set_tiempo() {
		this->tiempo += 100;
	}
	void Dibujar(Graphics^ graficador)override {
		Rectangle area_recorte = Rectangle(img->Width / 3 * idx, img->Height / 4 * idy, img->Width / 3, img->Height / 4);
		graficador->DrawImage(img, area_dibujo, area_recorte, GraphicsUnit::Pixel);
	}
	void Conversacion(Graphics^ graficador)
	{
		if (3000 < this->tiempo && this->tiempo < 6000)
		{
			graficador->DrawString("Asesinos, necesitamos su ayuda! ",
				gcnew Font("Arial", 20),
				gcnew SolidBrush(Color::Blue),
				Rectangle(area_dibujo.X, area_dibujo.Y - 60, 300, 60));
		}
		else if (9000 < this->tiempo && this->tiempo < 12000)
		{
			graficador->DrawString("Al rey. ",
				gcnew Font("Arial", 20),
				gcnew SolidBrush(Color::Blue),
				Rectangle(area_dibujo.X, area_dibujo.Y - 60, 300, 60));
		}
	}
};
ref class Asesino_N : public C_Imagen_N {
	int tiempo;
public:
	Asesino_N(String^ ruta, Rectangle area) : C_Imagen_N(ruta, area) {

	}
	~Asesino_N() {}
	void Dibujar(Graphics^ graficador) override {
		int ancho = img->Width / 3;
		int alto = img->Height / 4;
		Rectangle area_recorte = Rectangle(ancho * 1, alto * 1, ancho, alto);
		graficador->DrawImage(img, area_dibujo, area_recorte, GraphicsUnit::Pixel);
	}
	void Conversacion(Graphics^ graficador)
	{
		if (6000 < this->tiempo && this->tiempo < 9000)
		{
			graficador->DrawString("A quien tenemos que matar? ",
				gcnew Font("Arial", 20),
				gcnew SolidBrush(Color::Blue),
				Rectangle(area_dibujo.X, area_dibujo.Y - 60, 300, 60));
		}
	}
	int get_tiempo() { return this->tiempo; }
	void set_tiempo() {
		this->tiempo += 100;
	}
};