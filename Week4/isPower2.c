#include<stdio.h>
int isPower2(int x){
  int positive = !(x >> 31);
  int nonzero = !!x;
  int singleBit = !(x & (x + ~0));
  return positive & nonzero & singleBit;
}
int main(int argc, char const *argv[]){
  printf("%d\n",isPower2(5));
  return 0;
}
