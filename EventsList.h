#pragma once
#include "Event.h"
#include <cliext/list>

using namespace System;
using namespace cliext;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Json;

namespace MyCalendar {	
	public ref class EventsList {
	private:
		list<Event^>^ events;
		array <Event^>^ eventArray;
	public:
		EventsList() : eventArray(nullptr) {
			events = gcnew list<Event^>();
		}

		array<Event^>^ ToArray() {
			eventArray = events->to_array();
			return eventArray;
		}

		list<Event^>^ PopulateFromArray(array<Event^>^ eventsArray) {
			events = gcnew list<Event^>(eventsArray);
			return events;
		}

		list<Event^>^ GetEvents(){
			return this->events;
		}

		EventsList^ operator+=(Event^ event) {
			events->push_back(event);
			return this;
		}

		EventsList^ operator-=(Event^ event) {
			events->remove(event);
			return this;
		}

		void DrawEventsForDate(DateTime^ date, Point^ start, Graphics^ g) {
			int i = start->Y;
			for each(Event^ event in this->GetEvents()) {
				if (event->IsOnDate(date)) {
					event->text->SetPosition(Point(start->X, i));
					event->text->Draw(g);
					i += 40;
				}
			}
		}

		Element^ ElementHovered(Point p) {
			for each(Event^ event in this->GetEvents()) {
				if (event->TextBorderContains(p))
					return event->text->border;
			}
			return nullptr;
		}

		void CloseEvent(Point p, DateTime^ date) {
			for each(Event^ event in this->GetEvents()) {
				if (event->IsOnDate(date) && event->text->CloseClicked(p)) {
					events->remove(event);
					return;
				}
			}			
		}
	};
}