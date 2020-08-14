// begining of function found online at \/ when looking for assistance
//  https://tuxthink.blogspot.com/2011/03/using-foreachprocess-in-proc-entry.html

#include<linux/module.h>
#include<linux/kernel.h>
#include <linux/proc_fs.h>
#include<linux/sched/signal.h>
#include<linux/sched.h>

struct task_struct *task;


int functn_init (void) {
    for_each_process(task) {

      printl(KERN_INFO "\n %s %d \n",task_list->comm,task_list->pid);
    }
    return 0;
}

void functn_cleanup(void) {
    remove_proc_entry("ps_list",NULL);
}

MODULE_LICENSE("GPL");   
module_init(functn_init);
module_exit(functn_cleanup);


