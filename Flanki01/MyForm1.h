#pragma once

#include "Game.h"
//#include "Contestant.h"

namespace Flanki01 {
	Game* game = new Game();							/////////////////////////////////////////////
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		//Game* game = new Game();
		MyForm1(void)
		{
			InitializeComponent();
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->ForeColor = System::Drawing::Color::Peru;
			this->button1->Location = System::Drawing::Point(167, 34);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(250, 100);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Graj";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button2->ForeColor = System::Drawing::Color::Peru;
			this->button2->Location = System::Drawing::Point(167, 211);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(250, 100);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Ustawienia";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button3->ForeColor = System::Drawing::Color::Peru;
			this->button3->Location = System::Drawing::Point(167, 408);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(250, 100);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Wyjœcie";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Location = System::Drawing::Point(91, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(609, 539);
			this->panel1->TabIndex = 3;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->Controls->Add(this->button13);
			this->panel2->Controls->Add(this->button10);
			this->panel2->Controls->Add(this->button9);
			this->panel2->Controls->Add(this->button8);
			this->panel2->Controls->Add(this->button7);
			this->panel2->Controls->Add(this->button6);
			this->panel2->Controls->Add(this->button5);
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->button11);
			this->panel2->Controls->Add(this->button12);
			this->panel2->Location = System::Drawing::Point(164, 92);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(455, 368);
			this->panel2->TabIndex = 4;
			this->panel2->Visible = false;
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(362, 328);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(75, 23);
			this->button13->TabIndex = 9;
			this->button13->Text = L"button13";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm1::button13_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(267, 233);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(91, 86);
			this->button10->TabIndex = 8;
			this->button10->Text = L"button10";
			this->button10->UseVisualStyleBackColor = false;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(145, 233);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(91, 86);
			this->button9->TabIndex = 7;
			this->button9->Text = L"button9";
			this->button9->UseVisualStyleBackColor = false;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(25, 233);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(86, 86);
			this->button8->TabIndex = 6;
			this->button8->Text = L"button8";
			this->button8->UseVisualStyleBackColor = false;
			// 
			// button7
			// 
			this->button7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.BackgroundImage")));
			this->button7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button7->Location = System::Drawing::Point(267, 131);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(91, 86);
			this->button7->TabIndex = 5;
			this->button7->Text = L"button7";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm1::button7_Click);
			// 
			// button6
			// 
			this->button6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.BackgroundImage")));
			this->button6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button6->Location = System::Drawing::Point(145, 131);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(91, 86);
			this->button6->TabIndex = 4;
			this->button6->Text = L"button6";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm1::button6_Click);
			// 
			// button5
			// 
			this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button5->Location = System::Drawing::Point(25, 131);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(86, 86);
			this->button5->TabIndex = 3;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm1::button5_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::Control;
			this->button4->Location = System::Drawing::Point(267, 38);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(91, 37);
			this->button4->TabIndex = 2;
			this->button4->Text = L"button4";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::SystemColors::Control;
			this->button11->Location = System::Drawing::Point(145, 38);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(91, 37);
			this->button11->TabIndex = 1;
			this->button11->Text = L"button11";
			this->button11->UseVisualStyleBackColor = false;
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::SystemColors::Control;
			this->button12->Location = System::Drawing::Point(25, 38);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(86, 37);
			this->button12->TabIndex = 0;
			this->button12->Text = L"button12";
			this->button12->UseVisualStyleBackColor = false;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(782, 553);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(800, 600);
			this->MinimumSize = System::Drawing::Size(800, 600);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}



#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MyForm1::Visible = false;
		game->start(*game);
		MyForm1::Visible = true;
		//delete game;
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		panel1->Visible = false;
		panel2->Visible = true;
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
		panel2->Visible = false;
		panel1->Visible = true;
	}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	game->setCan("images/beczkowe_wisnia.png", canType::Beczkowe);
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	game->setCan("images/kustosz.png", canType::Kustosz);
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	game->setCan("images/harnas.png", canType::Harnas);
}
};
}
