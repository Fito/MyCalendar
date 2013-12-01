#pragma once
#include "Event.h"
#include "Json.h"

using namespace System;

namespace MyCalendar {
	ref class EventsCreator {
	public:
		EventsCreator(void){};

		list<Event^>^ CreateEvents(String^ eventsString){
			Json^ parser = gcnew Json();
			list<Event^>^ eventsList = gcnew list<Event^>();
			System::Diagnostics::Debug::Write("Events string: " + eventsString + "\n");
			list<array<String^>^>^ eventsData = parser->parseEvents(eventsString);

			for each(array<String^>^ event in eventsData) {
				Event^ newEvent = gcnew Event(
					event[0], 
					event[1], 
					Convert::ToInt32(event[2], 10), 
					Convert::ToInt32(event[3], 10), 
					Convert::ToInt32(event[4], 10)
				);

				eventsList->push_back(newEvent);
			}
			System::Diagnostics::Debug::Write(">>>>>>>>>> " + eventsList->size() + " <<<<<<<<<<");
			return eventsList;
		};
	};
}

