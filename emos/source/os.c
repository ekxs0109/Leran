
#include "os.h"

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

struct
{
	uint16_t limit_l;			 // 段界限
	uint16_t base_l;			 // 基址
	uint16_t base_hl_attr; // 基址高4位+属性
	uint16_t base_limit;	 // 基址+段界限
} GDT_TABLE[256] __attribute__((aligned(8))) = {
		[KERNEL_CODE_SEG / 8] = {0xffff, 0x0000, 0x9a00, 0x00cf}, // 第0个段 0xffff 4GB
		[KERNEL_DATA_SEG / 8] = {0xffff, 0x0000, 0x9200, 0x00cf}, // 第1个段
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


void os_init(void)
{
	page_dir[MAP_ADDR >> 22] = (uint32_t) page_table | PDE_P | PDE_W | PDE_U ;
	page_table[MAP_ADDR >> 12 & 0x3ff]  = (uint32_t) map_phy_buffer | PDE_P | PDE_W | PDE_U ; // 0x3ff 取低10位
}