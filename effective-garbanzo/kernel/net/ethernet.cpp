#include "net/ethernet.hpp"
#include "net/tcpip.hpp"
#include "drivers/vga.hpp"

void net_init(){
    vga_print("NET INIT... OK\n");
    // Placeholder: inicializar NIC, ARP, ICMP, TCP, UDP
}
