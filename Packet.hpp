#pragma once
#include <string>
#include "PacketType.hpp"
#include "Protocol.hpp"
#include "Status.hpp"
class Packet {

private:
	
	PacketType type;
	Status packetStatus;
	Protocol protocol;

public:

	void setType(PacketType newType);
	Packet(PacketType pType, Protocol prtcl);
	std::string getProtocolName();
	std::string getPacketTypeName();
	std::string getStatusName();
	bool validatePacket();
	bool isError();
	void displayInfo();
};

