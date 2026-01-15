#ifndef PCI_HPP
#define PCI_HPP

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t pci_read_config_32(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset);
void pci_write_config_32(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset, uint32_t value);

#ifdef __cplusplus
}
#endif

#endif
