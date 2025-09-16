
#include <vector>

class Object {
public:
	virtual ~Object() = default;
	virtual void render() = 0;
	virtual void process_event() = 0;
};

class Texture : public Object {
public:
	void render() override {}
	void process_event() override {}
};

class Panel : public Object {
public:
	void add(Object* object) {
		objects.push_back(object);
	}
	void render() override {
		for (auto object : objects) {
			object->render();
		}
	}
	void process_event() override {
		for (auto object : objects) {
			object->process_event();
		}
	}

private:
	std::vector<Object*> objects;
};

//int main() {
//	Texture texture;
//	Texture t1;
//	Texture t2;
//	Panel panel;
//	panel.add(&t1);
//	panel.add(&t2);
//	texture.process_event();
//	panel.process_event();
//}