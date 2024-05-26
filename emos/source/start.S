	#include "os.h"

	// 声明本地以下符号是全局的，在其它源文件中可以访问
	.global _start, timer_init

	// 指定以下的代码生成16位的机器指令，这样才能在启动时的实模式下运行
  	.code16

	// 以下是代码区
 	.text
_start: 
	mov $_start, %esp


read_disk:
	mov $_start_32, %bx // 写入开始的地址 0x7e00
	mov $0x2, %cx // 起始扇区号
	mov $0x240, %ax // al扇区数量 64， ah 02表示读磁盘 给 bios 程序
	mov $0x80,%dx // 读取的磁盘驱动器号


	int $0x13 // bios 中断 低级磁盘服务, 调用磁盘读写功能 https://baike.baidu.com/item/BIOS%E4%B8%AD%E6%96%AD%E8%B0%83%E7%94%A8/22788153

	jc read_disk // 读取磁盘失败则再次读取 JC=Jump if Carry当运算产生进位标志时，即CF=1时，跳转到目标程序处

	# ============= 进入保护模式 =============
	cli // 关闭中断
	lgdt [gdt_desc] // LGDT和SGDT分别用于加载和保存GDTR寄存器的内容
	lidt [idt_desc]
	mov $1, %eax
	lmsw %ax // 设置cr0的PE位
	jmp $KERNEL_CODE_SEG, $_start_32 // 跳转相对地址 

	.org 0x1fe	 // .org 设置程序起始位置, 0xc700 - 2字节给0x55aa留空间
	.byte 0x55, 0xaa	// 设置是否为可引导磁盘标识位

	.code32 // 切换以下代码生成32位的机器指令
	.text
_start_32:
	mov $KERNEL_DATA_SEG,%ax
	mov %ax,%ds
	mov %ax,%es
	mov %ax,%fs
	mov %ax,%gs
	mov $_start,%esp

	# ============= 设置分页 ========

	call os_init

	mov $page_dir, %eax // 设置页表
	mov %eax, %cr3 // 写入cr3


	mov %cr4, %eax // 读取cr4
	orl $(1<<4), %eax // 设置cr4的PAE位 设置允许分页
	mov %eax, %cr4 // 写入cr4

	mov %cr0, %eax // 读取cr0
	orl $(1<<31), %eax // 设置cr0的PG位
	mov %eax, %cr0 // 写入cr0


	sti // 开启中断

	jmp . 

timer_init:
	push %ds // 保存数据段寄存器
	pusha // 保存寄存器
	mov $0x20, %ax
	outb %al, $0x20

	popa // 恢复寄存器
	pop %ds // 恢复数据段寄存器

	iret // 中断返回

task_0_entry:
	jmp .


gdt_desc:
	.word (256*8) - 1 // 界限
	.long GDT_TABLE // 基址

idt_desc:
	.word (256*8) - 1 // 界限
	.long IDT_TABLE // 基址


