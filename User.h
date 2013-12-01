#pragma once
using namespace System;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Json;
using namespace System::Security::Cryptography;
using namespace System::Collections::Generic;

namespace MyCalendar {
	[DataContract]
	public ref class User {
	protected:
		[DataMember]
		String^ name;
		[DataMember]
		String^ encryptedPassword;
		[DataMember]
		String^ token;

		String^ EncryptPassword(String^ password) {
			array<Byte>^ passwordBytes = System::Text::Encoding::UTF8->GetBytes(password);
			array<Byte>^ encryptedBytes;
			SHA1^ shaM = gcnew SHA1Managed;
			encryptedBytes = shaM->ComputeHash(passwordBytes);
			return System::Text::Encoding::UTF8->GetString(encryptedBytes);
		};

	public:
		User(String^ name, String^ password, String^ token){
			this->name = name;
			this->encryptedPassword = EncryptPassword(password);
			this->token = token;
		};

		String^ GetName(void) {
			return name;
		};

		String^ GetEncryptedPassword(void) {
			return encryptedPassword;
		};

		void SetToken(String^ newToken) {
			token = newToken;
		};

		String^ GetToken(void) {
			return token;
		};
	};
}