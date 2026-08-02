#include<stdio.h>
int sign(int x) {
    return (x >> 31) | (!!x);
}
int main(int argc, char const *argv[])
{
    printf("%d\n",sign(-4));
    printf("%d\n",sign(0));
    printf("%d\n",sign(4));
    return 0;
}
