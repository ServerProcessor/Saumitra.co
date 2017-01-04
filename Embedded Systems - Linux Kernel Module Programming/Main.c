#include <linux/module.h>   /* Needed by all modules */
#include <linux/kernel.h>   /* Needed for kernel info */

int init_module(void)
  {
     printk(KERN_INFO " Hello World\n ");
     return 0;  /* A non zero return means init_module failed; can't be loaded */
  }

void cleanup_module(void)
  {
     printk(KERN_INFO " Goodbye World\n ");
  }
