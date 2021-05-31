#include <linux/module.h>
#include <linux/kallsyms.h>
#include <linux/sched/mm.h>
#include <linux/syscalls.h>
#include <asm/syscall_wrapper.h>

#define __NR_add 549

void **syscall_table;

asmlinkage pid_t (*real_add)(struct pt_regs *regs);

__SYSCALL_DEFINEx(1, file_varea, pid_t, pid)
{
	struct task_struct *t;
	t = pid_task(find_vpid(pid), PIDTYPE_PID);
	
	struct vm_area_struct *pp=t->mm->mmap;

	printk(KERN_INFO "######## Loaded files of a process '%s(%d)' in VM ########\n", t->comm,pid);

	char buf[100]={0};
	
	while(pp){
		if(pp->vm_file!=0)
		printk(KERN_INFO " mem(%0lx~%0lx) code(%0lx~%0lx) data(%0lx~%0lx) heap(%0lx~%0lx) %s\n", pp->vm_start, pp->vm_end, t->mm->start_code, t->mm->end_code, t->mm->start_data, t->mm->end_data, t->mm->start_brk, t->mm->brk, dentry_path_raw((pp->vm_file->f_path.dentry),buf,100));
		pp=pp->vm_next;
	}
	
	printk(KERN_INFO "################################################################\n");
}

void make_rw(void *addr){
	unsigned int level;
	pte_t *pte = lookup_address((u64)addr, &level);

	if(pte->pte &~ _PAGE_RW)
		pte->pte |= _PAGE_RW;
}

void make_ro(void *addr){
	unsigned int level;
	pte_t *pte = lookup_address((u64)addr, &level);

	pte->pte = pte->pte &~ _PAGE_RW;
}

static int __init file_varea_init(void)
{
	syscall_table = (void**) kallsyms_lookup_name("sys_call_table");

	make_rw(syscall_table);
	
	real_add = syscall_table[__NR_add];
	syscall_table[__NR_add] = __x64_sysfile_varea;

	return 0;

}

static void __exit file_varea_exit(void)
{
	syscall_table[__NR_add] = real_add;
	
	make_ro(syscall_table);	
}


module_init(file_varea_init);
module_exit(file_varea_exit);
MODULE_LICENSE("GPL");
