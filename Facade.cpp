
class Filesystem {
public:
	void open_file() {}
};

class ServiceManager {
public:
	void start_service() {}
};

class DriverManager {
public:
	void get_driver_info() {}
};

class Windows {
public:
	void open_file() {
		filesystem.open_file();
	}
	void start_service() {
		serviceManager.start_service();
	}
	void get_driver_info() {
		driverManager.get_driver_info();
	}

private:
	Filesystem filesystem;
	ServiceManager serviceManager;
	DriverManager driverManager;
};

//int main() {
//	Windows system;
//	system.start_service();
//}