
#include <iostream>

enum class ButtonEvent {
	left_button_clicked,
	right_button_clicked,
};
using enum ButtonEvent;

class Handler {
public:
	virtual void process_button(ButtonEvent event) = 0;
};

class AppHandler : public Handler {
public:
	void process_button(ButtonEvent event) override {
		if (event == right_button_clicked) {
			std::cout << "exit\n";
		}
	}
};

class DialogHandler : public Handler {
public:
	DialogHandler(Handler* parentHandler) : parentHandler(parentHandler) {}
	void process_button(ButtonEvent event) {
		if (event == left_button_clicked) {
			std::cout << "dialog ok\n";
		}
		else {
			parentHandler->process_button(event);
		}
	}
private:
	Handler* parentHandler;
};

class Button {
public:
	Button(Handler* handler) : handler(handler) {}
	void emit_signal(ButtonEvent event) {
		handler->process_button(event);
	}
private:
	Handler* handler;
};

//int main() {
//	AppHandler handler;
//	DialogHandler dialogHandler(&handler);
//	Button button(&dialogHandler);
//	button.emit_signal(right_button_clicked);
//}