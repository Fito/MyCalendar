#pragma once
#include "NewEventDialog.h"
#include "UserInfoDialog.h"
#include "EventText.h"
#include "EventsList.h"
#include "User.h"
#include "Json.h"
#include "UserLoader.h"
#include "EventsLoader.h"
#include "Requester.h"
#include "EventsCreator.h"

namespace MyCalendar {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::Serialization::Json;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void) : currentDate(DateTime::Today),
					   newEventDialog(gcnew NewEventDialog()),
					   userInfoDialog(gcnew UserInfoDialog()),
					   family(gcnew FontFamily(L"Arial")),
					   font(gcnew System::Drawing::Font(family, 10, FontStyle::Regular, GraphicsUnit::Point)),
					   brush(gcnew SolidBrush(Color::Black)),
					   eventsList(gcnew EventsList()),
					   eventText(nullptr),
					   hoveredElement(nullptr)
		{
			InitializeComponent();
	
			userLoader = gcnew UserLoader("user_info.json");
			user = userLoader->LoadUser();
			
			eventsLoader = gcnew EventsLoader("events.json");
			array<Event^>^ loadedEvents = eventsLoader->LoadEvents(); 
			if (loadedEvents){ eventsList->PopulateFromArray(eventsLoader->LoadEvents()); }
			sendDataToServer = false;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: DateTime^ currentDate;
	private: System::Windows::Forms::Button^  eventManagerCreateEvent;
	private: NewEventDialog^ newEventDialog;
	private: UserInfoDialog^ userInfoDialog;
	private: System::Windows::Forms::Label^  label1;
	private: FontFamily^ family;
	private: System::Drawing::Font^ font;
	private: SolidBrush^ brush;
	private: EventsList^ eventsList;
	private: EventText^ eventText;
	private: System::Windows::Forms::MonthCalendar^  monthCalendar1;
	private: Element^ hoveredElement;
	private: User^ user;
	private: UserLoader^ userLoader;
	private: EventsLoader^ eventsLoader;
	private: System::Windows::Forms::Label^  label2;
	private: bool sendDataToServer;

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
			this->eventManagerCreateEvent = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// eventManagerCreateEvent
			// 
			this->eventManagerCreateEvent->BackColor = System::Drawing::Color::Gainsboro;
			this->eventManagerCreateEvent->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->eventManagerCreateEvent->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->eventManagerCreateEvent->ForeColor = System::Drawing::Color::Black;
			this->eventManagerCreateEvent->Location = System::Drawing::Point(62, 198);
			this->eventManagerCreateEvent->Name = L"eventManagerCreateEvent";
			this->eventManagerCreateEvent->Size = System::Drawing::Size(139, 38);
			this->eventManagerCreateEvent->TabIndex = 1;
			this->eventManagerCreateEvent->Text = L"Create Event";
			this->eventManagerCreateEvent->UseVisualStyleBackColor = false;
			this->eventManagerCreateEvent->Click += gcnew System::EventHandler(this, &MyForm::eventManagerCreateEvent_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(334, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(159, 23);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Today\'s events:";
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->BackColor = System::Drawing::Color::White;
			this->monthCalendar1->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->monthCalendar1->ForeColor = System::Drawing::SystemColors::WindowText;
			this->monthCalendar1->Location = System::Drawing::Point(18, 18);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 3;
			this->monthCalendar1->TitleBackColor = System::Drawing::Color::Gainsboro;
			this->monthCalendar1->TitleForeColor = System::Drawing::Color::Black;
			this->monthCalendar1->TrailingForeColor = System::Drawing::Color::Black;
			this->monthCalendar1->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &MyForm::monthCalendar1_DateChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(14, 256);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 23);
			this->label2->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(557, 300);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->monthCalendar1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->eventManagerCreateEvent);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Text = L" My Calendar";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			if(!user){
				int dialogResult = 1;
				// Show user credentials dialog until the user logs in successfully or creates a new user.
				while( dialogResult ) {
					dialogResult = userInfoDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK ? 0 : 1;
				}
				user = userInfoDialog->getUser();
				userLoader->SaveUserData(user);
			}

			// Get events form the server if there are no events stored locally.
			if(eventsList->GetEvents()->empty()){
				Requester^ requester = gcnew Requester();
				requester->Get("http://my-calendar-server.herokuapp.com/events?token=" + user->GetToken());				
				EventsCreator^ creator = gcnew EventsCreator();
				eventsList->SetEvents(creator->CreateEvents(requester->getResponse()));
			}
							
			Invalidate();
			this->Text = (user->GetName() + "'s Calendar");
		 }

private: System::Void eventManagerCreateEvent_Click(System::Object^ sender, System::EventArgs^  e) {
			if(newEventDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				eventsList += gcnew Event(
					newEventDialog->TitleText, 
					newEventDialog->Date, 
					newEventDialog->DescriptionText
				);
				sendDataToServer = true;				
				eventsLoader->SaveEventsData(eventsList->ToArray());
				
				Invalidate();
			}
		 }

private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			Graphics^ g = e->Graphics;
			eventsList->DrawEventsForDate(currentDate, Point(280, 45), g);
		 }

private: System::Void monthCalendar1_DateChanged(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e) {
			currentDate = e->End;
			if (!TodaySelected(currentDate)){
				label1->Text = L"Events for " + StringifyDate(currentDate) + L":";
			} else {
				label1->Text = L"Today's Events:";
			}
			Invalidate();
		 }

private: bool TodaySelected(DateTime^ date) {
			DateTime today = DateTime::Today;
			return (date->Day == today.Day &&
					date->Month == today.Month &&
					date->Year == today.Year);
		 }

private: String^ StringifyDate(DateTime^ date) {
			return date->Month.ToString() + L"/" + date->Day.ToString();
		 }

private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			Element^ newHovered = eventsList->ElementHovered(e->Location);
			if (hoveredElement == newHovered) { 
				return; 
			} else if (newHovered) {
				if (hoveredElement) { hoveredElement->hovered = false; }
				hoveredElement = newHovered;				
				hoveredElement->hovered = true;
				Invalidate(hoveredElement->bound);
			}
			if (hoveredElement && !newHovered) {
				hoveredElement->hovered = false;
				Invalidate(hoveredElement->bound);
				hoveredElement = nullptr;	
			}
			Update();
		 }

private: System::Void MyForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (!(eventsList->GetEvents()->empty())) {
				 eventsList->EventClicked(e->Location);
				 eventsList->CloseEvent(e->Location, currentDate);
				 Invalidate();
			 }
		 }
private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			eventsLoader->SaveEventsData(eventsList->ToArray());
			if (sendDataToServer) {
				Requester^ resquester = gcnew Requester();
				Cursor->Current = Cursors::WaitCursor;
				label2->Text = "Sending data to server...";
				label2->Invalidate();
				resquester->postEvents("http://my-calendar-server.herokuapp.com/events", eventsList->ToJson(), user->GetToken());
			}
		 }
};
}
