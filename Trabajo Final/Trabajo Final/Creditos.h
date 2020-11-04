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
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
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
			this->pictureBox1->Location = System::Drawing::Point(1106, 21);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(120, 107);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// txt_title_creditos
			// 
			this->txt_title_creditos->AutoSize = true;
			this->txt_title_creditos->BackColor = System::Drawing::Color::Transparent;
			this->txt_title_creditos->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_title_creditos->ForeColor = System::Drawing::Color::Cornsilk;
			this->txt_title_creditos->Location = System::Drawing::Point(576, 21);
			this->txt_title_creditos->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->txt_title_creditos->Name = L"txt_title_creditos";
			this->txt_title_creditos->Size = System::Drawing::Size(178, 58);
			this->txt_title_creditos->TabIndex = 1;
			this->txt_title_creditos->Text = L"Creditos";
			this->txt_title_creditos->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox2_atras
			// 
			this->pictureBox2_atras->Location = System::Drawing::Point(28, 15);
			this->pictureBox2_atras->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox2_atras->Name = L"pictureBox2_atras";
			this->pictureBox2_atras->Size = System::Drawing::Size(79, 64);
			this->pictureBox2_atras->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2_atras->TabIndex = 2;
			this->pictureBox2_atras->TabStop = false;
			this->pictureBox2_atras->Click += gcnew System::EventHandler(this, &Creditos::pictureBox2_atras_Click);
			// 
			// Creditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1262, 673);
			this->Controls->Add(this->pictureBox2_atras);
			this->Controls->Add(this->txt_title_creditos);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
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
