#include <memory>
#include <string>
#include <exception>

class System {};

class Windows : public System {};
class Linux : public System {};
class Mac : public System {};


class SystemFactory {
public:
    static std::shared_ptr<System> createSystem(const std::string& sys) {
        if (sys == "windows") {
            return std::make_shared<Windows>();
        }
        else if (sys == "linux") {
            return std::make_shared<Linux>();
        }
        else if (sys == "mac") {
            return std::make_shared<Mac>();
        }
        else {
            throw std::exception("System not found!");
        }
    }
};

class Application {
public:
    void setSystem(const std::string& sys) {
        system = SystemFactory::createSystem(sys);
    }

private:
    std::shared_ptr<System> system;
};

//int main() {
//    Application app;
//    app.setSystem("linux");
//}