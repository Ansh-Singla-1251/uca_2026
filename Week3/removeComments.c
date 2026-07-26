#include <stdio.h>
int main(){
  int ch, next;
  int inString = 0, inChar = 0;
  while((ch = getchar()) != EOF){
    if(inString){
      putchar(ch);
      if(ch == '\\'){          
        if((next = getchar()) != EOF)
          putchar(next);
        }
      else if(ch == '"'){
        inString = 0;
      }
      continue;
    }
    if(inChar){
      putchar(ch);
      if (ch == '\\') {
        if ((next = getchar()) != EOF)
          putchar(next);
      }
      else if(ch == '\''){
        inChar = 0;
      }
      continue;
    }
    if(ch == '"'){
      inString = 1;
      putchar(ch);
      continue;
    }
    if(ch == '\''){
      inChar = 1;
      putchar(ch);
      continue;
    }
    if(ch == '/'){
      next = getchar();
      if(next == '/'){
        while((ch = getchar()) != EOF && ch != '\n');
          if(ch == '\n')
            putchar('\n');
      }
      else if(next == '*'){
        int prev = 0;
        while((ch = getchar()) != EOF){
          if(prev == '*' && ch == '/')
            break;
          prev = ch;
        }
      }
      else{
        putchar(ch);
        if(next != EOF)
          putchar(next);
      }
    }
    else{
      putchar(ch);
    }
  }
  return 0;
}