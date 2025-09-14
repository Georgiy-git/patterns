#include <memory>
#include <string>
#include <iostream>

class Object {};

class Panel : public Object {};
class Line : public Object {};
class Button : public Object {};

class QtPanel : public Panel {};
class QtLine : public Line {};
class QtButton : public Button {};

class SDLPanel : public Panel {};
class SDLLine : public Line {};
class SDLButton : public Button {};

class ObjectFactory {
public:
	static std::unique_ptr<ObjectFactory> createFactory(const std::string& libraryType);
	virtual ~ObjectFactory() = default;
	virtual std::shared_ptr<Panel> createPanel() = 0;
	virtual std::shared_ptr<Line> createLine() = 0;
	virtual std::shared_ptr<Button> createButton() = 0;
};

class SDLObjectFactory : public ObjectFactory {
public:
	std::shared_ptr<Panel> createPanel() override {
		return std::make_shared<SDLPanel>();
	}
	std::shared_ptr<Button> createButton() override {
		return std::make_shared<SDLButton>();
	}
	std::shared_ptr<Line> createLine() override {
		return std::make_shared<SDLLine>();
	}
};

class QtObjectFactory : public ObjectFactory {
public:
	std::shared_ptr<Panel> createPanel() override {
		return std::make_shared<QtPanel>();
	}
	std::shared_ptr<Button> createButton() override {
		return std::make_shared<QtButton>();
	}
	std::shared_ptr<Line> createLine() override {
		return std::make_shared<QtLine>();
	}
};

//factory method
std::unique_ptr<ObjectFactory> ObjectFactory::createFactory(const std::string& libraryType) {
	if (libraryType == "Qt") { return std::make_unique<QtObjectFactory>(); }
	else if (libraryType == "SDL") { return std::make_unique<SDLObjectFactory>(); }
	else {
		throw std::exception("Library not defined");
	}
}

//int main() {
//	auto objectFactory = ObjectFactory::createFactory("SDL");
//	auto panel = objectFactory->createPanel();
//	auto button = objectFactory->createButton();
//}