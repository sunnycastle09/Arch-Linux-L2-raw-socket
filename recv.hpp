#ifndef BOTANHPP
#define BOTANHPP
#include <sys/syscall.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstdio>

namespace botan {
	int fd;
	unsigned char buffer[65536];
	void socket_r() {
		fd = syscall(SYS_socket, AF_PACKET, SOCK_RAW, htons(0x88b5));
		if (fd < 0) {
			perror("socket");
		}
	}
	int recv() {
		long result = syscall(SYS_recvfrom, fd, buffer, sizeof(buffer), 0, nullptr, nullptr);
		if (result < 0) {
			perror("recvfrom");
		}
		return result;
	}
	void close_socket() {
		syscall(SYS_close, fd);
	}
}
#endif
