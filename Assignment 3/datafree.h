#pragma once
#include "basic.h"

class DataFree :public Basic {
public:
	DataFree();
	void Registration();
	void NoticeOfPayment() const;
	double GetPhoneCharges();
	double GetInternetCharges();
	double GetTotalCharges();
	string GetServiceType() const;
	void GetCharges();
private:
	double subscription_fee, free_flow_threshold;
};