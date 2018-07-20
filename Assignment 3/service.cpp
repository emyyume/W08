#include "service.h"

Service::~Service() {
	for (auto &i : this->service)
		delete i;
}

void Service::Registration() {
	try {
		int number_of_customers = 0;
		do {
			cout << "How many customers use this service? ", cin >> number_of_customers, cin.get();
			if (cin.fail()) return;
		} while (number_of_customers < 0);
		int service_type = 0;
		Basic* service = nullptr;
		for (int i = 0; i < number_of_customers; ++i) {
			do {
				cout << "What service does this customer use (0: Basic, 1: Data Free, 2: Data Fix)? ", cin >> service_type, cin.get();
				if (cin.fail()) return;
			} while (service_type < 0 || service_type > 2);
			if (service_type == 0)
				service = new Basic;
			else if (service_type == 1)
				service = new DataFree;
			else if (service_type == 2)
				service = new DataFix;
			cout << "Customer no." << i + 1 << ':' << endl;
			service->Registration();
			this->service.push_back(service);
		}
	}
	catch (const char* &msg) {
		cerr << msg << endl;
	}
	catch (...) {
		return;
	}
}
void Service::NoticeOfPayment() const {
	cout << endl << "Notice of Payment:" << endl;
	int no = 0;
	for (const auto &i : this->service) {
		cout << "Customer no." << ++no << ':' << endl;
		i->NoticeOfPayment();
		i->GetCharges();
	}
}