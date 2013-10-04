#pragma once
#include "Event.h"
#include <cliext/list>

using namespace System;
using namespace cliext;

namespace MyCalendar {
	public ref class EventsList {
	private:
		list<Event^>^ events;

	public:
		EventsList() {
			events = gcnew list<Event^>();
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