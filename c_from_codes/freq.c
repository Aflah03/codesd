#include <stdio.h>
#include <string.h>

int main(){
  int hash[26];
  char line[100];
  printf("Enter the line: ");
  fgets(line,100,stdin);
  // line[strspn(line, "\n")]='\0';
  printf("the line is : %s",line); 
}
