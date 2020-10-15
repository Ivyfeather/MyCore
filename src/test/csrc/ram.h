#ifndef __RAM_H__
#define __RAM_H__

#include "common.h"

#define RAMSIZE (128 * 1024 * 1024)

class ram_c{
public:
    ram_c(char* imgPath);
    void *get_img_start();
    long get_img_size();

    wlen_t Memread(wlen_t addr, bool en);
    void Memwrite(wlen_t addr, wlen_t data, bool wen, mask_t mask);

private:
    long img_size;
    wlen_t ram[RAMSIZE / sizeof(wlen_t)];

};

#endif