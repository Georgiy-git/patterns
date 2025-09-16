
#include <memory>
#include <iostream>


class Object {
public:
	virtual Object* clone() = 0;
};

class Person : public Object {
public:
	Object* clone() override {
		std::cout << "clone person\n";
		return new Person;
	}
};

class Unit : public Object {
public:
	Object* clone() override {
		std::cout << "clone unit\n";
		return new Unit;
	}
};

//int main() {
//	Person person;
//	Unit unit;
//	auto new_unit = unit.clone();
//	auto person_clone = person.clone();
//}