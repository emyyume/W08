#pragma once
#include "basic.h"

class DataFix :public Basic {
public:
	DataFix() = default;
	void Registration();
	void NoticeOfPayment() const;
	double GetPhoneCharges();
	double GetInternetCharges();
	double GetTotalCharges();
	string GetServiceType() const;
	void GetCharges();
};