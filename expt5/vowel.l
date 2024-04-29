%{
#include<stdio.h>
int vow=0,cons=0;
%}
%%
[aeiou] {vow++;}
[a-zA-Z] {cons++;}
%%
int yywrap() {
  return 1;
}
int main() {
  printf("Enter a string\n");
  yylex();
  printf("Vowels:-%d\n",vow);
  printf("Cons:-%d\n",cons);
  return 0;
}