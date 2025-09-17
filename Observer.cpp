
// Dependents
// Publish-Subscribe

#include <iostream>
#include <string>
#include <list>

class Object {
public:
	virtual void start() = 0;
};

class NetworkReader {
public:
	void read_network() {
		std::string received_command = "power on";
		for (auto& [object, command] : registrations) {
			if (command == received_command) {
				object->start();
			}
		}
	}
	void attach(Object* object, const std::string& command) {
		registrations.push_back({ object, command });
	}
	void detach(Object* object, const std::string& command) {
		registrations.remove_if([&](std::pair<Object*, std::string> reg) {
			return (reg.first == object && reg.second == command); });
	}
private:
	std::list<std::pair<Object*, std::string>> registrations;
};

class SensorAC : public Object{
public:
	void start() override {
		std::cout << "Start measuring the current\n";
	}
};

class SurveillanceSystem : public Object {
public:
	void start() override {
		std::cout << "Start surveillance\n";
	}
};

//int main() {
//	NetworkReader reader;
//	SensorAC sensor;
//	SurveillanceSystem system;
//	reader.attach(&sensor, "power on");
//	reader.attach(&system, "power on");
//	reader.read_network();
//}