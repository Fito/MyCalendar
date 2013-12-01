#pragma once

#include "EventText.h"

using namespace System;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Json;

namespace MyCalendar {
	[DataContract]
	public ref class Event {
	protected:
		[DataMember]
		String^ title;
		[DataMember]
		String^ description;
		[DataMember]
		int dateDay;
		[DataMember]
		int dateMonth;
		[DataMember]
		int dateYear;	
		// Not serialized
		DateTime^ date;
	public:
		EventText^ text;

		Event(String^ title, DateTime^ date, String^ description){
			this->title = title;
			this->date = date;
			this->dateDay = date->Day;
			this->dateMonth = date->Month;
			this->dateYear = date->Year;
			this->description = description;
			this->text = gcnew EventText(Point(0, 0), this->title, this->description);
		}
		
		Event(String^ title, String^ description, int dateDay, int dateMonth, int dateYear){
			this->title = title;
			this->date = CreateDate(dateDay, dateMonth, dateYear);
			this->dateDay = dateDay;
			this->dateMonth = dateMonth;
			this->dateYear = dateYear;
			this->description = description;
			this->text = gcnew EventText(Point(0, 0), this->title, this->description);
		}

		bool IsOnDate(DateTime^ date) {
			return (this->dateDay == date->Day &&
					this->dateMonth == date->Month &&
					this->dateYear == date->Year);
		}

		[OnDeserialized]
		void ReconstructDateAndText(StreamingContext context) {
			this->date = gcnew DateTime(
				(this->dateYear),
				(this->dateMonth),
				(this->dateDay)
			);
			this->text = gcnew EventText(Point(0, 0), this->title, this->description);
		}

		DateTime^ CreateDate(int dateDay, int dateMonth, int dateYear) {
			return gcnew DateTime(dateYear, dateMonth, dateDay);
		}

		DateTime^ GetDate() {
			return this->date;
		}

		String^ GetTitle() {
			return this->title;
		}

		String^ GetDescription() {
			return this->description;
		}

		bool TextBorderContains(Point p) {
			return this->text->border->Contains(p);
		}

		String^ ToJson(void) {
			String^ jsonString = "{";
			jsonString = jsonString + "\"title\":\"" + title + "\",";
			jsonString = jsonString + "\"description\":\"" + description + "\",";
			jsonString = jsonString + "\"day\":\"" + dateDay + "\",";
			jsonString = jsonString + "\"month\":\"" + dateMonth + "\",";
			jsonString = jsonString + "\"year\":\"" + dateYear + "\"}";
			return jsonString;
		}
	};
}