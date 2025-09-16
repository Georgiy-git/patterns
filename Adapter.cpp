
#include <string>
#include <iostream>

class SQLite {
public:
	void get_data(const std::string& table_name, int row, int column) {
		std::cout << "get data from sqlite\n";
	}
};

class SQL {
public:
	virtual void select(const std::string& request) = 0;
};

class PostgresSQL : public SQL {
public:
	void select(const std::string& request) override {
		std::cout << "select from Postgres sql\n";
	}
};

class SQLiteAdapter : public SQL {
public:
	void select(const std::string& request) override {
		sqlite->get_data("main", 0, 0);
	}
private:
	SQLite* sqlite;
};

//int main() {
//	SQL* sql = new SQLiteAdapter;
//	sql->select("main table");
//}