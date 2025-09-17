
// Policy

#include <iostream>

class Identification {
public:
	virtual void identify() = 0;
};

class FaceIdentification : public Identification {
public:
	void identify() override {
		std::cout << "identify by face\n";
	}
};

class NumberIdentification : public Identification {
public:
	void identify() override {
		std::cout << "identify by number\n";
	}
};

class AccessSystem {
public:
	AccessSystem(Identification* identification) : identification(identification) {}

	void access() {
		identification->identify();
	}
private:
	Identification* identification;
};

//int main() {
//	FaceIdentification identification;
//	AccessSystem system(&identification);
//	system.access();
//}