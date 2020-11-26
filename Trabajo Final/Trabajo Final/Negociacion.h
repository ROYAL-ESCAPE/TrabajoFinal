#pragma once
#include"CNegociacion.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Negociacion
	/// </summary>
	public ref class Negociacion : public System::Windows::Forms::Form
	{
		C_Imagen_N^ fondo;
		Corrupto_N^ corrupto;
		Asesino_N^ assasins;
		BufferedGraphics^ buffer;

	private: System::Windows::Forms::Timer^ timer1;
	public:
		Negociacion(void)
		{
			InitializeComponent();
			this->fondo = gcnew C_Imagen_N("MATERIALES\\Fondo_negociacion.png", this->ClientRectangle);
			this->corrupto = gcnew Corrupto_N("MATERIALES\\corrupt.png", Rectangle(0, 400, 100, 100));
			this->assasins = gcnew Asesino_N("MATERIALES\\assasin.png", Rectangle(500, 400, 100, 100));
			this->buffer = BufferedGraphicsManager::Current->Allocate(this->CreateGraphics(), this->ClientRectangle);
			this->corrupto->hacer_transparente();
			this->assasins->hacer_transparente();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Negociacion()
		{
			if (components)
			{
				delete components;
			}
			delete buffer;
			delete fondo;
			delete corrupto;
			delete assasins;
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

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
			this->timer1->Tick += gcnew System::EventHandler(this, &Negociacion::Animacion);
			// 
			// Negociacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(836, 554);
			this->Name = L"Negociacion";
			this->Text = L"Negociacion";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Animacion(System::Object^ sender, System::EventArgs^ e) {

		this->fondo->Dibujar(buffer->Graphics);
		this->corrupto->Dibujar(buffer->Graphics);
		this->assasins->Dibujar(buffer->Graphics);
		this->corrupto->Mover();
		this->corrupto->Conversacion(buffer->Graphics);
		this->assasins->Conversacion(buffer->Graphics);
		this->assasins->set_tiempo();
		this->corrupto->set_tiempo();
		if (this->assasins->get_tiempo() > 13000) {
			this->timer1->Stop();
			this->Close();
		}
		buffer->Render();
	}
	};
}