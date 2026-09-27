This is for Linux network namespace communication with *Raw Socket*.
# sender.hpp
**namespace is botan_s**
- ### `socket_s()`
Gen socket object and file descriptor to communicate.
If cant generate socket, then print error message.
>`perror("socket")`
