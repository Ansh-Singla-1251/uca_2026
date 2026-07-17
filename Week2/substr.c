#include<stdio.h>
int find_substring(const char *haystack, const char *needle){
    for(int i=0;haystack[i]!='\0';i++){
        int j=0;
        while(needle[j]!='\0' && haystack[i+j]!='\0' && needle[j]==haystack[i+j]){
            j++;
        }
        if(needle[j]=='\0'){
            return j-1;
        }
    }
    return -1;
}
int main(){
    char haystack[] = "Embedded Systems";
    char needle[] = "bed";
    printf("%d\n",find_substring(haystack,needle));
}