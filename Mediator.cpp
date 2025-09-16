
#include <tuple>
#include <vector>
#include <iostream>

class EventHandler;

class Object {
public:
	Object(EventHandler* handler);
	virtual void process_event(int event_num);
	void emit_signal(int event_num);
private:
	EventHandler* handler;
};

class EventHandler {
public:
	void connect(Object* sender, Object* recipient, int event_num) {
		events.push_back({ sender, recipient, event_num });
	}
	void process_event(Object* sender, int event_num) {
		for (auto [_sender, _recipient, _event_num] : events) {
			if (_sender == sender && event_num == _event_num) {
				_recipient->process_event(event_num);
			}
		}
	}
private:
	std::vector<std::tuple<Object*, Object*, int>> events;
};

Object::Object(EventHandler* handler) : handler(handler) {}
void Object::emit_signal(int event_num) {
	handler->process_event(this, event_num);
}
void Object::process_event(int event_num) {}

class Texture : public Object {
public:
	using Object::Object;
	void change_frame() {
		std::cout << "change frame\b";
	}
	void process_event(int event_num) override {
		if (event_num == 5) {
			change_frame();
		}
	}
};

class Button : public Object {
public:
	using Object::Object;
	void click() {
		emit_signal(5);
	}
};

//int main() {
//	EventHandler handler;
//	Texture texture(&handler);
//	Button button(&handler);
//	handler.connect(&button, &texture, 5);
//	button.click();
//}