#pragma once
using namespace System;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Json;

namespace MyCalendar {
	ref class Requester {
	protected:
	System::Net::WebClient^ client;
	String^ response;

	public:
		Requester(void): client(gcnew System::Net::WebClient()){};
		
		void Get(String^ uri) {
			response = client->DownloadString(uri);
		};

		String^ getResponse() {
			return response;
		}
	};

}


