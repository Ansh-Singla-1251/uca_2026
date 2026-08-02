#include<stdio.h>
int fitsBits(int x, int n) {
  int shift = 32 + (~n + 1);   // 32 - n
  return !(((x << shift) >> shift) ^ x);
}
int main(int argc, char const *argv[])
{
  printf("%d\n",fitsBits(-4,3));
  printf("%d",fitsBits(5,3));
  return 0;
}
