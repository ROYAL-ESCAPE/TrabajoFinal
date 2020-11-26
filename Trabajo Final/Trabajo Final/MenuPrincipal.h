#pragma once
#include"Juego.h"
#include"Creditos.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
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
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}






	private: System::Windows::Forms::Button^ btn_salir;
	private: System::Windows::Forms::Button^ btn_creditos;
	private: System::Windows::Forms::Button^ btn_jugar;
	private: System::Windows::Forms::PictureBox^ pictureBox1;






	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->btn_salir = (gcnew System::Windows::Forms::Button());
			this->btn_creditos = (gcnew System::Windows::Forms::Button());
			this->btn_jugar = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_salir
			// 
			this->btn_salir->Location = System::Drawing::Point(236, 325);
			this->btn_salir->Name = L"btn_salir";
			this->btn_salir->Size = System::Drawing::Size(110, 37);
			this->btn_salir->TabIndex = 8;
			this->btn_salir->Text = L"Salir";
			this->btn_salir->UseVisualStyleBackColor = true;
			this->btn_salir->Click += gcnew System::EventHandler(this, &MenuPrincipal::Salir);
			// 
			// btn_creditos
			// 
			this->btn_creditos->Location = System::Drawing::Point(236, 261);
			this->btn_creditos->Name = L"btn_creditos";
			this->btn_creditos->Size = System::Drawing::Size(110, 37);
			this->btn_creditos->TabIndex = 7;
			this->btn_creditos->Text = L"Creditos";
			this->btn_creditos->UseVisualStyleBackColor = true;
			this->btn_creditos->Click += gcnew System::EventHandler(this, &MenuPrincipal::creditos);
			// 
			// btn_jugar
			// 
			this->btn_jugar->Location = System::Drawing::Point(235, 195);
			this->btn_jugar->Name = L"btn_jugar";
			this->btn_jugar->Size = System::Drawing::Size(111, 38);
			this->btn_jugar->TabIndex = 6;
			this->btn_jugar->Text = L"Jugar";
			this->btn_jugar->UseVisualStyleBackColor = true;
			this->btn_jugar->Click += gcnew System::EventHandler(this, &MenuPrincipal::jugar);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(114, 50);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(362, 68);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(575, 479);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btn_salir);
			this->Controls->Add(this->btn_creditos);
			this->Controls->Add(this->btn_jugar);
			this->Name = L"MenuPrincipal";
			this->Text = L"Royale Escape";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void jugar(System::Object^ sender, System::EventArgs^ e) {
		Juego^ juego = gcnew Juego();
		this->Visible = false;
		juego->ShowDialog();
		this->Visible = true;
	}
	private: System::Void creditos(System::Object^ sender, System::EventArgs^ e) {
		Creditos^ creditos = gcnew Creditos();
		creditos->ShowDialog();
	}
	private: System::Void Salir(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
};
}
