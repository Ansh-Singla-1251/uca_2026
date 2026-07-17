#include<stdio.h>
#include<string.h>
void reverse_string(char *str){
int n=strlen(str);
    for(int i=0;i<n/2;i++){
        char x=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=x;
    }
}
int main(){
    char str[]="Data Structures";
    reverse_string(str);
    printf("%s\n",str);
}