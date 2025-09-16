
//Token

#include <utility>
#include <optional>
#include <vector>
#include <iostream>

struct State {
	int level;
	std::pair<int, int> coordinates;
	int hp;
};

class PersonMemento {
public:
	void set_state(const State& state) {
		states.push_back(state);
	}
	State get_last_state() {
		State last_state = states.back();
		states.pop_back();
		return last_state;
	}

private:
	std::vector<State> states;
};

class Person {
public:
	void update(std::optional<int> level = std::nullopt,
		std::optional<std::pair<int, int>> coordinates = std::nullopt,
		std::optional<int> hp = std::nullopt) {
		if (level.has_value()) state.level = level.value();
		if (coordinates.has_value()) state.coordinates = coordinates.value();
		if (hp.has_value()) state.hp = hp.value();
		memento.set_state(state);
	}
	const State& get_state() {
		return state;
	}
	void set_last_state() {
		state = memento.get_last_state();
	}
private:
	State state;
	PersonMemento memento;
};

//int main() {
//	Person person;
//	person.update(1, { {100, 100} }, 100);
//	person.update(2, { {200, 200} }, 90);
//	person.update(5, { {600, 700} }, 20);
//	person.set_last_state();
//	std::cout << person.get_state().level << std::endl;
//	person.set_last_state();
//	std::cout << person.get_state().level << std::endl;
//	person.set_last_state();
//	std::cout << person.get_state().level << std::endl;
//}