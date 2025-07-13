#include <string>
using namespace std;
class Shop {
public:
	string name;
	string address;
	string phone;
	void setDetails(string newName, string newAddress, string newPhone) {
		this->name = newName.empty() ? this->name : newName;
		this->address = newAddress.empty() ? this->address : newAddress;
		this->phone = newPhone.empty() ? this->phone : newPhone;
	}

	void setPhone(string newPhone) {
		this->phone = newPhone;
	}

	void setAddress(string newAddress) {
		this->name = newAddress;
	}

	void setName(string newName) {
		this->name = newName;
	}



};