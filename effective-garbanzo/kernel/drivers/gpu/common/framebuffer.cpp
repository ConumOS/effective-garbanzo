// kernel/drivers/gpu/common/framebuffer.cpp
#include <stdint.h>

struct Framebuffer {
    uint32_t* address;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    uint8_t bpp;
};

static Framebuffer target_fb;

void fb_init(void* addr, uint32_t w, uint32_t h, uint32_t p) {
    target_fb.address = (uint32_t*)addr;
    target_fb.width = w;
    target_fb.height = h;
    target_fb.pitch = p;
}

void put_pixel(uint32_t x, uint32_t y, uint32_t color) {
    target_fb.address[y * (target_fb.pitch / 4) + x] = color;
}
