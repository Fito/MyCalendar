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

		void DrawEventsForDate(DateTime^ date, Font^ font, Point^ start, Graphics^ g) {
			int i = start->Y;
			for each(Event^ event in this->GetEvents()) {
				if (event->IsOnDate(date)) {
					event->text = gcnew EventText(Color::Indigo, Point(start->X, i), event->GetTitle(), font);
					event->text->Draw(g);
					i += 30;
				}
			}
		}
	};
}