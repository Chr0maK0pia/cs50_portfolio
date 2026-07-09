#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    FILE *src = fopen(argv[1], "rb");
    //opens a file from the first cla and read it in binary data
    FILE *dst = fopen(argv[2], "wb");
    //opens a file from the second cla and writes it in binary

    BYTE b;
    //basically saying that while their is at least a byte left to be read in file src write it to dst.
    while(fread(&b, sizeof(b), 1 , src) != 0)
    {

        fwrite(&b, sizeof(b), 1, dst);

    }

    fclose(dst);
    fclose(src);
    

}