#include "Packet.hpp"
#include <iostream>

void Packet::setType(PacketType newType) {
	type = newType;
}

Packet::Packet(PacketType pType, Protocol prtcl) 
	: type(pType), protocol(prtcl)
	{
	}

bool Packet::isError() {
	return packetStatus == INVALID;
}

void Packet::displayInfo() {
	std::cout << "Type: " << getPacketTypeName() << '\n';
	std::cout << "Protocol: " << getProtocolName() << '\n';
	std::cout << "Status: " << getStatusName() << '\n';
}

bool Packet::validatePacket() {
	switch (type) {
	case DATA :
		if (protocol == TCP || protocol == UDP) {
			packetStatus = VALID;
		} else {
			packetStatus = INVALID;
		}
		break;

	case CONTROL: 
		if (protocol == TCP){
			packetStatus = VALID;
		} else {
			packetStatus = INVALID;
		}
		break;

	case ERROR:
		packetStatus = VALID;
		break;

	case UNKNOWN :
		packetStatus = INVALID;
		break;

	default:
			break;
	}
	
	return (packetStatus == VALID);
}

std::string Packet::getProtocolName() {
	switch (protocol) {
	case Protocol::TCP:
		return "TCP";

	case Protocol::UDP:
		return "UDP";

	case Protocol::HTTP:
		return "HTTP";

	case Protocol::FTP:
		return "FTP";
	default:
		return "Unknown Protocol";
	}

}

std::string Packet::getPacketTypeName() {
	switch (type) {
	

	case UNKNOWN:
		return "UNKNOWN";

	case DATA:
		return "DATA";

	case CONTROL:
		return "CONTROL";

	case ERROR:
		return "ERROR";

	default :
		return "Unknown Type";

	};
}

std::string Packet::getStatusName() {
	
	switch(packetStatus) {
	case PENDING:
		return "PENDING";

	case VALID:
		return "VALID";

	case INVALID:
		return "INVALID";

	case TIMEOUT:
		return "TIMEOUT";
	default:
		return "UNKNOWN STATUS";
	};
}