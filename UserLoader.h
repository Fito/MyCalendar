#pragma once

#include "User.h"

using namespace System;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Json;
using namespace System::IO;

namespace MyCalendar{
	ref class UserLoader {
	protected:
		String^ fileName;
		FileStream^ stream;
		DataContractJsonSerializer^ serializer;
	public:
		UserLoader(String^ file_name) : fileName(file_name),
										serializer( gcnew DataContractJsonSerializer(User::typeid)){};

		bool OpenFile(void) {
			stream = gcnew FileStream(fileName, FileMode::OpenOrCreate);
			return stream->Length;
		};

		void CloseFile(void) {
			stream->Close();
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