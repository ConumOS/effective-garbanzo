#include "vga.hpp"

volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;
uint8_t color = 0x07;

void vga_print(const char* str) {
    for (int i = 0; str[i]; i++)
        vga_buffer[i] = (color << 8) | str[i];
}
void vga_clear() {
    for (int i=0;i<80*25;i++)
        vga_buffer[i]=(color<<8)|' ';
}
void vga_set_color(uint8_t fg,uint8_t bg){color=(bg<<4)|fg;}
