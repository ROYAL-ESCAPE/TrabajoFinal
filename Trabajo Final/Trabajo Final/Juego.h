#pragma once
#include"CControladora.h"
namespace TrabajoFinal {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Resumen de Juego
	/// </summary>
	public ref class Juego : public System::Windows::Forms::Form
	{
	public:
		CControladora^ controladora = gcnew CControladora();
		Bitmap^ bmpSolido = gcnew Bitmap("MATERIALES//ladrillo2.png");
		Bitmap^ bmpBase = gcnew Bitmap("MATERIALES//grass.png");
		Bitmap^ bmpDestruible = gcnew Bitmap("MATERIALES//Ladrillo1.png");
		Juego(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Juego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Juego::timer1_Tick);
			// 
			// Juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1262, 673);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Juego";
			this->Text = L"Juego";
			this->Load += gcnew System::EventHandler(this, &Juego::Juego_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graficador = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(graficador, this->ClientRectangle);
		//controladora->CambiarNivel();
		controladora->dibujar(buffer->Graphics, bmpBase, bmpSolido, bmpDestruible);
		buffer->Render(graficador);
		delete buffer, espacio, graficador;
	}
	};
}
