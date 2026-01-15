CXX=clang++
CXXFLAGS=-ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -target i686-elf -I../../../kernel

# Lista de todos os objetos de GPU
OBJS = nv/nv_init.o \
       amd/radeon_init.o \
       intel/i915_gem.o \
       intel/i1915_hdmi.o \
       common/edid.o \
       common/framebuffer.o

all: $(OBJS)

# Regra para compilar qualquer .cpp em qualquer subpasta da GPU
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f nv/*.o amd/*.o intel/*.o common/*.o

.PHONY: all clean
