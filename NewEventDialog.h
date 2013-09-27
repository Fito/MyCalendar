#pragma once

namespace MyCalendar {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for NewEventDialog
	/// </summary>
	public ref class NewEventDialog : public System::Windows::Forms::Form
	{
	public:
		NewEventDialog(void)
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
		~NewEventDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  createEventCreate;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  createEventCancel;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->createEventCreate = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->createEventCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(12, 120);
			this->dateTimePicker1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(342, 29);
			this->dateTimePicker1->TabIndex = 1;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &NewEventDialog::dateTimePicker1_ValueChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 41);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(342, 29);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Print", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(154, 88);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 28);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Date";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe Print", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(154, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 28);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Title";
			// 
			// createEventCreate
			// 
			this->createEventCreate->BackColor = System::Drawing::Color::PaleGreen;
			this->createEventCreate->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->createEventCreate->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->createEventCreate->Location = System::Drawing::Point(12, 329);
			this->createEventCreate->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->createEventCreate->Name = L"createEventCreate";
			this->createEventCreate->Size = System::Drawing::Size(105, 38);
			this->createEventCreate->TabIndex = 3;
			this->createEventCreate->Text = L"Create";
			this->createEventCreate->UseVisualStyleBackColor = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe Print", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(127, 170);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(103, 28);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Description";
			// 
			// textBox2
			// 
			this->textBox2->AcceptsReturn = true;
			this->textBox2->BackColor = System::Drawing::SystemColors::Window;
			this->textBox2->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox2->Location = System::Drawing::Point(12, 202);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(342, 100);
			this->textBox2->TabIndex = 2;
			// 
			// createEventCancel
			// 
			this->createEventCancel->BackColor = System::Drawing::Color::LightSalmon;
			this->createEventCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->createEventCancel->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->createEventCancel->Location = System::Drawing::Point(249, 329);
			this->createEventCancel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->createEventCancel->Name = L"createEventCancel";
			this->createEventCancel->Size = System::Drawing::Size(105, 38);
			this->createEventCancel->TabIndex = 4;
			this->createEventCancel->Text = L"Cancel";
			this->createEventCancel->UseVisualStyleBackColor = false;
			// 
			// NewEventDialog
			// 
			this->AcceptButton = this->createEventCreate;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(220)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->CancelButton = this->createEventCancel;
			this->ClientSize = System::Drawing::Size(366, 380);
			this->ControlBox = false;
			this->Controls->Add(this->createEventCancel);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->createEventCreate);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dateTimePicker1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::Indigo;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"NewEventDialog";
			this->Text = L"Create new event";
			this->Load += gcnew System::EventHandler(this, &NewEventDialog::NewEventDialog_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void NewEventDialog_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	public: property String^ TitleText {
				String^ get() {
					return this->textBox1->Text;
				}
			}
	public: property String^ DescriptionText {
				String^ get() {
					return this->textBox2->Text;
				}
			}
	public: property DateTime^ Date {
				DateTime^ get() {
					return this->dateTimePicker1->Value;
				}
			}
private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
