#pragma once
#include <stdint.h>

struct Task {
    uint32_t esp, ebp;
    uint32_t eip;
    uint32_t id;
    char name[32];
};

void scheduler_init();
void scheduler_add_task(Task* t);
void schedule();
