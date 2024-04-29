%{
#include<stdio.h>
int newLines = 0, spaces = 0, words = 0;  
%}
%%
[\n]+ {newLines++;}
[ ]+ {spaces++;}
[a-zA-Z]{2,} {words++;}
%%
int yywrap() {
  return 1;
}
int main() {
  yyin = fopen("input.txt","r");
  yylex();
  printf("\nNo. of words: %d",words);
  printf("\nNo. of new line: %d",newLines);
  printf("\nNo. of spaces: %d\n",spaces);
}