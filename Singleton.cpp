
#include <memory>
#include <string>
#include <any>
#include <iostream>

class Singleton {
public:
	static Singleton* instance() {
		if (_instance == nullptr) {
			_instance = new Singleton;
			return _instance;
		}
		else {
			return _instance;
		}
	}
	std::any& getData() {
		return data;
	}

protected:
	Singleton() {}
	std::any data;

private:
	static inline Singleton* _instance = nullptr;
};

//int main() {
//	Singleton* singleton = Singleton::instance();
//	auto& data = singleton->getData();
//	data = 44299;
//	Singleton* new_singleton = Singleton::instance();
//	std::cout << std::any_cast<int>(new_singleton->getData());
//}