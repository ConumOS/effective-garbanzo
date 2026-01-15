#ifndef PAGING_HPP
#define PAGING_HPP

#include <stdint.h>
#include <stddef.h>

namespace paging {

    /**
     * Mapeia uma região de hardware (MMIO) para o espaço virtual do kernel.
     * @param physical_addr Endereço físico (ex: BAR0 da GPU)
     * @param size Tamanho da região em bytes
     * @return Ponteiro para o endereço virtual mapeado
     */
    void* map_device(uintptr_t physical_addr, size_t size);

    /**
     * Função base para mapear uma única página de 4KB.
     * Implementada no paging.cpp
     */
    void map_page(uintptr_t phys, uintptr_t virt, uint32_t flags);

} // namespace paging

#endif
