#include<stdio.h>
int getByte(int x, int n) {
  return (x >> (n << 3)) & 0xFF;
}
int main(int argc, char const *argv[])
{
    printf("%x\n",getByte(0x12345678,1));
    return 0;
}
