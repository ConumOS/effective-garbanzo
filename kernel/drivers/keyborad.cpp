#include "keyborad.hpp"


static inline unsigned char inb(unsigned short port) {
unsigned char ret;
asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
return ret;
}


void keyboard_init() {
 // get out my code my OS nigga!
 inb(0x60);
}
