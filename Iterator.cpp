
#include <iostream>
#include <any>

class Item {};

class ListItem : public Item {
public:
	std::any value;
	ListItem* next;
	ListItem* last;
};

class Iterator {
public:
	virtual void next() = 0;
	virtual void back() = 0;
};

class ListIterator : public Iterator {
public:
	void next() override {
		current_item = current_item->next;
	}
	void back() override {
		current_item = current_item->last;
	}
	ListItem* current_item = nullptr;
	ListItem* first_item = nullptr;
};

class List {
public:
	void add(std::any value) {
		auto new_item = new ListItem;
		new_item->value = value;
		new_item->last = iterator.current_item;

		if (iterator.first_item == nullptr) {
			iterator.first_item = iterator.current_item = new_item;
		}
		else {
			iterator.current_item->next = new_item;
			iterator.current_item = new_item;
		}
	}
	ListItem* begin() {
		iterator.current_item = iterator.first_item;
		return iterator.first_item;
	}
	ListItem* next() {
		iterator.next();
		return iterator.current_item;
	}
	ListItem* back() {
		iterator.back();
		return iterator.current_item;
	}

private:
	ListIterator iterator;
};

//int main() {
//	List list;
//	list.add({ 133 });
//	list.add({ 99 });
//	list.add({ 4422287 });
//	std::cout << std::any_cast<int>(list.begin()->value) << '\n' <<
//		std::any_cast<int>(list.next()->value) << '\n' << 
//		std::any_cast<int>(list.next()->value) << '\n' << 
//		std::any_cast<int>(list.back()->value);
//}