%{
#include<stdio.h>
int posInt = 0,negInt = 0,posFloat = 0,negFloat = 0;
%}
%%
[+]?[0-9]+ {posInt++;}
[-][0-9]+ {negInt++;}
[+]?[0-9]*\.[0-9]+ {posFloat++;}
[-]+[0-9]*\.[0-9]+ {negFloat++;}
%%
int yywrap() {
  return 1;
}
int main() {
  printf("Enter a number\n");
  yylex();
  printf("Postive Int: %d\nNegative Int: %d\nPostive Float: %d\nNegative Float: %d\n",posInt,negInt,posFloat,negFloat);
}