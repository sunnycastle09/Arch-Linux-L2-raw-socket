#ifndef BOTANHPP
#define BOTANHPP
#include <sys/syscall.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstdio>
extern fd;
namespace botan {
	unsigned char buffer[65536];
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
