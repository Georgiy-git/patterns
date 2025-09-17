
#include <iostream>

class Person {};

class PersonFactory {
public:
	Person createPerson() {
		draw_frame();
		load_texture();
		define_logical_domain();
		return Person();
	}
protected:
	virtual void load_texture() = 0;
	virtual void draw_frame() = 0;
	virtual void define_logical_domain() = 0;
};

class MainPersonFactory : public PersonFactory {
protected:
	void load_texture() override {
		std::cout << "load main texture\n";
	}
	void draw_frame() override {
		std::cout << "draw rectangular frame\n";
	}
	void define_logical_domain() override {
		std::cout << "define logical domain by main algorithm\n";
	}
};

class AdditionalPersonFactory : public PersonFactory {
protected:
	void load_texture() override {
		std::cout << "load additional texture\n";
	}
	void draw_frame() override {
		std::cout << "draw circle\n";
	}
	void define_logical_domain() override {
		std::cout << "define logical domain by additional algorithm\n";
	}
};

//int main() {
//	PersonFactory* factory = new MainPersonFactory;
//	Person person = factory->createPerson();
//}