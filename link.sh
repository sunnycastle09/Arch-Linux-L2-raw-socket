ip netns add ns1
ip netns add ns2
ip link add veth1 type veth peer veth2
ip link set veth1 netns ns1
ip link set veth2 netns ns2
ip netns exec ns1 ip link set veth1 up
ip netns exec ns2 ip link set veth2 up
ip netns exec ns1 ip link show
ip netns exec ns2 ip link show
