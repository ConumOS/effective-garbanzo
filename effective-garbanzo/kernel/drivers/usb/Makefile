CXX=clang++
CXXFLAGS=-ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -target i686-elf -I../../../kernel
OBJ=xhci.o usb_manager.o hid_kbd.o

all: $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o
