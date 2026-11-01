#ifndef BOTAN_HPP
#define BOTAN_HPP
#include <sys/syscall.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <linux/if_ether.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>

namespace botan {
	int fd;
	unsigned char buffer[65536];
	void socket() { //only once execute in one netns
		fd = syscall(SYS_socket, AF_PACKET, SOCK_RAW, htons(0x88b5));
		if (fd < 0) {
			perror("socket");
		}
	}
	//int framing(ifindex,desmac,srcmac,payload)
	int framing(int ifindex,std::string desmac, std::string srcmac, std::string payload) {
		long des_mac=std::stoull(desmac,nullptr,16);
		long src_mac=std::stoull(srcmac,nullptr,16);
		std::vector <unsigned char> frame;
		unsigned char tmp;
		for (int i = 0; i < 6; i++) { //desmac
			tmp = static_cast<unsigned char>((des_mac >> 40 - (8 * i)) & 0xff);
			frame.push_back(tmp);
		}
		for (int i = 0; i < 6; i++) { //srcmac
			tmp = static_cast<unsigned char>((src_mac >> 40 - (8 * i)) & 0xff);
			frame.push_back(tmp);
		}
		frame.push_back(0x88);//type
		frame.push_back(0xb5);
		for (int i = 0; i < payload.length(); i++) {
			frame.push_back(payload[i]);
		}
		struct sockaddr_ll addr { 0 };
		addr.sll_family = AF_PACKET;
		addr.sll_protocol = htons(0x88b5);
		addr.sll_ifindex = ifindex;
		addr.sll_halen = ETH_ALEN;
		memcpy(addr.sll_addr, frame.data(), ETH_ALEN);
		long result = syscall(SYS_sendto, fd, frame.data(), frame.size(), 0, &addr, sizeof(addr));
		std::cout << "\n";
		if (result < 0) {
			perror("sendto");
			exit(1);
		}
		return frame.size();
	}
	sockaddr_ll addr_rcv{};
	socklen_t addr_len=sizeof(addr_rcv);
	int recv() {
		long result = syscall(SYS_recvfrom, fd, buffer, sizeof(buffer), 0, &addr_rcv, &addr_len);
		if (result < 0) {
			perror("recvfrom");
			exit(1);
		}
		return result;
	}
	void close_socket() {
		syscall(SYS_close, fd);
	}
}
#endif
