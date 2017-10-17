#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/slab.h>

int init_module(void)
{
	void *p;
	printk(KERN_INFO "Allocating memory.\n");
	p = kmalloc(1024, GFP_KERNEL);

	if (p)
		return 0;
	return 1;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}
