
//Wrapper

#include <iostream>

class Object {
public:
	virtual ~Object() = default;
	virtual void render() = 0;
};

class Widget : public Object {
public:
	void render() override {
		std::cout << "render widget\n";
	}
};

class ObjectComplement : public Object {
public:
	ObjectComplement(Object* object) : object(object) {}

protected:
	Object* object;
};

class TitleComplement : public ObjectComplement {
public:
	using ObjectComplement::ObjectComplement;
	void render() override {
		std::cout << "draw title\n";
		object->render();
	}
};

class FrameComplement : public ObjectComplement {
public:
	using ObjectComplement::ObjectComplement;
	void render() override {
		std::cout << "draw frame\n";
		object->render();
	}
};

//int main() {
//	Widget widget;
//	TitleComplement with_title(&widget);
//	FrameComplement with_frame(&with_title);
//	with_frame.render();
//}