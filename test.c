#include <stdio.h>

int main(void)
{
    unsigned char floatArray[4] = {0x00, 0x00, 0x00, 0x40};
    float ret = *((float *)floatArray);
    printf("%f\n", ret);
}
