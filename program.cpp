#include <iostream>
#include "recv.hpp"
#include <cstdlib>
 
int main(){
	botan_r::socket_r(); 
	std::system("ip netns exec ns1 ./send");
	int size=botan_r::recv();
	std::cout<<"\ndes mac: ";
	for(int i=0;i<6;i++){
		std::cout<<std::hex<<static_cast<int>(botan_r::buffer[i])<<":";
	}	
	std::cout<<"\nsrc mac: ";
	for(int i=6;i<12;i++){
		std::cout<<std::hex<<static_cast<int>(botan_r::buffer[i])<<":";
	}
	std::cout<<"\npayload: ";
	for(int i=14;i<size;i++){
		std::cout<<botan_r::buffer[i];
	}
	//
	std::cout<<"\n";
}

