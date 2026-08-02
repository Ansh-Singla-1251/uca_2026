#include<stdio.h>
int conditional(int x, int y, int z) {
    int mask = ~(!x) + 1;  
    return (~mask & y) | (mask & z);
}
int main(int argc, char const *argv[])
{
  printf("%d\n", conditional(2, 4, 5));  // 4
  printf("%d\n", conditional(0, 4, 5));  // 5

  return 0;
}
