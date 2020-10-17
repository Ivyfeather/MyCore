#include<stdio.h>
int main(){
	FILE *fp = fopen("ram_test", "wb");
	unsigned int nop = 0x4033;
	int i;
	for(i=0;i<100;i++)
		fwrite((const void*)&nop, sizeof(unsigned int), 1, fp);
	return 0;
}
