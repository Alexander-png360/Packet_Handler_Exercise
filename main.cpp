#include "Packet.hpp"
#include <iostream>

int main() {

	Packet udpPacket(DATA, UDP);
	udpPacket.validatePacket();
	udpPacket.displayInfo();
	
	Packet tcpPacket(DATA, TCP);
	tcpPacket.validatePacket();
	tcpPacket.displayInfo();

	Packet unknownPacket(UNKNOWN, TCP);
	unknownPacket.validatePacket();
	unknownPacket.displayInfo();
}