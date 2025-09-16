
#include <iostream>

class Object {
public:
	virtual void render() = 0;
	virtual void process_event(int num) = 0;
};

class Person : public Object {
public:
	void render() override {}
	void process_event(int num) override {
		std::cout << "Operation number " << num << std::endl;
	}
};

class PersonProxy : public Object {
public:
	PersonProxy(Person* person) : person(person) {}
	void render() override {
		person->render();
	}
	void process_event(int num) override {
		if (num > 5 && num < 116) {
			person->process_event(num);
		}
	}
private:
	Person* person;
};

//int main() {
//	Person person;
//	PersonProxy proxy(&person);
//	proxy.process_event(100);
//	proxy.process_event(211);
//	proxy.render();
//}