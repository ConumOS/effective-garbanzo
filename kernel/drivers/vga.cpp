// kernel/drivers/vga.cpp
void vga_put(char c, int pos) {
    volatile char* vga = (volatile char*)0xB8000;
    vga[pos * 2] = c;
    vga[pos * 2 + 1] = 0x0F;
}