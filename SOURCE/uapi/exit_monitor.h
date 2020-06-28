/*
 * Linux内核诊断工具--用户接口API
 *
 * Copyright (C) 2020 Alibaba Ltd.
 *
 * 作者: Baoyou Xie <baoyou.xie@linux.alibaba.com>
 *
 * License terms: GNU General Public License (GPL) version 2
 *
 */

#ifndef UAPI_EXIT_MONITOR_H
#define UAPI_EXIT_MONITOR_H

int exit_monitor_syscall(struct pt_regs *regs, long id);

//#define DIAG_EXIT_MONITOR_ACTIVATE (DIAG_BASE_SYSCALL_EXIT_MONITOR)
//#define DIAG_EXIT_MONITOR_DEACTIVATE (DIAG_EXIT_MONITOR_ACTIVATE + 1)
#define DIAG_EXIT_MONITOR_SET (DIAG_BASE_SYSCALL_EXIT_MONITOR)
#define DIAG_EXIT_MONITOR_SETTINGS (DIAG_EXIT_MONITOR_SET + 1)
#define DIAG_EXIT_MONITOR_DUMP (DIAG_EXIT_MONITOR_SETTINGS + 1)

struct diag_exit_monitor_settings {
	unsigned int activated;
	unsigned int verbose;
	unsigned int tgid;
	char comm[TASK_COMM_LEN];
};

struct exit_monitor_detail {
	int et_type;
	int seq;
	unsigned long id;
	struct timeval tv;
	struct diag_task_detail task;
	struct diag_kern_stack_detail kern_stack;
	struct diag_user_stack_detail user_stack;
	struct diag_raw_stack_detail raw_stack;
};

struct exit_monitor_map {
	int et_type;
	int seq;
	unsigned long id;
	struct timeval tv;
	struct diag_task_detail task;
	dev_t dev;
	unsigned long ino;
	unsigned long long pgoff;
	unsigned long start;
	unsigned long end;
	unsigned long flags;
	char file_name[255];
};
#endif /* UAPI_EXIT_MONITOR_H */
