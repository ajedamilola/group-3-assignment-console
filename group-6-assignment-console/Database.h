#include<sqlite3.h>
#include<iostream>
#include "Shop.h"



using namespace std;

bool initDatabase() {
	sqlite3* DB;
	string sql = "CREATE TABLE IF NOT EXISTS metadata("
		" id INTEGER PRIMARY KEY AUTOINCREMENT,"
		"	label VARCHAR(200) NOT NULL,"
		"	value TEXT"
		");"

		"CREATE TABLE IF NOT EXISTS storeitems("
		"	id  INTEGER PRIMARY KEY AUTOINCREMENT,"
		"	name VARCHAR(200) NOT NULL,"
		"price FLOAT DEFAULT 0,"
		"description TEXT,"
		"stock_qty INT NOT NULL DEFAULT 0"
		"); ";

	int exit_code = 0;
	exit_code = sqlite3_open("database.db", &DB);
	char* messagError;
	exit_code = sqlite3_exec(DB, sql.c_str(),NULL,0, &messagError);

	if (exit_code == SQLITE_OK) {
		sqlite3_close(DB);
		return true;
	}
	else {
		cerr << "Unable to create tables";
		return false;
	}
}