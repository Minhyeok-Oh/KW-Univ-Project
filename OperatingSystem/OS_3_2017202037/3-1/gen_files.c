#include <stdio.h>

#define MAX_PROCESSES 20

int main(void){
    FILE *f_write = fopen("./temp.txt","wt"); // file open with wt(erase and write) mode 

    for(int i=0; i<MAX_PROCESSES*2; i++){
        fprintf(f_write, "%d\n", 2+rand()%100);
    }

    fclose(f_write);
}