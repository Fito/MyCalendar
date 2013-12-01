#pragma once

#include "Requester.h"
#include "Json.h"

namespace MyCalendar {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Specialized;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UserInfoDialog
	/// </summary>
	public ref class UserInfoDialog : public System::Windows::Forms::Form
	{
	public:
		UserInfoDialog(void)
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
		~UserInfoDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox2;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  logIn;
	private: System::Windows::Forms::Button^  signUp;




	protected:
		User^ tempUser;
		bool shouldClose;
	private: System::Windows::Forms::Label^  errorMessage;
	protected:

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
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->logIn = (gcnew System::Windows::Forms::Button());
			this->signUp = (gcnew System::Windows::Forms::Button());
			this->errorMessage = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12));
			this->textBox2->Location = System::Drawing::Point(12, 84);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(260, 26);
			this->textBox2->TabIndex = 1;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12));
			this->textBox1->Location = System::Drawing::Point(12, 152);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->PasswordChar = '*';
			this->textBox1->Size = System::Drawing::Size(260, 26);
			this->textBox1->TabIndex = 2;
			this->textBox1->UseSystemPasswordChar = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 14, System::Drawing::FontStyle::Bold));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(12, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 24);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Name";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 14, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(12, 124);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 24);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Password";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 14, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(12, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(216, 24);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Enter your information";
			// 
			// logIn
			// 
			this->logIn->BackColor = System::Drawing::Color::Blue;
			this->logIn->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->logIn->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->logIn->ForeColor = System::Drawing::Color::White;
			this->logIn->Location = System::Drawing::Point(12, 241);
			this->logIn->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->logIn->Name = L"logIn";
			this->logIn->Size = System::Drawing::Size(105, 38);
			this->logIn->TabIndex = 7;
			this->logIn->Text = L"Log In";
			this->logIn->UseVisualStyleBackColor = false;
			this->logIn->Click += gcnew System::EventHandler(this, &UserInfoDialog::logIn_Click);
			// 
			// signUp
			// 
			this->signUp->BackColor = System::Drawing::Color::Blue;
			this->signUp->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->signUp->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->signUp->ForeColor = System::Drawing::Color::White;
			this->signUp->Location = System::Drawing::Point(167, 241);
			this->signUp->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->signUp->Name = L"signUp";
			this->signUp->Size = System::Drawing::Size(105, 38);
			this->signUp->TabIndex = 8;
			this->signUp->Text = L"Sign Up";
			this->signUp->UseVisualStyleBackColor = false;
			this->signUp->Click += gcnew System::EventHandler(this, &UserInfoDialog::signUp_Click);
			// 
			// errorMessage
			// 
			this->errorMessage->AutoSize = true;
			this->errorMessage->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 14, System::Drawing::FontStyle::Bold));
			this->errorMessage->ForeColor = System::Drawing::Color::Red;
			this->errorMessage->Location = System::Drawing::Point(12, 192);
			this->errorMessage->Name = L"errorMessage";
			this->errorMessage->Size = System::Drawing::Size(0, 24);
			this->errorMessage->TabIndex = 9;
			// 
			// UserInfoDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(220)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(290, 292);
			this->ControlBox = false;
			this->Controls->Add(this->errorMessage);
			this->Controls->Add(this->signUp);
			this->Controls->Add(this->logIn);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox2);
			this->Name = L"UserInfoDialog";
			this->Text = L"User Info";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &UserInfoDialog::UserInfoDialog_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: property String^ userName {
				String^ get() {
					return this->textBox2->Text;
				}
			}
	public: property String^ userPassword {
				String^ get() {
					return this->textBox1->Text;
				}
			}

	public: User^ getUser(void) {
				return this->tempUser;
			}

	private: System::Void logIn_Click(System::Object^  sender, System::EventArgs^  e) {
				ShowMessage("Communicating with server...", Color::Black);
				Cursor->Current = Cursors::WaitCursor;

				Requester^ requester = gcnew Requester();
				User^ user = gcnew User(userName, userPassword, "");
				requester->GetUser("http://my-calendar-server.herokuapp.com/user", user->GetName(), user->GetEncryptedPassword());

				System::Diagnostics::Debug::Write(">>>>" + requester->getResponse());
				if (requester->getResponse() == "Invalid User") {
					ShowMessage("Invalid user credentials", Color::Red);
					shouldClose = false;
				} else {
					Json^ parser = gcnew Json();
					array<String^>^ userParsedData = parser->parseUser(requester->getResponse());
					user->SetToken(userParsedData[0]);
					tempUser = user;
					shouldClose = true;
				}
				Cursor->Current = Cursors::Default;
			 }

	private: System::Void signUp_Click(System::Object^  sender, System::EventArgs^  e) {
				ShowMessage("Communicating with server...", Color::Black);
				Cursor->Current = Cursors::WaitCursor;

				User^ user = gcnew User(userName, userPassword, "");
				NameValueCollection^ userData = gcnew NameValueCollection;
				userData->Add("name", user->GetName());
				userData->Add("encrypted_password", user->GetEncryptedPassword());

				Requester^ requester = gcnew Requester();
				requester->Post("http://my-calendar-server.herokuapp.com/user", userData);

				if (requester->getResponse() == "A user with that name already exists") {
					ShowMessage("That name already exists", Color::Red);
					shouldClose = false;				
				} else {
					Json^ parser = gcnew Json();
					array<String^>^ userParsedData = parser->parseUser(requester->getResponse());
					user->SetToken(userParsedData[0]);
					tempUser = user;
					shouldClose = true;
				}
				Cursor->Current = Cursors::Default;
			}

	private: System::Void UserInfoDialog_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				e->Cancel = !shouldClose;
			}

	private: void ShowMessage(String^ message, Color color) {
				errorMessage->ForeColor = color;
				errorMessage->Text = message;
				errorMessage->Invalidate();				
			 }
};
}
