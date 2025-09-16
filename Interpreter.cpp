
#include <iostream>

struct Command {
	int address;
	int num;
	int first_operand;
	int second_operand;
};

class Interpreter {
public:
	virtual int interpret(Command& command) = 0;
};

class AddressInterpreter : public Interpreter {
public:
	int interpret(Command& command) override {
		if (command.address == 0) {
			std::cout << "send all\n";
		}
		else if (command.address > 0 && command.address < 246) {
			std::cout << "send to " << command.address << std::endl;
		}
		else {
			return 2;
		}
		return 0;
	}
};

class FunctionInterpreter : public Interpreter {
public:
	int interpret(Command& command) override {
		if (command.num == 0) {
			command.first_operand += command.second_operand;
			command.second_operand = 0;
		}
		else if (command.num == 1) {
			command.first_operand *= command.second_operand;
			command.second_operand = 0;
		}
		else {
			return 2;
		}
		return 0;
	}
};

class AppInterpreter : public Interpreter {
public:
	int interpret(Command& command) override {
		int res1 = addrInterpreter.interpret(command);
		int res2 = funcInterpreter.interpret(command);
		if (res1 != 0 || res2 != 0) {
			return 2;
		}
		return 0;
	}
private:
	AddressInterpreter addrInterpreter;
	FunctionInterpreter funcInterpreter;
};

//int main() {
//	AppInterpreter interpreter;
//	Command command{ 0, 1, 11, 300 };
//	int res = interpreter.interpret(command);
//	std::cout << res << std::endl;
//	command = Command{ 455, 1, 11, 300 };
//	res = interpreter.interpret(command);
//	std::cout << res;
//}