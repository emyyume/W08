#include "basic.h"

Basic::Basic() :customer_name("Customer"), identity_card("123456789"), address("Heaven"), call_time(0), call_rate(1000), traffic(0), price_of_access(200), phone_charges(0), internet_charges(0), total_charge(0) {}

void Basic::Registration() {
	cout << "Please enter full of customers information:" << endl;
	cout << "Fullname? ", getline(cin, this->customer_name);
	cout << "Identity card? ", getline(cin, this->identity_card);
	cout << "Address? ", getline(cin, this->address);
	cout << "Call time (minutes)? ", cin >> this->call_time, cin.get();
	if (this->call_time < 0 || cin.fail())
		throw "Please enter the correct customer information!";
	cout << "Traffic (MB)? ", cin >> this->traffic, cin.get();
	if (this->traffic < 0 || cin.fail())
		throw "Please enter the correct customer information!";
}
void Basic::NoticeOfPayment() const {
	cout << "Type: " << this->GetServiceType() << endl
		<< "Fullname: " << this->customer_name << endl
		<< "Identity card: " << this->identity_card << endl
		<< "Address: " << this->address << endl
		<< "Call time: " << this->call_time << " minutes" << endl
		<< "Traffic: " << this->traffic << " MB" << endl;
}
double Basic::GetPhoneCharges() {
	return this->phone_charges = this->call_time * this->call_rate;
}
double Basic::GetInternetCharges() {
	return this->internet_charges = this->traffic * this->price_of_access;
}
double Basic::GetTotalCharges() {
	return 1.1*(this->GetInternetCharges() + this->GetPhoneCharges());
}
string Basic::GetServiceType() const {
	return "Basic";
}
void Basic::GetCharges() {
	cout << "Phone charges: " << this->GetPhoneCharges() << " VND" << endl
		<< "Internet charges: " << this->GetInternetCharges() << " VND" << endl
		<< "Total charges: " << this->GetTotalCharges() << " VND" << endl;
}