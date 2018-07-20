#include "datafix.h"

void DataFix::Registration() {
	Basic::Registration();
}
void DataFix::NoticeOfPayment() const {
	Basic::NoticeOfPayment();
}
double DataFix::GetPhoneCharges() {
	return this->phone_charges = 0.9 * Basic::GetPhoneCharges();
}
double DataFix::GetInternetCharges() {
	return this->internet_charges = 1000000;
}
double DataFix::GetTotalCharges() {
	return 1.1*(this->GetInternetCharges() + this->GetPhoneCharges());
}
string DataFix::GetServiceType() const {
	return "DataFix";
}
void DataFix::GetCharges() {
	Basic::GetCharges();
}