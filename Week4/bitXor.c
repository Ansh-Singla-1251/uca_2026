#include<stdio.h>
int bitXor(int x, int y) {
    return ~(~x & ~y) & ~(x & y);
}
int main(int argc, char const *argv[])
{
    int a=bitXor(2,3);
    printf("%d\n",a);
    return 0;
}
