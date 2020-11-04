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
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ btn_instrucciones_aparecer;
	private: System::Windows::Forms::Button^ btn_instrucciones_desaparecer;
	private: System::Windows::Forms::PictureBox^ pictureBox3;


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
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_instrucciones_aparecer = (gcnew System::Windows::Forms::Button());
			this->btn_instrucciones_desaparecer = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_salir
			// 
			this->btn_salir->Location = System::Drawing::Point(595, 363);
			this->btn_salir->Margin = System::Windows::Forms::Padding(4);
			this->btn_salir->Name = L"btn_salir";
			this->btn_salir->Size = System::Drawing::Size(131, 42);
			this->btn_salir->TabIndex = 8;
			this->btn_salir->Text = L"Salir";
			this->btn_salir->UseVisualStyleBackColor = true;
			this->btn_salir->Click += gcnew System::EventHandler(this, &MenuPrincipal::Salir);
			// 
			// btn_creditos
			// 
			this->btn_creditos->Location = System::Drawing::Point(590, 283);
			this->btn_creditos->Margin = System::Windows::Forms::Padding(4);
			this->btn_creditos->Name = L"btn_creditos";
			this->btn_creditos->Size = System::Drawing::Size(131, 45);
			this->btn_creditos->TabIndex = 7;
			this->btn_creditos->Text = L"Creditos";
			this->btn_creditos->UseVisualStyleBackColor = true;
			this->btn_creditos->Click += gcnew System::EventHandler(this, &MenuPrincipal::creditos);
			// 
			// btn_jugar
			// 
			this->btn_jugar->Location = System::Drawing::Point(585, 142);
			this->btn_jugar->Margin = System::Windows::Forms::Padding(4);
			this->btn_jugar->Name = L"btn_jugar";
			this->btn_jugar->Size = System::Drawing::Size(148, 47);
			this->btn_jugar->TabIndex = 6;
			this->btn_jugar->Text = L"Jugar";
			this->btn_jugar->UseVisualStyleBackColor = true;
			this->btn_jugar->Click += gcnew System::EventHandler(this, &MenuPrincipal::jugar);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->Location = System::Drawing::Point(499, 61);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(327, 51);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MenuPrincipal::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox2->Location = System::Drawing::Point(977, 61);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(192, 128);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 10;
			this->pictureBox2->TabStop = false;
			// 
			// btn_instrucciones_aparecer
			// 
			this->btn_instrucciones_aparecer->Location = System::Drawing::Point(595, 219);
			this->btn_instrucciones_aparecer->Margin = System::Windows::Forms::Padding(4);
			this->btn_instrucciones_aparecer->Name = L"btn_instrucciones_aparecer";
			this->btn_instrucciones_aparecer->Size = System::Drawing::Size(136, 37);
			this->btn_instrucciones_aparecer->TabIndex = 11;
			this->btn_instrucciones_aparecer->Text = L"Instrucciones";
			this->btn_instrucciones_aparecer->UseVisualStyleBackColor = true;
			this->btn_instrucciones_aparecer->Click += gcnew System::EventHandler(this, &MenuPrincipal::btn_instrucciones_aparecer_Click);
			// 
			// btn_instrucciones_desaparecer
			// 
			this->btn_instrucciones_desaparecer->Location = System::Drawing::Point(597, 219);
			this->btn_instrucciones_desaparecer->Margin = System::Windows::Forms::Padding(4);
			this->btn_instrucciones_desaparecer->Name = L"btn_instrucciones_desaparecer";
			this->btn_instrucciones_desaparecer->Size = System::Drawing::Size(136, 37);
			this->btn_instrucciones_desaparecer->TabIndex = 12;
			this->btn_instrucciones_desaparecer->Text = L"Instrucciones";
			this->btn_instrucciones_desaparecer->UseVisualStyleBackColor = true;
			this->btn_instrucciones_desaparecer->Click += gcnew System::EventHandler(this, &MenuPrincipal::btn_instrucciones_desaparecer_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->Location = System::Drawing::Point(951, 219);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(256, 171);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 13;
			this->pictureBox3->TabStop = false;
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1262, 673);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->btn_instrucciones_desaparecer);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btn_salir);
			this->Controls->Add(this->btn_creditos);
			this->Controls->Add(this->btn_jugar);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->btn_instrucciones_aparecer);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MenuPrincipal";
			this->Text = L"Royale Escape";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void jugar(System::Object^ sender, System::EventArgs^ e) {
		Juego^ juego = gcnew Juego();
		juego->ShowDialog();
		Close();
	}
	private: System::Void creditos(System::Object^ sender, System::EventArgs^ e) {
		Creditos^ creditos = gcnew Creditos();
		creditos->ShowDialog();
	}
	private: System::Void Salir(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
	private: System::Void btn_instrucciones_desaparecer_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Width = 572;
		btn_instrucciones_desaparecer->Visible = false;
		btn_instrucciones_aparecer->Visible = true;
	}
	private: System::Void btn_instrucciones_aparecer_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Width = 980;
		btn_instrucciones_desaparecer->Visible = true;
		btn_instrucciones_aparecer->Visible = false;
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
