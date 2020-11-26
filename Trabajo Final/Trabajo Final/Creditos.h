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

	protected:
	private: System::Windows::Forms::Label^ txt_title_creditos;
	private: System::Windows::Forms::Label^ label1;


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
			this->txt_title_creditos = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txt_title_creditos
			// 
			this->txt_title_creditos->AutoSize = true;
			this->txt_title_creditos->BackColor = System::Drawing::Color::Transparent;
			this->txt_title_creditos->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_title_creditos->ForeColor = System::Drawing::Color::Cornsilk;
			this->txt_title_creditos->Location = System::Drawing::Point(432, 17);
			this->txt_title_creditos->Name = L"txt_title_creditos";
			this->txt_title_creditos->Size = System::Drawing::Size(145, 47);
			this->txt_title_creditos->TabIndex = 1;
			this->txt_title_creditos->Text = L"Creditos";
			this->txt_title_creditos->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(201, 274);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(670, 132);
			this->label1->TabIndex = 3;
			this->label1->Text = L"u202013066 Christian Joel Cutipa Cañapataña \r\nu201721662 Jairo Andree Alvarez San"
				L"chez \r\nu202012087 Omar David Valle Guzmán \r\nu20201a291 Cristopher Rondon Añaños";
			// 
			// Creditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(946, 547);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txt_title_creditos);
			this->Name = L"Creditos";
			this->Text = L"Creditos";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox2_atras_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	};
}
