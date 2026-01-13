// kernel/kernel.cpp
extern "C" void kernel_main();


void print(const char* str) {
    volatile char* vga = (volatile char*)0xB8000;
    for (int i = 0; str[1]; i++) {
        vga[i * 2] = str[i];
        vga[i * 2 + 1] = 0x07;
    }
}


extern "C" void kernel_main() {
    print("LOAD KERNEL... OK");
    while (1) {}
}