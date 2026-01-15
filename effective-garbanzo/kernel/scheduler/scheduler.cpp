#include "scheduler.hpp"
#include "..//cpu/paging.hpp" // IWYU pragma: keep

Task task_table[16];
int task_count=0;
int current_task=0;

void scheduler_init() {
    for(int i=0;i<16;i++) {
        task_table[i].id=i;
    }
}

void scheduler_add_task(Task* t) {
    if(task_count<16){
        task_table[task_count]=*t;
        task_count++;
    }
}

void schedule(){
    current_task=(current_task+1)%task_count;
}
