#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Adamya Verma");
MODULE_DESCRIPTION("first dynamic kernal module");

static struct proc_dir_entry *custom_proc_node;
// ssize_t	(*proc_read)(struct file *, char __user *, size_t, loff_t *);
static ssize_t	ldd_read(struct file * file_pointer, char __user *user_space_buffer , size_t count, loff_t *offset){
    printk("entered the read function\n");
    char msg[]="awk\n";
    size_t len=strlen(msg);
    int result;

    if(*offset>=len){//to ensure that doesn't [rints infinitly]
        return 0;
    }
    //api to write to user buffer
    result =copy_to_user(user_space_buffer,msg,len);
    *offset+=len;
    return len;//return the number of bytes
}


struct proc_ops driver_proc_ops={
    .proc_read=ldd_read,
};


static int init_function(void){
    printk("entered the init function\n");
    custom_proc_node=proc_create("ldd_driver", 0, NULL, &driver_proc_ops);
    printk("exited the init function\n");
    return 0;
}

static void exit_function(void){
    printk("entered the exit function\n");
    proc_remove(custom_proc_node);
    printk("exited the exit function\n");
    
}

module_init(init_function);
module_exit(exit_function);