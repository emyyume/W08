#pragma once
#include <iostream>
#include <string>
using namespace std;

class Basic {
public:
	Basic();
	virtual void Registration();
	virtual void NoticeOfPayment() const;
	virtual double GetPhoneCharges();
	virtual double GetInternetCharges();
	virtual double GetTotalCharges();
	virtual string GetServiceType() const;
	virtual void GetCharges();
protected:
	string customer_name, identity_card, address;
	double call_time, call_rate, traffic, price_of_access;
	double phone_charges, internet_charges, total_charge;
};