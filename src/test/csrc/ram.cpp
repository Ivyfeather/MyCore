#include "ram.h"
#include <stdio.h>
#include <assert.h>

#define MEM_ASSERT(addr) assert(START_ADDR <= addr && addr <= START_ADDR + RAMSIZE/sizeof(wlen_t)\
                                    && "addr out of range")


ram_c::ram_c(char *img_path){
    assert(img_path);
    FILE *fp = fopen(img_path, "rb");
    assert(fp);

    fseek(fp, 0, SEEK_END);
    img_size = ftell(fp);

    fseek(fp, 0, SEEK_SET);
    int ret = fread(ram, img_size, 1, fp);
    assert(ret == 1);
    fclose(fp);
}

void *ram_c::get_img_start() { return &ram[0]; }
long ram_c::get_img_size() { return img_size; }

wlen_t ram_c::Memread(wlen_t addr, bool en){
    if(en){
        //printf("[TEST] readmem: 0x%016lx\n", addr);
        MEM_ASSERT(addr);
        return ram[(addr - START_ADDR)/sizeof(wlen_t)];
    }
    return 0;
}

void ram_c::Memwrite(wlen_t addr, wlen_t data, bool wen, mask_t mask){
    if(wen){
        MEM_ASSERT(addr);
        //[TODO] implement bit mask later
        ram[(addr - START_ADDR)/sizeof(wlen_t)] = data;
    }
}
