#include<stdio.h>
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}
int main(int argc, char const *argv[])
{
    int a=bitAnd(2,3);
    printf("%d\n",a);
    return 0;
}
