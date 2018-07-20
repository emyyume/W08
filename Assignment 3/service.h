#pragma once
#include "datafree.h"
#include "datafix.h"
#include <vector>

class Service {
public:
	Service() = default;
	~Service();
	void Registration();
	void NoticeOfPayment() const;
private:
	vector<Basic*> service;
};