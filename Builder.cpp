
#include <memory>
#include <string>
#include <iostream>
#include <vector>

using data = std::string;
using frame = std::string;


struct FrameComplement {
	frame _frame;
};

struct TCPFrame : public FrameComplement {};

struct UDPFrame : public FrameComplement {};

struct ModbusFrame : public FrameComplement {};


class ProtocolBuilder {
public:
	virtual ~ProtocolBuilder() = default;
	virtual int calculate_checksum(const data& _data) = 0;
	virtual void append_checksum(data& _data, int checksum) = 0;
	virtual void append_address(data& _data, int address) = 0;
	virtual FrameComplement build(data _data) = 0;
};

class TCPBuilder : public ProtocolBuilder {
public:
	FrameComplement build(data _data) override {
		append_address(_data, 1);
		int checksum = calculate_checksum(_data);
		append_checksum(_data, checksum);
		return TCPFrame{ _data };
	}

protected:
	int calculate_checksum(const data& _data) override {
		return _data.size() + 8;
	}
	void append_checksum(data& _data, int checksum) override {
		_data +=  '|' + std::to_string(checksum);
	}
	void append_address(data& _data, int address) override {
		_data += "0x" + std::to_string(address);
	}
};

class UDPBuilder : public ProtocolBuilder {
public:
	FrameComplement build(data _data) override {
		int checksum = calculate_checksum(_data);
		append_checksum(_data, checksum);
		append_address(_data, 4);
		return UDPFrame{ _data };
	}

protected:
	int calculate_checksum(const data& _data) override {
		return _data.size() + 4;
	}
	void append_checksum(data& _data, int checksum) override {
		_data += '!' + std::to_string(checksum);
	}
	void append_address(data& _data, int address) override {
		_data += "0x0" + std::to_string(address);
	}
};

class ModbusBuilder : public ProtocolBuilder {
public:
	FrameComplement build(data _data) override {
		int checksum = calculate_checksum(_data);
		append_checksum(_data, checksum);
		append_address(_data, 16);
		return ModbusFrame{ _data };
	}

protected:
	int calculate_checksum(const data& _data) override {
		return _data.size() + 2;
	}
	void append_checksum(data& _data, int checksum) override {
		_data += '#' + std::to_string(checksum);
	}
	void append_address(data& _data, int address) override {
		_data += "x" + std::to_string(address);
	}
};


class NetworkHandler {
public:
	NetworkHandler(std::shared_ptr<ProtocolBuilder> builder) : 
		builder(builder) {}

	std::vector<FrameComplement> construct_frames(std::vector<data> _data) {
		std::vector<FrameComplement> frames;
		for (const auto& elem : _data) {
			frames.push_back(builder->build(elem));
		}
		return frames;
	}
private:
	std::shared_ptr<ProtocolBuilder> builder;
};

//int main() {
//	std::shared_ptr<UDPBuilder> builder = std::make_shared<UDPBuilder>();
//	std::vector<data> info{ "12441", "43523", "hello" };
//	NetworkHandler handler(std::move(builder));
//	auto frames = handler.construct_frames(info);
//}