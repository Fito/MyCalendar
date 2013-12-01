#pragma once
using namespace System;
using namespace System::Collections::Specialized;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Json;

namespace MyCalendar {
	ref class Requester {
	protected:
	System::Net::WebClient^ client;
	String^ response;

	public:
		Requester(void): client(gcnew System::Net::WebClient()){};

		void GetUser(String^ uri, String^ name, String^ encrypted_password) {
			String^ uriWithData = uri + "?name=" + name + "&encrypted_password=" + encrypted_password;

			Get(uriWithData);
		};

		void Get(String^ uri) {
			response = client->DownloadString(uri);
		};
		
		void Post(String^ uri, NameValueCollection^ data) {
			response = System::Text::Encoding::UTF8->GetString(client->UploadValues(uri, data));
		};

		String^ getResponse() {
			return response;
		};

		void postEvents(String^ baseUri, String^ dataString, String^ token) {
			NameValueCollection^ data = gcnew NameValueCollection();
			data->Add("events", dataString);
			data->Add("token", token);
			response = System::Text::Encoding::UTF8->GetString(client->UploadValues(baseUri, data));
		};
	};

}


