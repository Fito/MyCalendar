#pragma once
using namespace System;

namespace MyCalendar {
	public ref class Event {
	protected:
		String^ title;
		DateTime^ date;
		String^ description;
	public:
		EventText^ text;

		Event(String^ title, DateTime^ date, String^ description){
			this->title = title;
			this->date = date;
			this->description = description;
		}

		bool IsOnDate(DateTime^ date) {
			return (this->date->Day == date->Day &&
					this->date->Month == date->Month &&
					this->date->Year == date->Year);
		}

		DateTime^ GetDate() {
			return this->date;
		}

		String^ GetTitle() {
			return this->title;
		}
	};
}