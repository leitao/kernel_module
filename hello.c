#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/slab.h>

void *p;

int init_module(void)
{
	int x = 0;

	printk(KERN_INFO "Allocating memory.\n");
	p = kmalloc(1024, GFP_KERNEL);
	if (p){
		x = ((int *) p)[1024];
		return 0;
	}	
	return x;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Not freeing p = %p.\n", p);
}
