/**
 * simple.c
 *
 * A simple kernel module. 
 * 
 * To compile, run makefile by entering "make"
 *
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */


#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#define  GOLDEN_RATIO_PRIME 3.1415
extern HZ;

int gcd(int x, int y){
    int gcd, i;
    for( i=1; i <= x && i <= y; ++i)
    {
        // Checks if i is factor of both integers
        if(x%i==0 && y%i==0)
            gcd = i;
    }

    return gcd;
}

/* This function is called when the module is loaded. */
static int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");
       printk(KERN_INFO "%lu\n", GOLDEN_RATIO_PRIME);

       return 0;
}

/* This function is called when the module is removed. */
static void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
    printk(KERN_INFO "%d\n", HZ);
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

