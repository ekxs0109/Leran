
#include "os.h"

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;


struct 
{
	uint16_t offset_l;
	uint16_t selector;
	uint16_t attr;
	uint16_t offset_h;
} IDT_TABLE[256] __attribute__((aligned(8)));



struct
{
	uint16_t limit_l;			 // 段界限
	uint16_t base_l;			 // 基址
	uint16_t base_hl_attr; // 基址高4位+属性
	uint16_t base_limit;	 // 基址+段界限
} GDT_TABLE[256] __attribute__((aligned(8))) = {
		[KERNEL_CODE_SEG / 8] = {0xffff, 0x0000, 0x9a00, 0x00cf}, // 第0个段 0xffff 4GB
		[KERNEL_DATA_SEG / 8] = {0xffff, 0x0000, 0x9200, 0x00cf}, // 第1个段

		[APP_CODE_SEG / 8] = {0xffff, 0x0000, 0xfa00, 0x00cf}, // 用户代码段
		[APP_DATA_SEG / 8] = {0xffff, 0x0000, 0xf300, 0x00cf}, // 用户数据段
};																														// 8字节对齐

#define PDE_P (1 << 0)	// 是否存在
#define PDE_W (1 << 1)	// 是否可写
#define PDE_U (1 << 2)	// 是否用户可读
#define PDE_PS (1 << 7) // 是否4k页


#define MAP_ADDR 0x80000000

uint8_t map_phy_buffer[4096] __attribute__((aligned(4096))) = {0x36};
static uint32_t page_table[1024] __attribute__((aligned(4096))) = {PDE_U};


uint32_t page_dir[1024] __attribute__((aligned(4096))) = {
		[0] = (0) | PDE_P | PDE_W | PDE_U | PDE_PS, // 第0页 恒等映射
};



void outb(uint8_t data , uint16_t port){ // 给端口写入数据
	__asm__ __volatile__("outb %[v], %[p]"::[p]"d"(port),[v]"a"(data));
}

void timer_init(void);

void os_init(void)
{
	outb(0x11,0x20); // 初始化8259 主片 控制器 
	outb(0x11,0xA0); // 初始化8259 从片 控制器
	outb(0x20, 0x21); // 设置主片上的控制寄存器
	outb(0x28, 0xA1); // 设置从片上的控制寄存器

	outb(1 << 2, 0x21); // 告诉主片连接了从片
	outb(2,0xA1); // 告诉从片连接了主片
	outb(0x1,0x21); // 操作系统相关
	outb(0x1,0xA1); 

	outb(0xfe , 0x21); // 设置IRQ0开启

	int tmo = 1193180 / 100; // 时钟频率 1193180是每秒振荡次数, 这里为 100毫秒
	outb(0x36, 0x43); // 初始化 PIT 的通道 0，设置为方波发生器模式，并准备好接受接下来的频率除数值，该除数值会通过两次 outb 调用分别发送低字节和高字节到 PIT 通道 0 的数据端口（0x40）。
	outb((uint8_t)tmo, 0x40); // 设置 8253 时钟频率
	outb(tmo >> 8 , 0x40); // 由于outb每次只能发送8位数据，所以高8位和低8位要分开写入



	IDT_TABLE[0x20].offset_l = (uint32_t)timer_init  & 0xFFFF;
	IDT_TABLE[0x20].offset_h = (uint32_t)timer_init  >> 16;
	IDT_TABLE[0x20].selector = KERNEL_CODE_SEG;
	IDT_TABLE[0x20].attr = 0x8e00; // 设置中断门 设置为32位



	page_dir[MAP_ADDR >> 22] = (uint32_t) page_table | PDE_P | PDE_W | PDE_U ;
	page_table[MAP_ADDR >> 12 & 0x3ff]  = (uint32_t) map_phy_buffer | PDE_P | PDE_W | PDE_U ; // 0x3ff 取低10位
}