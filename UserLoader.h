#pragma once

#include "DataLoader.h"
#include "User.h"

using namespace System;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Json;
using namespace System::IO;

namespace MyCalendar{
	ref class UserLoader : DataLoader {
	public:
		UserLoader(String^ file_name) : DataLoader(file_name) {
			serializer = gcnew DataContractJsonSerializer(User::typeid);
		};

		User^ LoadUser(void) {
			User^ user;
			if(OpenFile()) { 
				user = (User^)serializer->ReadObject(stream);
			} else {
				user = nullptr;
			}
			CloseFile();
			return user;
		};

		void SaveUserData(User^ user) {
			OpenFile();
			serializer->WriteObject(stream, user);
			CloseFile();
		};
	};
}