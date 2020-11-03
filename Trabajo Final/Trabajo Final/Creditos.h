#pragma once

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Creditos
	/// </summary>
	public ref class Creditos : public System::Windows::Forms::Form
	{
	public:
		Creditos(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~Creditos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Label^ txt_title_creditos;
	private: System::Windows::Forms::PictureBox^ pictureBox2_atras;

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Creditos::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->txt_title_creditos = (gcnew System::Windows::Forms::Label());
			this->pictureBox2_atras = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2_atras))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(478, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(90, 87);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// txt_title_creditos
			// 
			this->txt_title_creditos->AutoSize = true;
			this->txt_title_creditos->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_title_creditos->Location = System::Drawing::Point(239, 27);
			this->txt_title_creditos->Name = L"txt_title_creditos";
			this->txt_title_creditos->Size = System::Drawing::Size(119, 27);
			this->txt_title_creditos->TabIndex = 1;
			this->txt_title_creditos->Text = L"Creditos";
			this->txt_title_creditos->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox2_atras
			// 
			this->pictureBox2_atras->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2_atras.Image")));
			this->pictureBox2_atras->Location = System::Drawing::Point(21, 12);
			this->pictureBox2_atras->Name = L"pictureBox2_atras";
			this->pictureBox2_atras->Size = System::Drawing::Size(59, 52);
			this->pictureBox2_atras->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2_atras->TabIndex = 2;
			this->pictureBox2_atras->TabStop = false;
			this->pictureBox2_atras->Click += gcnew System::EventHandler(this, &Creditos::pictureBox2_atras_Click);
			// 
			// Creditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(580, 363);
			this->Controls->Add(this->pictureBox2_atras);
			this->Controls->Add(this->txt_title_creditos);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Creditos";
			this->Text = L"Creditos";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2_atras))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox2_atras_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		
	};
}
