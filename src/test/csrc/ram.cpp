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
        // logg(DEBUG, "read ram: 0x%016lx\n", addr);
        if(addr == 0) return 0;
        MEM_ASSERT(addr);
        return ram[(addr - START_ADDR)/sizeof(wlen_t)];
    }
    return 0;
}

void ram_c::Memwrite(wlen_t addr, wlen_t data, bool wen, mask_t mask){
    if(wen){
        logg(DEBUG, "write ram: 0x%016lx, mask: %x\n", addr, mask);
        MEM_ASSERT(addr);
        wlen_t bitmask = 0;
        for(int i=0; i<8; i++){
            if(mask & (0x1 << i)){
                bitmask |= (wlen_t)(0xFF) << (8*i);
            }
        }
        ram[(addr - START_ADDR)/sizeof(wlen_t)] &= ~bitmask;
        ram[(addr - START_ADDR)/sizeof(wlen_t)] |= (data & bitmask);
    }
}
