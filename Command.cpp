
//Action, Transaction

#include <iostream>

class Command {
public:
	virtual void execute() = 0;
};

class Application {
public:
	void app_exit() {
		std::cout << "exit\n";
	}
};

class ExitCommand : public Command {
public:
	ExitCommand(Application* app) : app(app) {}
	void execute() override {
		app->app_exit();
	}
private:
	Application* app;
};

class Button {
public:
	void connect(Command* command) { this->command = command; }
	void disconnect() {
		command = nullptr;
	}
	void click() {
		if (command != nullptr) {
			command->execute();
		}
	}
private:
	Command* command = nullptr;
};

//int main() {
//	Application app;
//	ExitCommand exitCommand(&app);
//	Button button;
//	button.connect(&exitCommand);
//	button.click();
//	button.disconnect();
//	button.click();
//}