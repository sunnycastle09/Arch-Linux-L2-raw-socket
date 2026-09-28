This is for Linux network namespace communication with *Raw Socket*.
# sender.hpp
**namespace is botan_s**
- ### `void socket_s()`
Create socket and file descriptor to communicate.  
- ### `int framing()`
Creates a frame from given parameter value.  
and make sockaddr_11 struct specifiyng where to send frame.  
Calls the `sendto()` syscall and pass frame, sockaddr_11 structure as argument.
# recv.hpp
**namespace is botan_r**
- ### `void socket_r()`
Create socket and file descriptor to receive frame.  
- ### `int recv()`
Receive frame from socket and store at buffer array. Return frame size.
- ### `void close_socket()`
close socket.
**Must call receive_r first. If call socket_r, the process blocked until receive frame. So call it on background and send frame.**
# Example
- link.sh is create netns(ns1, ns2).
- ns1: sender, ns2: reciever.
- run program.cpp on background(`ip netns exec ns2 ./program &`
- it create socket and run send.exe by `system("ip netns exec ns1 send")`.
- then ns2 will recv.
