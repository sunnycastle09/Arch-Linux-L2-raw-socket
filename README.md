This is for Linux network namespace communication with *Raw Socket*.
# sender.hpp
**namespace is botan_s**
- ### `void socket_s()`
Generate socket object and file descriptor to communicate.  
- ### `int framing()`
Generate frame from parameter value.  
and make sock11 struct about where to send frame.  
Calls the `sendto()` syscall and pass frame, sock11 struct as argument.
# recv.hpp
**namespace is botan_r**
- ### `void socket_r()`
Generate socket object and file descriptor to receieve frame.  
- ### `int recv()`
Receieve frame from socket object and store at buffer array. Return frame size.
- ### `void close_socket()`
close socket.
  
