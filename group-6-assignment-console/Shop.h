#include <string>
using namespace std;
class Shop {
private:
	static Shop dbShop;
	static int record_exist_callback(void* data, int rowsReturned, char** values, char** columnNames) {
		//i can simply do this since the fact that this callback is called means there was a record that matches the query
		recordExist = true;
		return 0;
	}

	static int load_data_callback(void* data, int columns, char** values, char** columnNames) {
		for (int i = 0; i < columns; i++) {
			char* columnName = columnNames[i];
			
			if (strcmp(columnName, "label") == 0) {
				char* label = values[i];
				char* value = values[i + 1];

				if (strcmp(label, "storeName") == 0) {
					dbShop.name = value;
				}
				else if (strcmp(label, "storePhone") == 0) {
					dbShop.phone = value;
				}
				else if (strcmp(label, "storeAddress") == 0) {
					dbShop.address = value;
				}
			}
			
		}
		return 0;
	}

public:
	//intermediate variables for sqlite queries
	static bool recordExist;
	static sqlite3* db;


	string name;
	string address;
	string phone;

	void setDetails(string newName, string newAddress, string newPhone) {
		//tenery
		this->name = newName.empty() ? this->name : newName;
		this->address = newAddress.empty() ? this->address : newAddress;
		this->phone = newPhone.empty() ? this->phone : newPhone;

		sqlite3_open("database.db", &db);
		persistState("storeName", this->name);
		persistState("storeAddress", this->address);
		persistState("storePhone", this->phone);
		sqlite3_close(db);

	}

	void setPhone(string newPhone) {
		this->phone = newPhone;
		persistState("storePhone", this->phone);
	}

	void setAddress(string newAddress) {
		this->address = newAddress;
		persistState("storeAddress", this->address);
	}

	void setName(string newName) {
		this->name = newName;
		persistState("storeName", this->name);
	}

	static void persistState(string key, string value) {

		recordExist = false;
		//first check if the record of the store phone is in the database
		string check_query = "SELECT * FROM metadata WHERE label='" + key + "'";
		char* errMsg;
		sqlite3_exec(db, check_query.c_str(), record_exist_callback, NULL, &errMsg);


		//Preparing the query for updating
		string updateQuery = "UPDATE metadata SET value = '" + value + "' WHERE label = '" + key + "'";
		string insertQuery = "INSERT INTO metadata (label, value) VALUES ('" + key + "', '" + value + "')";
		const char* saveQuery = recordExist ? updateQuery.c_str() : insertQuery.c_str();
		int exit_code = sqlite3_exec(db, saveQuery, NULL, NULL, NULL);

		if (exit_code != SQLITE_OK) {
			cerr << "\nError saving " << key << " to database\n";
			if (errMsg) {
				cout << errMsg;
			}
		}
	}

	Shop(bool loadFromDB = false) {
		if (loadFromDB) {
			sqlite3_open("database.db", &db);
			int exit_code = sqlite3_exec(db, "SELECT * FROM metadata WHERE label LIKE '%store%'", load_data_callback, NULL, NULL);

			this->name = dbShop.name;
			this->phone = dbShop.phone;
			this->address = dbShop.address;
		}
	}

};