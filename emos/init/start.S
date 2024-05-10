	#include "os.h"

	// 声明本地以下符号是全局的，在其它源文件中可以访问
	.global _start

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

	jmp .

	.org 0x1fe	 // .org 设置程序起始地址 0x1fe , 0x1fe = 510 后面就是0x7c00
	.byte 0x55, 0xaa	// 0x7c00 引导程序的入口

_start_32:
	.fill 64*1024,1,0x35

