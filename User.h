#pragma once
using namespace System;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Json;

namespace MyCalendar {
	[DataContract]
	public ref class User {
	protected:
		[DataMember]
		String^ name;
		[DataMember]
		String^ password;
	public:
		User(String^ name, String^ password){
			this->name = name;
			this->password = password;
		};

		String^ GetName(void) {
			return name;
		};
	};
}