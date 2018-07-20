#include "datafree.h"

DataFree::DataFree() :subscription_fee(0), free_flow_threshold(0) {}

void DataFree::Registration() {
	Basic::Registration();
	cout << "Subscription fee? ", cin >> this->subscription_fee, cin.get();
	if (this->subscription_fee < 0 || cin.fail())
		throw "Please enter the correct customer information!";
	cout << "Free flow threshold? ", cin >> this->free_flow_threshold, cin.get();
	if (this->free_flow_threshold < 0 || cin.fail())
		throw "Please enter the correct customer information!";
}
void DataFree::NoticeOfPayment() const {
	Basic::NoticeOfPayment();
	cout << "Subscription fee: " << this->subscription_fee << " VND" << endl
		<< "Free flow threshold: " << this->free_flow_threshold << " MB" << endl;
}
double DataFree::GetPhoneCharges() {
	return this->phone_charges = Basic::GetPhoneCharges();
}
double DataFree::GetInternetCharges() {
	return this->internet_charges = (this->traffic <= this->free_flow_threshold) ? subscription_fee : subscription_fee + Basic::GetInternetCharges();
}
double DataFree::GetTotalCharges() {
	return 1.1*(this->GetInternetCharges() + this->GetPhoneCharges());
}
string DataFree::GetServiceType() const {
	return "DataFree";
}
void DataFree::GetCharges() {
	Basic::GetCharges();
}