#include "common.h"
#include "difftest.h"

#define RAMSIZE (128 * 1024 * 1024)

class ram_c{
public:
    ram_c(char* imgPath);
    void *get_img_start();
    Long get_img_size();

    wlen_t Memread(wlen_t addr, bool en);
    void Memwrite(wlen_t addr, wlen_t data, bool wen, mask_t mask);

private:
    Long img_size;
    wlen_t ram[RAMSIZE / sizeof(wlen_t)];

}
