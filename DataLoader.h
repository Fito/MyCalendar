#pragma once

using namespace System;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Json;
using namespace System::IO;

namespace MyCalendar {
	ref class DataLoader {
	protected:
		String^ fileName;
		FileStream^ stream;
		DataContractJsonSerializer^ serializer;
	public:
		DataLoader(String^ file_name) {
			fileName = file_name;
		};

		bool OpenFile(void) {
			stream = gcnew FileStream(fileName, FileMode::OpenOrCreate);
			return stream->Length;
		};

		void CloseFile(void) {
			stream->Close();
		};
	};
}

