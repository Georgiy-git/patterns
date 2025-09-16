
#include <iostream>

class API {
public:
	virtual ~API() = default;
	virtual void drawPoint() = 0;
	virtual void drawLine() = 0;
};

class WinAPI : public API {
public:
	void drawPoint() override {}
	void drawLine() override {}
};

class LinuxAPI : public API {
public:
	void drawPoint() override {}
	void drawLine() override {}
};

class Object {
public:
	Object(API* api) : api(api) {}

protected:
	API* api;
};

class Rect : public Object {
public:
	Rect(API* api) : Object(api) {
		api->drawLine();
		api->drawLine();
		api->drawLine();
		api->drawLine();
	}
};

//int main() {
//	WinAPI api;
//	Rect rect(&api);
//}