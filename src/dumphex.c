#include "dumphex.h"
#include "printf.h"

void DumpHex(const void *data, uint32_t size)
{
    char ascii[17];
    uint32_t i, j;
    ascii[16] = '\0';

    for (i = 0; i < size; ++i)
    {
        if (i % 16 == 0) {
            printf("0x%08X | ", (int)data + i);
        }

        printf("%02X ", ((unsigned char *)data)[i]);
        if (((unsigned char *)data)[i] >= ' ' && ((unsigned char *)data)[i] <= '~')
        {
            ascii[i % 16] = ((unsigned char *)data)[i];
        }
        else
        {
            ascii[i % 16] = '.';
        }
        if ((i + 1) % 8 == 0 || i + 1 == size)
        {
            printf(" ");
            if ((i + 1) % 16 == 0)
            {
                printf("|  %s \r\n", ascii);
            }
            else if (i + 1 == size)
            {
                ascii[(i + 1) % 16] = '\0';
                if ((i + 1) % 16 <= 8)
                {
                    printf(" ");
                }
                for (j = (i + 1) % 16; j < 16; ++j)
                {
                    printf("   ");
                }
                printf("|  %s \r\n", ascii);
            }
        }
    }
}