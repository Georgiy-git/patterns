
#include <iostream>

class PersonState {
public:
	virtual void run() = 0;
	virtual void evade() = 0;
	virtual void strike() = 0;
};

class FullHP : public PersonState {
public:
	void run() override {
		std::cout << "run with speed 10\n";
	}
	void evade() override {
		std::cout << "try evade with chance 0.5\n";
	}
	void strike() override {
		std::cout << "strike with 3 damage\n";
	}
};

class LowHP : public PersonState {
public:
	void run() override {
		std::cout << "run with speed 5\n";
	}
	void evade() override {
		std::cout << "try evade with chance 0.1\n";
	}
	void strike() override {
		std::cout << "strike with 1 damage\n";
	}
};

class Person {
public:
	void setState(PersonState* state) { this->state = state; }
	void run() {
		state->run();
	}
	void evade() {
		state->evade();
	}
	void strike() {
		state->strike();
	}
private:
	PersonState* state;
};

//int main() {
//	Person person;
//	FullHP fstate;
//	LowHP lstate;
//	person.setState(&fstate);
//	person.run();
//	person.run();
//	person.setState(&lstate);
//	person.strike();
//	person.evade();
//}