#pragma once
#include"CControladora.h"
#include"Negociacion.h"
#include"CNegociacion.h"
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
	private: System::Windows::Forms::PictureBox^ pictureBox_win;
	private: System::Windows::Forms::PictureBox^ pictureBox_lose;
	public:
		CControladora^ controladora;
		bool animacion;
		Juego(void)
		{
			InitializeComponent();
			this->controladora= gcnew CControladora();
			animacion = false;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Juego::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox_win = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_lose = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_win))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_lose))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Juego::timer1_Tick);
			// 
			// pictureBox_win
			// 
			this->pictureBox_win->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox_win->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_win.Image")));
			this->pictureBox_win->Location = System::Drawing::Point(87, 50);
			this->pictureBox_win->Name = L"pictureBox_win";
			this->pictureBox_win->Size = System::Drawing::Size(800, 400);
			this->pictureBox_win->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox_win->TabIndex = 2;
			this->pictureBox_win->TabStop = false;
			this->pictureBox_win->Visible = false;
			// 
			// pictureBox_lose
			// 
			this->pictureBox_lose->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox_lose->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_lose.Image")));
			this->pictureBox_lose->Location = System::Drawing::Point(87, 50);
			this->pictureBox_lose->Name = L"pictureBox_lose";
			this->pictureBox_lose->Size = System::Drawing::Size(1000, 600);
			this->pictureBox_lose->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox_lose->TabIndex = 3;
			this->pictureBox_lose->TabStop = false;
			this->pictureBox_lose->Visible = false;
			// 
			// Juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(491, 303);
			this->Controls->Add(this->pictureBox_lose);
			this->Controls->Add(this->pictureBox_win);
			this->Name = L"Juego";
			this->Text = L"Juego";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_win))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_lose))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graficador = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(graficador, this->ClientRectangle);
		
		controladora->Mostrar(buffer->Graphics);
		buffer->Render(graficador);
		if (controladora->get_cont_corruptos()==0  && animacion==false) {//si pasa determinado tiempo mostrar la animacion
			timer1->Enabled = false;
			animacion = true;
			Negociacion^ nego = gcnew Negociacion();
			nego->ShowDialog();
			nego->Close();
			controladora->set_nivel(true);
			controladora->on_time_animacion();
			timer1->Enabled = true;
		}
		if(controladora->Mover(buffer->Graphics)==false){
			timer1->Enabled = false;
			if (controladora->GetResultado()==true) {
				pictureBox_win->Visible = true;
				MessageBox::Show("El Rey a escapado!!");
			}
			else {
				pictureBox_lose->Visible = true;
				MessageBox::Show("corruptos y asesinos ganaron");		
			}//this->timer1->Stop();
			this->Close();

		}
	}
	private: System::Void Juego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		controladora->MoverJugador(true, e->KeyCode);
	}
	private: System::Void Juego_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		controladora->MoverJugador(false, e->KeyCode);
	}
};
}
