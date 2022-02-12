#pragma once

#include <kernel/process.h>

struct irq_callback {
	int (*callback)(process_t * this, int irq, void *data);
	process_t * owner;
	void * data;
	struct irq_callback * next;
};

extern struct irq_callback * irq_callbacks[];

void gic_assign_interrupt(int irq, int (*callback)(process_t*,int,void*), void * data);
void gic_map_pci_interrupt(const char * name, uint32_t device, int * int_out, int (*callback)(process_t*,int,void*), void * isr_addr);
