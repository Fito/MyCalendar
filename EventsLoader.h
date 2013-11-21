#pragma once

#include "DataLoader.h"
#include "Event.h"

using namespace System;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Json;
using namespace System::IO;

namespace MyCalendar {
	ref class EventsLoader : DataLoader {
	public:
		EventsLoader(String^ file_name) : DataLoader(file_name) {
			serializer = gcnew DataContractJsonSerializer(array<Event^>::typeid);
		};

		array<Event^>^ LoadEvents(void) {
			array<Event^>^ eventArray;
			if(OpenFile()) { 
				 eventArray = (array<Event^>^)serializer->ReadObject(stream);
			} else {
				eventArray = nullptr;
			}
			CloseFile();
			return eventArray;
		};

		void SaveEventsData(array<Event^>^ eventsArray) {
			OpenFile();
			serializer->WriteObject(stream, eventsArray);
			CloseFile();
		};
	};
}
