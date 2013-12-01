#pragma once

#include "User.h"
#include <cliext/list>

using namespace cliext;
using namespace System;
using namespace System::Web::Script::Serialization;
using namespace System::Collections::Generic;

namespace MyCalendar {
	ref class Json {
	protected:
		JavaScriptSerializer^ serializer;

	public:
		Json(void){
			serializer = gcnew JavaScriptSerializer();
		};
				
		array<String^>^ parseObject(String^ object, int elements) {
			array<String^>^ values = gcnew array<String^>(elements);
			Dictionary<String^, String^>^ dic = serializer->Deserialize<Dictionary<String^, String^>^>(object);
			dic->Values->CopyTo(values, 0);
			return values;
		};

		array<String^>^ parseUser(String^ object) {
			return parseObject(object, 3);
		};

		list<array<String^>^>^ parseEvents(String^ objectsArray) {
			list<array<String^>^>^ parsedObjects = gcnew list<array<String^>^>();
			list<Dictionary<String^, String^>^>^ objects = 
				gcnew list<Dictionary<String^, String^>^>(
					serializer->Deserialize<array<Dictionary<String^, String^>^>^>(objectsArray)
				);
			for each(Dictionary<String^, String^>^ object in objects){
				System::Diagnostics::Debug::Write("Pushing object ---- \n");
				array<String^>^ values = gcnew array<String^>(5);
				object->Values->CopyTo(values, 0);
				parsedObjects->push_back(values);
			}
			return parsedObjects;
		}
	};
}
