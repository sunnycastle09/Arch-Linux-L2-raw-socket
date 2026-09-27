#include <iostream>
#include "sender.hpp"

int main(){
	botan_s::socket_s();
	int size=botan_s::framing(4,0x8ecf85317965,0x52bb266b33a9,"hello_world");
}
